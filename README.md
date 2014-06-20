SessionM PhoneGap SDK
===============
This plugin allows you to add SessionM achievements to your phonegap app for iOS and Android.

Compatibility: Cordova (PhoneGap) v3.5 or above

Setup Steps
---------------

### iOS Setup
1. Go to http://developer.sessionm.com and setup an account.
2. Create an iOS app and get the key.
3. Download the SDK and add it to your phone gap project.
4. Install the SessionM Plugin

   ```bash
   cordova plugin add https://github.com/sessionm/phonegap-plugin
   ```
    
   ```bash
    cordova prepare
    ```
5. Add the following to your root level config.xml allow access to the following URL:

    ```xml
    <access origin="https://*.sessionm.com" />
    ```
    ```
6. Start a session:

    ```javascript
    sessionm.phonegap.startSession('your-key-from-above-here');
    ```
7. To log an action call:

   ```javascript
   sessionm.phonegap.logAction('myAction');
   ```
8. To present the portal call:

   ```javascript
   sessionm.phonegap.presentActivity(2);
   ```

### Android Setup
### Installation
1. Go to http://developer.sessionm.com and setup an account.
2. Create an Android app and get the key.
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
4. Download the sessionM SDK and add it to your phone gap project.
5. Install the SessionM Plugin
    
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
    sessionm.phonegap.presentActivity(2);
    ```

