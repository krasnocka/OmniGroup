// Copyright 2008, 2010 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <OmniFoundation/OFObject.h>

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
@class NSFileWrapper;
#endif
@class OUZipArchive;

@interface OUZipMember : OFObject
{
@private;
    NSString *_name;
    NSDate *_date;
}

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
- initWithFileWrapper:(NSFileWrapper *)fileWrapper; // Returns an instance of the appropriate subclass
- (NSFileWrapper *)fileWrapperRepresentation; // Returns a new autoreleased file wrapper; won't return the same wrapper on multiple calls
#endif
- initWithPath:(NSString *)path fileManager:(NSFileManager *)fileManager;

- initWithName:(NSString *)name date:(NSDate *)date; // Assumes that you won't create a duplicate/bad name within a parent (case conflicts, embedded '/', etc.)

- (NSString *)name;
- (NSDate *)date;

- (BOOL)appendToZipArchive:(OUZipArchive *)zip fileNamePrefix:(NSString *)fileNamePrefix error:(NSError **)outError;

- (NSComparisonResult)localizedCaseInsensitiveCompareByName:(OUZipMember *)otherMember;

@end