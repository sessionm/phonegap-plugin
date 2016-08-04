//
//  SMReceipt.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_RECEIPT__
#define __SM_RECEIPT__

#import <Foundation/Foundation.h>

/*!
 @typedef SMReceiptStatus
 @abstract Receipt upload status.
 */
typedef enum SMReceiptStatus {
    /*! Upload status is unknown */
    SMReceiptStatusUnknown,                              /* unknown */
    /*! Upload is pending review. */
    SMReceiptStatusPending,                              /* pending */
    /*! Upload was approved. */
    SMReceiptStatusValid,                                /* valid */
    /*! Upload was rejected. */
    SMReceiptStatusInvalid,                              /* invalid */
    /*! Multiple image upload is partially finished. */
    SMReceiptStatusIncomplete                            /* incomplete */
} SMReceiptStatus;


/*!
 @class SMReceiptResult
 @abstract Defines the purchase data for an item on a receipt.
 */
@interface SMReceiptResult : NSObject

/*!
 @property resultID
 @abstract Unique ID for result.
 @discussion This ID will be equal to //apple_ref/occ/instp/SMTranscation/recordModelID in the corresponding transaction record.
 */
@property(nonatomic, strong, readonly) NSString *resultID;
/*!
 @property name
 @abstract Item name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property descriptionText
 @abstract Item description.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property price
 @abstract Individual item price.
 */
@property(nonatomic, assign, readonly) float price;
/*!
 @property quantity
 @abstract Amount of item purchased.
 */
@property(nonatomic, assign, readonly) int quantity;
/*!
 @property points
 @abstract Amount of points user earned for uploading the receipt.
 */
@property(nonatomic, assign, readonly) int points;

@property(nonatomic, strong, readonly) NSDictionary *extras;

@end


/*!
 @class SMReceipt
 @abstract Defines the data associated with a receipt uploaded by the user.
 */
@interface SMReceipt : NSObject

/*!
 @property receiptID
 @abstract Unique ID for receipt.
 */
@property(nonatomic, strong, readonly) NSString *receiptID;
/*!
 @property campaignID
 @abstract ID of promotional campaign associated with the receipt.
 */
@property(nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property placementID
 @abstract ID of receipt placement.
 */
@property(nonatomic, strong, readonly) NSString *placementID;
/*!
 @property userID
 @abstract ID of user that uploaded the receipt images.
 */
@property(nonatomic, strong, readonly) NSString *userID;
/*!
 @property groupID
 @abstract ID used to identify partially-finished multiple image upload.
 */
@property(nonatomic, strong, readonly) NSString *groupID;
/*!
 @property invalidCode
 @abstract Error code for a rejected receipt upload.
 @discussion <ul>
    <li>0 Unknown</li>
    <li>1 Receipt cannot be read clearly</li>
    <li>2 Receipt is cropped</li>
    <li>3 Receipt submitted twice</li>
    <li>4 Receipt processing unavailable</li>
    <li>5 Image is not a receipt</li>
    <li>6 No valid purchases found</li>
    <li>7 Purchases are from a non-qualifying store</li>
    <li>8 Image cannot be read clearly</li>
    <li>9 Image is unrelated to campaign</li>
    <li>10 Image submitted twice</li>
    <li>11 Image processing unavailable</li>
    <li>12 Image has no valid purchases found, similar to 6</li>
    <li>13 Multiple submissions not allowed for this campaign</li>
 </ul>
 */
@property(nonatomic, assign, readonly) int invalidCode;
/*!
 @property invalidReason
 @abstract Explains why a receipt upload was rejected.
 */
@property(nonatomic, strong, readonly) NSString *invalidReason;
/*!
 @property imageCount
 @abstract Number of images uploaded for the receipt.
 */
@property(nonatomic, assign, readonly) int imageCount;
/*!
 @property imageURLs
 @abstract URLs of uploaded receipt images.
 */
@property(nonatomic, strong, readonly) NSArray<NSString *> *imageURLs;
/*!
 @property createdTime
 @abstract Denotes when receipt data was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Denotes when receipt data was last updated.
 */
@property(nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property status
 @abstract Receipt upload status.
 */
@property(nonatomic, assign, readonly) SMReceiptStatus status;
/*!
 @property data
 @abstract Custom, developer-defined data associated with the receipt.
 @discussion This data is sent when the receipt is uploaded.
 */
@property(nonatomic, strong, readonly) NSDictionary *data;
/*!
 @property results
 @abstract Returns results of processing receipt images for purchase data.
 @discussion Each array element represents purchase data for a single item.
 */
@property(nonatomic, strong, readonly) NSArray<SMReceiptResult *> *results;
/*!
 @property storeName
 @abstract The name of the store from which the receipt was issued.
 */
@property(nonatomic, strong, readonly) NSString *storeName;
/*!
 @property receiptDate
 @abstract The date on which the receipt was issued.
 */
@property(nonatomic, strong, readonly) NSString *receiptDate;
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMReceiptStatus @/link enum value.
 @param string String to convert.
 @result @link SMReceiptStatus @/link enum value.
 */
+ (SMReceiptStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMReceiptStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMReceiptStatus)status;

@end

#endif /* __SM_RECEIPT__ */
