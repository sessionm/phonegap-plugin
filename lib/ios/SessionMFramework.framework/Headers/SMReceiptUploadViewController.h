//
//  SMReceiptUploadViewController.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_RECEIPT_UPLOAD_VIEW_CONTROLLER__
#define __SM_RECEIPT_UPLOAD_VIEW_CONTROLLER__

#import <UIKit/UIKit.h>

/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_CAMPAIGN_ID_KEY
 @abstract Sets the <code>campaignID</code> parameter of @link //apple_ref/occ/instm/SMReceiptsManager/uploadReceiptImages:withCampaignID:placementID:data: @/link or @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link when a receipt is uploaded.
 @discussion This key can be used in the <code>attributes</code> parameter of @link initWithAttributes: @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_CAMPAIGN_ID_KEY;
/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_PLACEMENT_ID_KEY
 @abstract Sets the <code>placementID</code> parameter of @link //apple_ref/occ/instm/SMReceiptsManager/uploadReceiptImages:withCampaignID:placementID:data: @/link or @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link when a receipt is uploaded.
 @discussion This key can be used in the <code>attributes</code> parameter of @link initWithAttributes: @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_PLACEMENT_ID_KEY;
/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_DATA_KEY
 @abstract Sets the <code>data</code> parameter of @link //apple_ref/occ/instm/SMReceiptsManager/uploadReceiptImages:withCampaignID:placementID:data: @/link or @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link when a receipt is uploaded.
 @discussion This key can be used in the <code>attributes</code> parameter of @link initWithAttributes: @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_DATA_KEY;
/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_KEY
 @abstract Determines whether @link //apple_ref/occ/instm/SMReceiptsManager/uploadReceiptImages:withCampaignID:placementID:data: @/link or @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link is called to upload a receipt.
 @discussion This key can be used in the <code>attributes</code> parameter of @link initWithAttributes: @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_KEY;
/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_FILES
 @abstract Selects @link uploadReceiptImageFiles:withCampaignID:placementID:data: @/link to be called to upload a receipt.
 @discussion This key can be used as the value of @link SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_KEY @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_FILES;
/*!
 @const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_ASSETS
 @abstract Selects @link uploadReceiptImages:withCampaignID:placementID:data: @/link to be called to upload a receipt.
 @discussion This key can be used as the value of @link SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_KEY @/link.
 */
extern NSString *const SM_RECEIPT_UPLOAD_ATTRIBUTE_UPLOAD_TYPE_ASSETS;


/*!
 @class SMReceiptUploadViewController
 @abstract View controller for receipt upload activity.
 @discussion An instance of this class is created and presented by the SDK when the user is asked to upload a receipt image for particular ads. The developer can optionally create an instance using the @link initWithAttributes: @/link method to upload receipt images without going through the ad flow.
 */
@interface SMReceiptUploadViewController : UIViewController

/*!
 @abstract Creates and returns a new instance of <code>SMReceiptUploadViewController</code> with the specified attributes.
 @param attributes Metadata the user should enter when uploading a receipt.
 @result An instance of <code>SMReceiptUploadViewController</code> with the specified attributes.
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;
/*!
 @abstract Sets the color scheme of the view controller.
 @discussion This method should be called before an instance of <code>SMReceiptUploadViewController</code> is presented. A value of <code>nil</code> can be specified to keep the current color for a parameter.
 @param bgColor Background color (default is white).
 @param titleColor Title text color (default is black).
 @param descriptionColor Non-title text color (default is black).
 @param systemButtonColor System button color (default is system tint color).
 @param actionButtonColor Action button color (default is blue).
 @param actionButtonTitleColor Action button text color (default is white).
 */
+ (void)setBackgroundColor:(UIColor *)bgColor
                titleColor:(UIColor *)titleColor
          descriptionColor:(UIColor *)descriptionColor
         systemButtonColor:(UIColor *)systemButtonColor
         actionButtonColor:(UIColor *)actionButtonColor
    actionButtonTitleColor:(UIColor *)actionButtonTitleColor;

@end

#endif /* __SM_RECEIPT_UPLOAD_VIEW_CONTROLLER__ */
