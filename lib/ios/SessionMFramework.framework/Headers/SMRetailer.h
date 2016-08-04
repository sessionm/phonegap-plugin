//
//  SMRetailer.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_RETAILER__
#define __SM_RETAILER__

#import <Foundation/Foundation.h>

/*!
 @class SMRetailer
 @abstract Defines the data associated with a retailer that has a loyalty program.
 */
@interface SMRetailer : NSObject

/*!
 @property retailerID
 @abstract Unique ID for retailer.
 */
@property(nonatomic, strong, readonly) NSString *retailerID;
/*!
 @property name
 @abstract Retailer name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property card
 @abstract Loyalty card name.
 */
@property(nonatomic, strong, readonly) NSString *card;
/*!
 @property icon
 @abstract URL for retailer thumbnail icon.
 */
@property(nonatomic, strong, readonly) NSString *iconURL;
/*!
 @property image
 @abstract URL for retailer banner image.
 */
@property(nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property isLinked
 @abstract Indicates whether the current user has linked a loyalty card issued by the retailer.
 */
@property(nonatomic, assign, readonly) BOOL      isLinked;

@property(nonatomic, strong, readonly)NSDictionary *extras;

@end

#endif /* __SM_RETAILER__ */
