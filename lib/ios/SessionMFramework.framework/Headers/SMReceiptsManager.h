//
//  SMReceiptsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_RECEIPTS_MANAGER__
#define __SM_RECEIPTS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMReceipt.h"

/*!
 @const SM_RECEIPTS_MANAGER_UPLOAD_PROGRESS_NOTIFICATION
 @abstract Notifies observers that an image was successfully uploaded.
 @discussion An @link SMReceipt @/link object representing the current receipt data can be accessed from the notification's <code>userInfo</code> property with the @link SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_UPLOAD_PROGRESS_NOTIFICATION;
/*!
 @const SM_RECEIPTS_MANAGER_DID_UPLOAD_RECEIPT_NOTIFICATION
 @abstract Notifies observers that all receipt images were successfully uploaded.
 @discussion An @link SMReceipt @/link object representing the final receipt data can be accessed from the notification's <code>userInfo</code> property with the @link SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_DID_UPLOAD_RECEIPT_NOTIFICATION;
/*!
 @const SM_RECEIPTS_MANAGER_DID_FETCH_RECEIPTS_NOTIFICATION
 @abstract Notifies observers that the current user's uploaded receipts were fetched.
 @discussion An <code>NSArray</code> object representing the uploaded receipts can be accessed from the notification's <code>userInfo</code> property with the @link SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_DID_FETCH_RECEIPTS_NOTIFICATION;
/*!
 @const SM_RECEIPTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY
 @abstract Used to access relevant data from a notification's <code>userInfo</code> property.
 */
extern NSString *const SM_RECEIPTS_MANAGER_NOTIFICATION_DATA_KEY;


/*!
 @protocol SMReceiptsDelegate
 @abstract Defines callbacks for @link SMReceiptsManager @/link methods.
 */
@protocol SMReceiptsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that an image was successfully uploaded.
 @discussion This method is called in response to @link uploadReceiptImages:withCampaignID:placementID:data: @/link, @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link, and @link resumeIncompleteUploadForGroupID: @/link - once for each image upload.
 @param receipt The current receipt data.
 */
- (void)uploadProgress:(SMReceipt *)receipt;
/*!
 @abstract Notifies delegate that all receipt images were successfully uploaded.
 @discussion This method is called in response to @link uploadReceiptImages:withCampaignID:placementID:data: @/link, @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link, and @link resumeIncompleteUploadForGroupID: @/link after all images have been uploaded.
 @param receipt The final receipt data.
 */
- (void)didUploadReceipt:(SMReceipt *)receipt;
/*!
 @abstract Notifies delegate that the current user's uploaded receipts were fetched.
 @discussion This method is called in response to @link fetchReceipts @/link and @link fetchReceiptsWithLimit:page: @/link.
 @param receipts The uploaded receipts.
 */
- (void)didFetchReceipts:(NSArray<SMReceipt *> *)receipts;

@end


/*!
 @class SMReceiptsManager
 @abstract This API manager contains methods for uploading receipt images and fetching uploaded receipt data.
 */
@interface SMReceiptsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMReceiptsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMReceiptsDelegate> delegate;
/*!
 @property receipts
 @abstract The current user's uploaded receipts.
 @discussion This property is updated in response to a successful @link fetchReceipts @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReceipt *> *receipts;

/*!
 @abstract Identifiers for the current user's incomplete receipt uploads.
 @discussion An element of the array can be used as input for @link resumeIncompleteUploadForGroupID: @/link or @link removeIncompleteUploadForGroupID: @/link.  Default is to remove any other user's receipt uploads
 */
-(NSArray<NSString *> *)incompleteUploadGroupIDs;

/*!
 @abstract Identifiers for the current user's incomplete receipt uploads.
 @discussion An element of the array can be used as input for @link resumeIncompleteUploadForGroupID: @/link or @link removeIncompleteUploadForGroupID: @/link.
 @param keepOtherUsers flag to indicate if other user's receipts should be kept.
 @return List of GroupIDs for the current user.
 */
-(NSArray<NSString *> *)incompleteUploadGroupIDsAndKeepOtherUsers:(BOOL)keepOtherUsers;

/*!
 @abstract Uploads the receipt images with the specified asset identifiers for the specified campaign.
 @discussion @link uploadProgress: @/link and @link didUploadReceipt: @/link are called in response to this method.
 @param assetIDs Array of <code>PHObject</code> <code>localIdentifier</code> strings.
 @param campaignID ID of promotional campaign for which receipt is being uploaded.
 @param placementID ID of receipt placement (optional).
 @param data Custom, developer-defined data associated with the receipt (optional).
 */
- (NSString *)uploadReceiptImages:(NSArray <NSString *> *)assetIDs withCampaignID:(NSString *)campaignID placementID:(NSString *)placementID data:(NSDictionary *)data;
/*!
 @abstract Uploads the receipt images with the specified file paths for the specified campaign.
 @discussion @link uploadProgress: @/link and @link didUploadReceipt: @/link are called in response to this method.
 @param paths Array of image file paths.
 @param campaignID ID of promotional campaign for which receipt is being uploaded.
 @param placementID ID of receipt placement (optional).
 @param data Custom, developer-defined data associated with the receipt (optional).
 */
- (NSString *)uploadReceiptImageFiles:(NSArray <NSString *> *)paths withCampaignID:(NSString *)campaignID placementID:(NSString *)placementID data:(NSDictionary *)data;

/*!
 @abstract Resumes the incomplete receipt upload with the specified group ID.
 @discussion @link uploadProgress: @/link and @link didUploadReceipt: @/link are called in response to this method.
 @param groupID ID of receipt upload that will be resumed.
 */
- (void)resumeIncompleteUploadForGroupID:(NSString *)groupID;
/*!
 @abstract Removes all incomplete receipt uploads from storage.
 @discussion All group IDs are removed from @link incompleteUploadGroupIDs @/link on success.
 */
- (void)removeAllIncompleteUploads;
/*!
 @abstract Removes the incomplete receipt upload with the specified group ID from storage.
 @discussion Group ID is removed from @link incompleteUploadGroupIDs @/link on success.
 @param groupID ID of receipt upload that will be removed.
 */
- (void)removeIncompleteUploadForGroupID:(NSString *)groupID;

/*!
 @abstract Makes a request to update @link receipts @/link with the current user's uploaded receipts.
 @discussion @link didFetchReceipts: @/link is called in response to this method.
 */
- (void)fetchReceipts;
/*!
 @abstract Makes a request to update @link receipts @/link with a limited number of the current user's uploaded receipts.
 @param limit The maximum amount of receipts to fetch (optional).
 @param page <code>limit * (page-1)</code> most recent receipt records will be skipped for the fetch (optional).
 @discussion @link didFetchReceipts: @/link is called in response to this method.
 */
- (void)fetchReceiptsWithLimit:(int)limit page:(int)page;

@end

#endif /* SM_RECEIPTS_MANAGER */
