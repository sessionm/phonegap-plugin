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
    ```sh
    cordova plugin add <sessionm-phonegapPlugin-folder>
    OR
    cordova plugin add https://github.com/sessionm/phonegap-plugin
    cordova prepare
    ```
6. Add the following to your root level config.xml allow access to the following URL:

    ```xml
    <access origin="https://*.sessionm.com" />
    ```

7. Add a script tag to your index.html:

    ```html

    ```
8. Start a session:

    ```javascript
    sessionm.phonegap.startSession('your-key-from-above-here');
    ```
9. To log an action call:

    ```javascript
    sessionm.phonegap.logAction('myAction');
    ```
10. To present the portal call:

    ```javascript
    sessionm.phonegap.presentActivity(2);
    ```

### Android Setup

Coming Soon
