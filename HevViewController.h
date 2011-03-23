//
//  HevViewController.h
//  Hex View
//
//  Created by Aaron Spiteri on 5/03/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "HexViewModel.h"

@interface HevViewController : NSObject {
    NSArray* files;  /* Container for open files */
    IBOutlet NSTextView *fview;
    HexViewModel *hexview;
}
@property(nonatomic, retain) IBOutlet NSTextView *fview;

-(IBAction)openFile: (id) sender;
-(IBAction)closeFile: (id) sender;
@end
