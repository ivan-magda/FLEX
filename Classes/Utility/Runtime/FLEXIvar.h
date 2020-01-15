//
//  FLEXIvar.h
//  FLEX
//
//  Derived from MirrorKit.
//  Created by Tanner on 6/30/15.
//  Copyright (c) 2015 Tanner Bennett. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FLEXRuntimeUtility.h"
#import <objc/runtime.h>


@interface FLEXIvar : NSObject

+ (instancetype)ivar:(Ivar)ivar;
+ (instancetype)named:(NSString *)name onClass:(Class)cls;

/// The underlying \c Ivar data structure.
@property (nonatomic, readonly) Ivar             objc_ivar;

/// The name of the instance variable.
@property (nonatomic, readonly) NSString         *name;
/// The type of the instance variable.
@property (nonatomic, readonly) FLEXTypeEncoding type;
/// The type encoding string of the instance variable.
@property (nonatomic, readonly) NSString         *typeEncoding;
/// The offset of the instance variable.
@property (nonatomic, readonly) NSInteger        offset;

/// For internal use
@property (nonatomic) id tag;

- (id)getValue:(id)target;

/// Calls into -getValue: and passes that value into
/// -[FLEXRuntimeUtility potentiallyUnwrapBoxedPointer:type:]
/// and returns the result
- (id)getPotentiallyUnboxedValue:(id)target;

@end