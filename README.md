SessionM Cordova (PhoneGap) SDK v1.0.0
===============
This plugin allows you to add SessionM achievements to your Cordova (PhoneGap) app for iOS and Android.

Compatibility: Cordova (PhoneGap) v3.5 or above

Setup Steps
---------------

### iOS Setup
### Installation
1. Go to [SessionM Dev Portal](http://developer.sessionm.com) and setup an account.
2. Create an iOS app and get the key.
3. Install the SessionM Plugin

   ```bash
   cordova plugin add https://github.com/sessionm/phonegap-plugin
   ```
    
   ```bash
    cordova prepare
    ```

You should be able to see SessionMFramework.framework in both "Linked Frameworks and Libraries" and "Embedded Binaries" in General tab.

Note: If you don't see SessionMFramework.framework in "Embedded Binaries", please manually add SessionMFramework.framework to "Embedded Binaries" in General tab.

###Usage
1. Add the following to your root level config.xml allow access to the following URL:

    ```xml
    <access origin="https://*.sessionm.com" />
    ```
2. Start a session:

    ```javascript
    sessionm.phonegap.startSession('your-key-from-above-here');
    ```
3. To log an action call:

   ```javascript
   sessionm.phonegap.logAction('myAction');
   ```
4. To present the portal call:

   ```javascript
   sessionm.phonegap.presentActivity('PORTAL');
   ```

### Android Setup
### Installation
1. Go to [SessionM Dev Portal](http://developer.sessionm.com) and setup an account.
2. Create an android app and get the key.
3. Add the key and permissions to AndroidManifest.xml.
   
   ```xml
   <uses-permission android:name="android.permission.INTERNET" />
   <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />

   ...
   
   <application>
   <meta-data
   	android:name="com.sessionm.appid"
   	android:value="your-key-from-above-here" />
   </application>
   ```
4. Install the SessionM Plugin
    
    ```bash
    cordova plugin add https://github.com/sessionm/phonegap-plugin
    ```
    ```bash
    cordova prepare
    ```

### Usage
1. To start a session, put the following javascript in index.js.

    ```javascript
    onDeviceReady: function() {
        app.receivedEvent('deviceready');
    	sessionm.phonegap.startSession('your-key-from-above-here');
    }
    ```

2. To log an action call:

    ```javascript
    sessionm.phonegap.logAction('myAction');
    ```

3. To present the portal call:

    ```javascript
    sessionm.phonegap.presentActivity('PORTAL');
    ```

4. To set up listeners in Android, call the proper method just below the startSession();. Like:

   ```javascript
   onDeviceReady: function() {
      app.receivedEvent('deviceready');
      sessionm.phonegap.startSession("382e91ef41df2e74ecd963fd04b68a186a6b41e0");
      sessionm.phonegap.listenDidPresentActivity(function(data) {console.log('mPlus Rewards Portal Presented.');});
      sessionm.phonegap.listenDidDismissActivity(function(data) {console.log('mPlus Rewards Portal Dismissed.');});
      sessionm.phonegap.listenFailures(function(data) {console.log('SessionM Failure!')});
      //Update html when user status updates
      sessionm.phonegap.listenUpdateUser(function(data) {
         app.updateUserText(data);
         app.updateBadgeCount(data);
      })
   	...
   },
   
   updateBadgeCount: function(data){
      var msg = '' + data.unclaimedAchievementCount;
      document.getElementById('badgeCount').innerHTML = msg;
   },

   updateUserText: function(data){
      //Get user total point balance
      document.getElementById('userBalance').innerHTML = 'User Balance: ' + data.pointBalance;
      //Get user unclaimed achievement count
      document.getElementById('unclaimedCount').innerHTML = 'Unclaimed Achievement Count: ' + data.unclaimedAchievementCount;
      //Get if user is opted out
      document.getElementById('isOptOut').innerHTML = 'User Opted Out: ' + data.optedOut;
   },
   ```
   In index.html, create a DIV or a Label Element like in the HTML example below.

   ```xml
   <body>
   ...
        
      <label id="userBalance">mPlus Rewards Value: --</label>
      <label id="unclaimedCount">mPlus Rewards Value: --</label>
      <label id="isOptOut">mPlus Rewards Value: --</label>
   
   ...
   </body>
   ```

