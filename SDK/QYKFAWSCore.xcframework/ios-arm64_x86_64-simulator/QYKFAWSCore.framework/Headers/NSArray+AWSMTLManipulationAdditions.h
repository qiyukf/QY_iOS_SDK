//
//  NSArray+MTLManipulationAdditions.h
//  Mantle
//
//  Created by Josh Abernathy on 9/19/12.
//  Copyright (c) 2012 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (QYKFMTLManipulationAdditions)

// The first object in the array or nil if the array is empty.
// Forwards to `firstObject` which has been first declared in iOS7, but works with iOS4/10.6.
@property (nonatomic, readonly, strong) id QYKFmtl_firstObject;

// Returns a new array without all instances of the given object.
- (NSArray *)QYKFmtl_arrayByRemovingObject:(id)object;

// Returns a new array without the first object. If the array is empty, it
// returns the empty array.
- (NSArray *)QYKFmtl_arrayByRemovingFirstObject;

// Returns a new array without the last object. If the array is empty, it
// returns the empty array.
- (NSArray *)QYKFmtl_arrayByRemovingLastObject;

@end
