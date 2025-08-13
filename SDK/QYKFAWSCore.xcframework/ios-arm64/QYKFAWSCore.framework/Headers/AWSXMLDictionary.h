//
//  XMLDictionary.h
//
//  Version 1.4
//
//  Created by Nick Lockwood on 15/11/2010.
//  Copyright 2010 Charcoal Design. All rights reserved.
//
//  Get the latest version of XMLDictionary from here:
//
//  https://github.com/nicklockwood/XMLDictionary
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <Foundation/Foundation.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wobjc-missing-property-synthesis"


typedef NS_ENUM(NSInteger, QYKFXMLDictionaryAttributesMode)
{
    QYKFXMLDictionaryAttributesModePrefixed = 0, //default
    QYKFXMLDictionaryAttributesModeDictionary,
    QYKFXMLDictionaryAttributesModeUnprefixed,
    QYKFXMLDictionaryAttributesModeDiscard
};


typedef NS_ENUM(NSInteger, QYKFXMLDictionaryNodeNameMode)
{
    QYKFXMLDictionaryNodeNameModeRootOnly = 0, //default
    QYKFXMLDictionaryNodeNameModeAlways,
    QYKFXMLDictionaryNodeNameModeNever
};


static NSString *const QYKFXMLDictionaryAttributesKey   = @"__attributes";
static NSString *const QYKFXMLDictionaryCommentsKey     = @"__comments";
static NSString *const QYKFXMLDictionaryTextKey         = @"__text";
static NSString *const QYKFXMLDictionaryNodeNameKey     = @"__name";
static NSString *const QYKFXMLDictionaryAttributePrefix = @"_";


@interface QYKFXMLDictionaryParser : NSObject <NSCopying>

+ (QYKFXMLDictionaryParser *)sharedInstance;

@property (nonatomic, assign) BOOL collapseTextNodes; // defaults to YES
@property (nonatomic, assign) BOOL stripEmptyNodes;   // defaults to YES
@property (nonatomic, assign) BOOL trimWhiteSpace;    // defaults to YES
@property (nonatomic, assign) BOOL alwaysUseArrays;   // defaults to NO
@property (nonatomic, assign) BOOL preserveComments;  // defaults to NO
@property (nonatomic, assign) BOOL wrapRootNode;      // defaults to NO

@property (nonatomic, assign) QYKFXMLDictionaryAttributesMode attributesMode;
@property (nonatomic, assign) QYKFXMLDictionaryNodeNameMode nodeNameMode;

- (NSDictionary *)dictionaryWithParser:(NSXMLParser *)parser;
- (NSDictionary *)dictionaryWithData:(NSData *)data;
- (NSDictionary *)dictionaryWithString:(NSString *)string;
- (NSDictionary *)dictionaryWithFile:(NSString *)path;

@end


@interface NSDictionary (QYKFXMLDictionary)

+ (NSDictionary *)QYKFxml_dictionaryWithXMLParser:(NSXMLParser *)parser;
+ (NSDictionary *)QYKFxml_dictionaryWithXMLData:(NSData *)data;
+ (NSDictionary *)QYKFxml_dictionaryWithXMLString:(NSString *)string;
+ (NSDictionary *)QYKFxml_dictionaryWithXMLFile:(NSString *)path;

- (NSDictionary *)QYKFxml_attributes;
- (NSDictionary *)QYKFxml_childNodes;
- (NSArray *)QYKFxml_comments;
- (NSString *)QYKFxml_nodeName;
- (NSString *)QYKFxml_innerText;
- (NSString *)QYKFxml_innerXML;
- (NSString *)QYKFxml_XMLString;

- (NSArray *)QYKFxml_arrayValueForKeyPath:(NSString *)keyPath;
- (NSString *)QYKFxml_stringValueForKeyPath:(NSString *)keyPath;
- (NSDictionary *)QYKFxml_dictionaryValueForKeyPath:(NSString *)keyPath;

@end


@interface NSString (QYKFXMLDictionary)

- (NSString *)QYKFxml_XMLEncodedString;

@end


#pragma GCC diagnostic pop
