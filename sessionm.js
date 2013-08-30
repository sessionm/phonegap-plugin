// SessionM Phonegap Plugin 

(function(cordova) {

  function SessionM() {};
 
  SessionM.prototype.startSession = function(appId, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'startSession', [appId]);
  };

  SessionM.prototype.logAction = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'logAction', [event]);
  };
 
  SessionM.prototype.presentActivity = function(activityType, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'presentActivity', [activityType]);
  };
 
  SessionM.prototype.dismissActivity = function(successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'dismissActivity', []);
  };
 
  SessionM.prototype.setMetaData = function(data, key, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setMetaData', [data,key]);
  };

  SessionM.prototype.setAutoPresentMode = function(autoPresentMode, callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setAutoPresentMode', [autoPresentMode]);
  };
 
  SessionM.prototype.getUnclaimedAchievementCount = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getUnclaimedAchievementCount', []);
  };
 
  SessionM.prototype.getUnclaimedAchievementValue = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getUnclaimedAchievementValue', []);
  };
 
  SessionM.prototype.getOptedOutState = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'getOptedOutState', []);
  };
 
  SessionM.prototype.listenUnclaimedAchievement = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUnclaimedAchievementCallback', []);
  };
 
  SessionM.prototype.listenUpdateUser = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUpdateUserCallback', []);
  };
 
  SessionM.prototype.listenStateTransitions = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setStateTransitionCallback', []);
  };

  SessionM.prototype.listenFailures = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setFailureCallback', []);
  };
 
  SessionM.prototype.listentActivityUnavailable = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setActivityUnavailableCallback', []);
  };

  SessionM.prototype.listentWillPresentActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillPresentActivityCallback', []);
  };

  SessionM.prototype.listenDidPresentActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidPresentActivityCallback', []);
  };

  SessionM.prototype.listenWillDismissActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillDissmissActivityCallback', []);
  };

  SessionM.prototype.listentDidDismissActivity = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidDissmissActivityCallback', []);
  };

  SessionM.prototype.listenWillStartPlayingMedia = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setWillStartPlayingMediaForActivityCallback', []);
  };

  SessionM.prototype.listenDidFinishPlayingMedia = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setDidFinishPlayingMediaForActivityCallback', []);
  };

  SessionM.prototype.listenUserActions = function(callback) {
    return cordova.exec(callback, null, 'SessionMPlugin', 'setUserActionCallback', []);
  };
  
  SessionM.prototype.notifyCustomAchievementPresented = function(event, successCallback, failureCallback) {
      return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementPresented', [event]);
  };

  SessionM.prototype.notifyCustomAchievementDismissed = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementCancelled', [event]);
  };

  SessionM.prototype.notifyCustomAchievementClaimed = function(event, successCallback, failureCallback) {
    return cordova.exec(successCallback, failureCallback, 'SessionMPlugin', 'notifyCustomAchievementClaimed', [event]);
  };

  SessionM.install = function() {
    if (!window.plugins) {
      window.plugins = {};
    }
    window.plugins.sessionm = new SessionM();
    return window.plugins.sessionm;
  };

  cordova.addConstructor(SessionM.install);

})(window.cordova || window.Cordova || window.PhoneGap);
