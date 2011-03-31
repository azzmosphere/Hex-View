/*
 *========================================================
 *  HexViewModel.h
 *  Hex View
 *
 *  Created by Aaron Spiteri on 7/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 *========================================================
 */

#import <Cocoa/Cocoa.h>
#import <limits.h>
#import <stdio.h>
#import "HexView.h"

#define HEXFORMAT "0x%04x "
#define BYTESZ 1

@interface HexViewModel : NSObject {
    NSString      *fileError;/* file error */
    NSFileHandle  *filedes;  /* file descriptor */
    NSData        *fbuffer;  /* buffer containing file data */
}

@property(nonatomic, copy) NSString *fileError;
@property(nonatomic, copy) NSString      *filePath;
@property(nonatomic, copy) NSData        *fbuffer;

-(HexViewModel *) initWithFilePath: (NSString *) filePathIn;


-(BOOL)checkFile;
-(void)closeFile;
-(NSString *)getFileError;
-(NSString *)getBufferAsHex;

@end
