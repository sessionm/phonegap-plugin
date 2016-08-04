//
//  SMAddress.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_ADDRESS__
#define __SM_ADDRESS__

#import <Foundation/Foundation.h>

@interface SMAddress : NSObject

@property (nonatomic, strong)NSString *addressee;
@property (nonatomic, strong)NSString *street1;
@property (nonatomic, strong)NSString *street2;
@property (nonatomic, strong)NSString *city;
@property (nonatomic, strong)NSString *stateProvince;
@property (nonatomic, strong)NSString *postalCode;
@property (nonatomic, strong)NSString *country;

@end

#endif /* __SM_ADDRESS__ */