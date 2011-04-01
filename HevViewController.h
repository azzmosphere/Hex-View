//
//  HevViewController.h
//  Hex View
//
//  Created by Aaron Spiteri on 5/03/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "HexViewModel.h"

#define FONT "Courier New"
#define FNTSZ 12.0

@interface HevViewController : NSObject {
    NSArray* files;                      /* Container for open files */
    IBOutlet NSTextView *fview;          /* The main window class */
    IBOutlet NSProgressIndicator *fProg; /* Progress inficator */
    HexViewModel *hexview;
}
@property(nonatomic, retain) IBOutlet NSTextView *fview;

-(IBAction)openFile: (id) sender;
-(IBAction)closeFile: (id) sender;
-(void) awakeFromNib;
@end
