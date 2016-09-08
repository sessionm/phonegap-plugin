cordova.define("sessionm-cordova-plugin.sessionm", function(require, exports, module) {
// SessionM Phonegap Plugin 

  function SessionMPlugin(){
 
  SessionMPlugin.prototype.startSession = function(appId, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'startSession', [appId]);
  };

  SessionMPlugin.prototype.startCustomSession = function(serverURL, appID, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'startCustomSession', [serverURL, appID]);
  };

  SessionMPlugin.prototype.logAction = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'logAction', [event]);
  };
 
  SessionMPlugin.prototype.presentActivity = function(activityType, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'presentActivity', [activityType]);
  };
 
  SessionMPlugin.prototype.dismissActivity = function(successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'dismissActivity', []);
  };
 
  SessionMPlugin.prototype.setMetaData = function(data, key, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setMetaData', [data,key]);
  };

  SessionMPlugin.prototype.setAutoPresentMode = function(autoPresentMode, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setAutoPresentMode', [autoPresentMode]);
  };
 
  SessionMPlugin.prototype.getUnclaimedAchievementCount = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getUnclaimedAchievementCount', []);
  };
 
  SessionMPlugin.prototype.getUnclaimedAchievementValue = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getUnclaimedAchievementValue', []);
  };
 
  SessionMPlugin.prototype.getOptedOutState = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getOptedOutState', []);
  };

  SessionMPlugin.prototype.logInUserWithEmail = function(email, password, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'logInUserWithEmail', [email, password]);
  };

  SessionMPlugin.prototype.signUpUserWithData = function(email, password, yearOfBirth, gender, zipcode, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'signUpUserWithData', [email, password, yearOfBirth, gender, zipcode]);
  };

  SessionMPlugin.prototype.logOutUser = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'logOutUser', []);
  };
 
  SessionMPlugin.prototype.listenUnclaimedAchievement = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUnclaimedAchievementCallback', []);
  };
 
  SessionMPlugin.prototype.listenUpdateUser = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUpdateUserCallback', []);
  };
 
  SessionMPlugin.prototype.listenStateTransitions = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setStateTransitionCallback', []);
  };

  SessionMPlugin.prototype.listenFailures = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setFailureCallback', []);
  };
 
  SessionMPlugin.prototype.listentActivityUnavailable = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setActivityUnavailableCallback', []);
  };

  SessionMPlugin.prototype.listentWillPresentActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillPresentActivityCallback', []);
  };

  SessionMPlugin.prototype.listenDidPresentActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidPresentActivityCallback', []);
  };

  SessionMPlugin.prototype.listenWillDismissActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillDismissActivityCallback', []);
  };

  SessionMPlugin.prototype.listenDidDismissActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidDismissActivityCallback', []);
  };

  SessionMPlugin.prototype.listenWillStartPlayingMedia = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillStartPlayingMediaForActivityCallback', []);
  };

  SessionMPlugin.prototype.listenDidFinishPlayingMedia = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidFinishPlayingMediaForActivityCallback', []);
  };

  SessionMPlugin.prototype.listenUserActions = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUserActionCallback', []);
  };
  
  SessionMPlugin.prototype.notifyCustomAchievementPresented = function(event, successCallback, failureCallback) {
      return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementPresented', [event]);
  };

  SessionMPlugin.prototype.notifyCustomAchievementDismissed = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementCancelled', [event]);
  };

  SessionMPlugin.prototype.notifyCustomAchievementClaimed = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementClaimed', [event]);
  };
}
module.exports = new SessionMPlugin();

});
