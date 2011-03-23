/*
 *========================================================
 *  HexViewModel.m
 *  Hex View
 *
 *  Created by Aaron Spiteri on 7/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *========================================================
 */

#import "HexViewModel.h"

@implementation HexViewModel
@synthesize fildes, fileError, filedes, filePath, fbuffer;

/*
 *========================================================
 * 
 * Class constructor.
 *========================================================
 */
-(HexViewModel *) initWithFilePath: (NSString *) filePathIn {
    self = [super init];
    if( self ){
        self.filePath = filePathIn;
    }
    return self;
}

/*
 *========================================================
 * 
 * checkFile
 * 
 * Check the file for any potential problems using the 
 * file manager,  also prime the file for opening by
 * setting encoding type and other attributes required.
 *========================================================
 */
-(BOOL) checkFile {
    NSFileManager *filemgr = [NSFileManager defaultManager];
    if ([filemgr fileExistsAtPath: self.filePath ] == NO){
        self.fileError = [self.filePath stringByAppendingString:@": file does not exist"];
        return NO;
    }
    else if([filemgr isReadableFileAtPath: self.filePath ] == NO){
        self.fileError = [self.filePath stringByAppendingString:@": can not be read"];
        return NO;
    }
    return YES;
}

/*
 *========================================================
 * closeFile
 *
 * Close file if it has been open otherwise do nothing.
 *========================================================
 */
-(void)closeFile {
    // Function stump for completeness
}

/*
 *========================================================
 * getFileError
 *========================================================
 */
-(NSString *) getFileError {
    return self.fileError;
}

/*
 *========================================================
 * getBuffer
 *
 * Return the contents of the read file as ASCII text
 *========================================================
 */
-(NSString *)getBufferAsHex {
    NSString  *sout = nil;
    int i =0, *lary = calloc(1,sizeof(int)), byteCount = 0;
    char *cFileName = calloc(PATH_MAX,BYTESZ);
    
    [filePath getCString: cFileName maxLength: PATH_MAX encoding: NSNonLossyASCIIStringEncoding];
    
    if((i = getFileAsInt(cFileName, lary,&byteCount)) != 0){
        fileError = [NSString stringWithCString: strerror(i)]; 
        return nil;
    }
    
    for(;i < byteCount;i ++){
        if(sout == nil){
            sout = [NSString stringWithFormat:@HEXFORMAT,(long) lary[i]];
        }
        else {
            sout = [sout stringByAppendingFormat:@HEXFORMAT,(long) lary[i]];
        }
    }
    return sout;
}

@end