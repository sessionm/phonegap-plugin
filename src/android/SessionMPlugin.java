package com.sessionm.phonegap;

import java.util.HashMap;
import java.util.Map;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.util.Log;
import android.widget.FrameLayout;

import com.sessionm.api.AchievementActivity;
import com.sessionm.api.AchievementActivity.AchievementDismissType;
import com.sessionm.api.AchievementActivityIllegalStateException;
import com.sessionm.api.AchievementData;
import com.sessionm.api.ActivityListener;
import com.sessionm.api.SessionListener;
import com.sessionm.api.SessionM;
import com.sessionm.api.SessionM.ActivityType;
import com.sessionm.api.SessionM.State;
import com.sessionm.api.User;
import com.sessionm.api.message.notification.data.NotificationMessage;

public class SessionMPlugin extends CordovaPlugin implements SessionListener,
        ActivityListener {

    private static final String TAG = "SessionM.PhoneGap";
    private CallbackContext unclaimedAchievementCallback;
    private CallbackContext updateUserCallback;
    private CallbackContext stateTransitionCallback;
    private CallbackContext failureCallback;
    private CallbackContext activityUnavailableCallback;
    private CallbackContext didPresentActivityCallback;
    private CallbackContext didDismissActivityCallback;
    private CallbackContext userActionCallback;
    private AchievementActivity achievementActivity;
    private boolean autoPresentMode = true;
    private com.sessionm.api.SessionM sessionM;

    @Override
    public boolean execute(final String action, final JSONArray args,
                           final CallbackContext callbackContext) throws JSONException {
        cordova.getThreadPool().execute(new Runnable() {

            @Override
            public void run() {
                try {
                    executeInternal(action, args, callbackContext);
                } catch (JSONException e) {
                    if (Log.isLoggable(TAG, Log.ERROR)) {
                        Log.e(TAG, String.format("Error executing command: %s",
                                action), e);
                    }
                    callbackContext.error(e.getMessage());
                }
            }

        });
        return true;
    }

    private synchronized void executeInternal(String action, JSONArray args,
                                              final CallbackContext callbackContext) throws JSONException {
        if (action.equals("startSession")) {
            // Really this is a no-op
            // Doesn't actually start the session but will initialize the plugin
            // as a listener.
            if (sessionM == null) {
                sessionM = com.sessionm.api.SessionM.getInstance();
                sessionM.setApplicationContext(cordova.getActivity().getApplicationContext());
                sessionM.setActivityListener(this);
                sessionM.setSessionListener(this);
                sessionM.setExpandedPresentationMode(true);
                SessionM.getInstance().onActivityStart(cordova.getActivity());
                sessionM.setExpandedPresentationMode(false);
                callbackContext.success();
            } else {
                callbackContext.error("Already started!");
            }
        } else if (action.equals("startCustomSession")) {
            if (sessionM == null) {
                String serverURL = args.getString(0);
                String appID = args.getString(1);
                if (serverURL == null || serverURL.isEmpty()) {
                    callbackContext.error("Expected a valid server url.");
                    return;
                }
                if (appID == null || appID.isEmpty()) {
                    callbackContext.error("Expected a valid app key.");
                    return;
                }
                sessionM = com.sessionm.api.SessionM.getInstance();
                sessionM.setApplicationContext(cordova.getActivity().getApplicationContext());
                sessionM.setActivityListener(this);
                sessionM.setSessionListener(this);
                sessionM.setExpandedPresentationMode(true);
                sessionM.setServerType(SessionM.SERVER_TYPE_CUSTOM, serverURL);
                sessionM.setAppKey(appID);
                SessionM.getInstance().onActivityStart(cordova.getActivity());
                sessionM.setExpandedPresentationMode(false);
                callbackContext.success();
            } else {
                callbackContext.error("Already started!");
            }
        } else if (action.equals("logAction")) {
            if (args.length() == 1 && sessionM != null) {
                String actionToLog = args.getString(0);
                SessionM.getInstance().logAction(actionToLog);
                callbackContext.success();
            } else {
                callbackContext.error("Expected a single string argument.");
            }
        } else if (action.equals("presentActivity")) {
            if (args.length() == 1) {
                String presentType = args.getString(0);
                ActivityType selectedType = null;
                // Translate to enum type.
                if (presentType.equals("ACHIEVEMENT"))
                    selectedType = ActivityType.ACHIEVEMENT;
                else if (presentType.equals("PORTAL"))
                    selectedType = ActivityType.PORTAL;
                else if (presentType.equals("INTERSTITIAL"))
                    selectedType = ActivityType.INTERSTITIAL;
                if (selectedType != null
                        && SessionM.getInstance().getSessionState() != SessionM.State.STOPPED) {
                    SessionM.getInstance().presentActivity(selectedType);
                    callbackContext.success();
                } else {
                    callbackContext.error(String.format(
                            "Invalid present type: %s", presentType));
                }
            } else {
                callbackContext.error("Expected a single string argument.");
            }
        } else if (action.equals("dismissActivity") && sessionM != null) {
            sessionM.dismissActivity();
        } else if (action.equals("setMetaData")) {
            if (args.length() == 2 && sessionM != null) {
                String key = args.getString(0);
                String value = args.getString(1);
                sessionM.setMetaData(key, value);
                callbackContext.success();
            } else {
                callbackContext.error("Expected a key and a value argument.");
            }
        } else if (action.equals("setAutoPresentMode")) {
            if (args.length() == 1 && sessionM != null) {
                boolean autoPresentMode = args.getBoolean(0);
                sessionM.setAutopresentMode(autoPresentMode);
                callbackContext.success();
            } else {
                callbackContext.error("Expected a single boolean argument");
            }
        } else if (action.equals("getUnclaimedAchievementCount")
                && sessionM != null) {
            JSONObject ret = new JSONObject();
            ret.put("unclaimedAchievementCount", sessionM.getUser()
                    .getUnclaimedAchievementCount());
            callbackContext.success(ret);
        } else if (action.equals("getUnclaimedAchievementValue")
                && sessionM != null) {
            JSONObject ret = new JSONObject();
            ret.put("unclaimedAchievementValue", sessionM.getUser()
                    .getUnclaimedAchievementValue());
            callbackContext.success(ret);
        } else if (action.equals("getOptedOutState") && sessionM != null) {
            JSONObject ret = new JSONObject();
            ret.put("optedOut", sessionM.getUser().isOptedOut());
            callbackContext.success(ret);
        } else if (action.equals("logInUserWithEmail") && sessionM != null) {
            if (args.length() == 2 && sessionM != null) {
                String email = args.getString(0);
                String password = args.getString(1);
                sessionM.logInUserWithEmail(email, password);
                callbackContext.success();
            } else {
                callbackContext.error("Expected an email and password argument.");
            }
        } else if (action.equals("signUpUserWithData") && sessionM != null) {
            if (args.length() == 5 && sessionM != null) {
                String email = args.getString(0);
                String password = args.getString(1);
                String yearOfBirth = args.getString(2);
                String gender = args.getString(3);
                String zipcode = args.getString(4);
                Map<String, String> dataMap = new HashMap<String, String>();
                dataMap.put(SessionM.USER_DATA_EMAIL_KEY, email);
                dataMap.put(SessionM.USER_DATA_PASSWORD_KEY, password);
                dataMap.put(SessionM.USER_DATA_BIRTH_YEAR_KEY, yearOfBirth);
                dataMap.put(SessionM.USER_DATA_GENDER_KEY, gender);
                dataMap.put(SessionM.USER_DATA_ZIP_CODE_KEY, zipcode);
                sessionM.signUpUserWithData(dataMap);
                callbackContext.success();
            } else {
                callbackContext.error("Expected an hash map argument.");
            }
        } else if (action.equals("logOutUser") && sessionM != null) {
            sessionM.logOutUser();
            callbackContext.success();
        } else if (action.equals("setUnclaimedAchievementCallback")) {
            unclaimedAchievementCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setUpdateUserCallback")) {
            updateUserCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setStateTransitionCallback")) {
            stateTransitionCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setFailureCallback")) {
            failureCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setActivityUnavailableCallback")) {
            activityUnavailableCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setDidPresentActivityCallback")) {
            didPresentActivityCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setDidDismissActivityCallback")) {
            didDismissActivityCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("setUserActionCallback")) {
            userActionCallback = callbackContext;
            PluginResult res = new PluginResult(PluginResult.Status.NO_RESULT);
            res.setKeepCallback(true);
            callbackContext.sendPluginResult(res);
        } else if (action.equals("notifyCustomAchievementPresented")) {
            PluginResult res = null;
            if (achievementActivity == null) {
                res = new PluginResult(PluginResult.Status.INVALID_ACTION);
            } else {
                try {
                    achievementActivity.notifyPresented();
                    res = new PluginResult(PluginResult.Status.OK);
                } catch (AchievementActivityIllegalStateException e) {
                    if (Log.isLoggable(TAG, Log.ERROR)) {
                        Log.e(TAG, "Error presenting custom achievement.", e);
                    }
                    res = new PluginResult(PluginResult.Status.ERROR);
                }
            }
            callbackContext.sendPluginResult(res);

        } else if (action.equals("notifyCustomAchievementCancelled")) {
            PluginResult res = null;
            if (achievementActivity == null) {
                res = new PluginResult(PluginResult.Status.INVALID_ACTION);
            } else {
                try {
                    achievementActivity
                            .notifyDismissed(AchievementDismissType.CANCELLED);
                    res = new PluginResult(PluginResult.Status.OK);
                } catch (AchievementActivityIllegalStateException e) {
                    if (Log.isLoggable(TAG, Log.ERROR)) {
                        Log.e(TAG, "Error cancelling custom achievement.", e);
                    }
                    res = new PluginResult(PluginResult.Status.ERROR);
                }
            }
            callbackContext.sendPluginResult(res);
        } else if (action.equals("notifyCustomAchievementClaimed")) {
            PluginResult res = null;
            if (achievementActivity == null) {
                res = new PluginResult(PluginResult.Status.INVALID_ACTION);
            } else {
                try {
                    achievementActivity
                            .notifyDismissed(AchievementDismissType.CLAIMED);
                    res = new PluginResult(PluginResult.Status.OK);
                } catch (AchievementActivityIllegalStateException e) {
                    if (Log.isLoggable(TAG, Log.ERROR)) {
                        Log.e(TAG, "Error claiming custom achievement.", e);
                    }
                    res = new PluginResult(PluginResult.Status.ERROR);
                }
            }
            callbackContext.sendPluginResult(res);
        } else {
        }

    }

    /**
     * @Override public boolean shouldAutopresentActivity(SessionM instance) {
     * return autoPresentMode; }
     */
    // true for now
    @Override
    public boolean shouldPresentAchievement(SessionM instance,
                                            AchievementData data) {
        return true;
    }

    @Override
    public FrameLayout viewGroupForActivity() {
        return null;
    }

    // SessionListener
    @Override
    public void onSessionFailed(SessionM instance, int errorCode) {
        if (failureCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, String.format(
                    "onSessionFailed called with errorCode: %d", errorCode));
        }

        PluginResult result = new PluginResult(PluginResult.Status.OK,
                errorCode);
        result.setKeepCallback(true);
        failureCallback.sendPluginResult(result);
    }

    @Override
    public void onSessionStateChanged(SessionM instance, State state) {
        if (stateTransitionCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, String.format(
                    "onSessionStateChanged called with state: %s", state));
        }

        PluginResult result = new PluginResult(PluginResult.Status.OK,
                state.toString());
        result.setKeepCallback(true);
        stateTransitionCallback.sendPluginResult(result);
    }

    @Override
    public void onUnclaimedAchievement(SessionM instance, AchievementData achievement) {
        if (unclaimedAchievementCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, String.format("onUnclaimedAchievement called state: %s", achievement));
        }
        achievementActivity = new AchievementActivity(achievement);
        JSONObject achievementJSON = new JSONObject();
        try {
            achievementJSON.put("iconURL", achievement.getAchievementIconURL());
            achievementJSON.put("name", achievement.getName());
            achievementJSON.put("points", achievement.getMpointValue());
            achievementJSON.put("isCustom", achievement.isCustom());
            achievementJSON.put("action", achievement.getName());
            achievementJSON.put("message", achievement.getMessage());
        } catch (JSONException e) {
            if (Log.isLoggable(TAG, Log.ERROR)) {
                Log.e(TAG, String.format("Error creating achievement JSON. ", e));
            }
            return;
        }

        PluginResult result = new PluginResult(PluginResult.Status.OK, achievementJSON);
        result.setKeepCallback(true);
        unclaimedAchievementCallback.sendPluginResult(result);
    }

    @Override
    public void onUserUpdated(SessionM instance, User user) {
        if (updateUserCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, String.format("onUserUpdated called with user: %s", user));
        }

        JSONObject userJSON = new JSONObject();
        //Call error callback if enrollment failed
        if (instance.getEnrollmentResult().equals(SessionM.EnrollmentResultType.FAILURE)) {
            try {
                userJSON.put("errorMessage", sessionM.getResponseErrorMessage());
            } catch (JSONException e) {
                e.printStackTrace();
            }
            PluginResult result = new PluginResult(PluginResult.Status.OK, userJSON);
            result.setKeepCallback(true);
            updateUserCallback.sendPluginResult(result);
            return;
        }

        try {
            userJSON.put("optedOut", user.isOptedOut());
            userJSON.put("unclaimedAchievementCount",
                    user.getUnclaimedAchievementCount());
            userJSON.put("unclaimedAchievementValue",
                    user.getUnclaimedAchievementValue());
            userJSON.put("pointBalance", user.getPointBalance());
        } catch (JSONException e) {
            if (Log.isLoggable(TAG, Log.ERROR)) {
                Log.e(TAG, String.format("Error creating user JSON. ", e));
            }
            return;
        }

        PluginResult result = new PluginResult(PluginResult.Status.OK, userJSON);
        result.setKeepCallback(true);
        updateUserCallback.sendPluginResult(result);
    }

    // ActivityListener
    @Override
    public void onDismissed(SessionM instance) {
        if (didDismissActivityCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, "onDismissed called");
        }
        PluginResult result = new PluginResult(PluginResult.Status.OK);
        result.setKeepCallback(true);
        didDismissActivityCallback.sendPluginResult(result);
    }

    @Override
    public void onPresented(SessionM instance) {
        if (didPresentActivityCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, "onPresented called");
        }
        PluginResult result = new PluginResult(PluginResult.Status.OK);
        result.setKeepCallback(true);
        didPresentActivityCallback.sendPluginResult(result);
    }

    /**
     * @Override public void onUnavailable(SessionM instance) { if
     * (activityUnavailableCallback == null) { return; } if
     * (Log.isLoggable(TAG, Log.DEBUG)) { Log.d(TAG,
     * "onUnavailable called"); }
     * <p/>
     * PluginResult result = new PluginResult(PluginResult.Status.OK);
     * result.setKeepCallback(true);
     * activityUnavailableCallback.sendPluginResult(result); }
     */

    @Override
    public void onUserAction(SessionM instance, UserAction action,
                             Map<String, String> data) {
        if (userActionCallback == null) {
            return;
        }
        if (Log.isLoggable(TAG, Log.DEBUG)) {
            Log.d(TAG, String.format(
                    "onUserAction called with action: %s data: %s", action,
                    data));
        }
        JSONObject userActionJSON = new JSONObject();
        try {
            for (String key : data.keySet()) {
                userActionJSON.put(key, data.get(key));
            }
            userActionJSON.put("_action", action);
        } catch (JSONException e) {
            if (Log.isLoggable(TAG, Log.ERROR)) {
                Log.e(TAG, String.format("Error creating user JSON. ", e));
            }
            return;
        }

        PluginResult result = new PluginResult(PluginResult.Status.OK,
                userActionJSON);
        result.setKeepCallback(true);
        userActionCallback.sendPluginResult(result);
    }

    @Override
    public void onResume(boolean foo) {
        super.onResume(foo);
        SessionM.getInstance().onActivityResume(cordova.getActivity());
    }

    @Override
    public void onPause(boolean foo) {
        super.onPause(foo);
        SessionM.getInstance().onActivityPause(cordova.getActivity());
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        SessionM.getInstance().onActivityStop(cordova.getActivity());
    }

}
