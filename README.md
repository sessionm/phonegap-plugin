SessionM PhoneGap SDK
===============
This plugin allows you to add SessionM achievements to your phonegap app for iOS and Android.

Setup Steps
---------------

### iOS Setup
1. Go to http://developer.sessionm.com and setup an account.
2. Create an iOS app and get the key.
3. Download the SDK and add it to your phone gap project.
4. Add the SessionMPhoneGapPlugin.h and SessionMPhoneGapPlugin.m to the plugin directory of your project.
5. Add the following to your root level config.xml:

```xml
<feature name="SessionMPlugin">
    <param name="ios-package" value="SessionMPhoneGapPlugin"/>
</feature>
<access origin="https://*.sessionm.com" /> 
```
6. Add a script tag to your index.html: 

```html
<script type="text/javascript" src="js/sessionm.js"></script>
```
7. Start a session:

```javascript
window.plugins.sessionm.startSession('your-key-from-above-here');
```
8. To log an action call:

```javascript
window.plugins.sessionm.logAction('myAction');
```
9. To present the portal call:

```javascript
window.plugins.sessionm.presentActivity(2);
```


### Android Setup

Coming Soon
