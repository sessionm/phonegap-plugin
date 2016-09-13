//
//  SMAddress.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_ADDRESS__
#define __SM_ADDRESS__

#import <Foundation/Foundation.h>

/*!
 @class SMAddress
 @abstract Defines the data associated with a shipping address used in an offer order (see @link //apple_ref/occ/cl/SMOrder @/link).
 */
@interface SMAddress : NSObject

/*!
 @property addressee
 @abstract Recipient of ordered items.
 */
@property(nonatomic, strong, readwrite) NSString *addressee;
/*!
 @property street1
 @abstract First part of street address (e.g. 1234 Example Street).
 */
@property(nonatomic, strong, readwrite) NSString *street1;
/*!
 @property street2
 @abstract Second part of street address (e.g. Apartment 1).
 */
@property(nonatomic, strong, readwrite) NSString *street2;
/*!
 @property city
 @abstract Addressee's city.
 */
@property(nonatomic, strong, readwrite) NSString *city;
/*!
 @property stateProvince
 @abstract Addressee's state or province.
 */
@property(nonatomic, strong, readwrite) NSString *stateProvince;
/*!
 @property postalCode
 @abstract Addressee's postal code.
 */
@property(nonatomic, strong, readwrite) NSString *postalCode;
/*!
 @property country
 @abstract Addressee's country.
 */
@property(nonatomic, strong, readwrite) NSString *country;

@end

#endif /* __SM_ADDRESS__ */
