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

#define HEXFORMAT "0x%05x "
#define BYTESZ 1

@interface HexViewModel : NSObject {
    // DEPRECIATE fildes
    int       fildes;    /* file descriptor */
    
    // KEEP THIS
    NSString      *fileError;/* file error */
    NSFileHandle  *filedes;  /* file descriptor */
    NSData        *fbuffer;  /* buffer containing file data */
}
@property(readwrite) int fildes;

@property(nonatomic, copy) NSString *fileError;
@property(nonatomic, copy) NSFileHandle  *filedes;
@property(nonatomic, copy) NSString      *filePath;
@property(nonatomic, copy) NSData        *fbuffer;

-(HexViewModel *) initWithFilePath: (NSString *) filePathIn;


-(BOOL)checkFile;
-(void)closeFile;
-(NSString *)getFileError;
-(NSString *)getBufferAsHex;

@end
