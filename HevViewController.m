/*
 *========================================================
 *  HevViewController.m
 *  Hex View
 *
 *  Created by Aaron Spiteri on 5/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *========================================================
 */

#import "HevViewController.h"

@implementation HevViewController
@synthesize fview;

/*
 *========================================================
 * awakeFromNib
 * Initilize the main window (NIB) to what it should look
 * like immediately after it has been completed.
 *========================================================
 */
-(void) awakeFromNib {
    [super awakeFromNib];
    
    /* Make progress bar disappear after the file has loaded */
    [fProg setDoubleValue:0.0];
    [fProg setDisplayedWhenStopped:NO];
    [fProg setIndeterminate:NO];
    
    /* Set the default font and size */
    fview.font = [NSFont fontWithName:@FONT size:FNTSZ];
}

/*
 *========================================================
 * openFile
 * Create a dialog box and send the file to the model for
 * opening.
 *
 * Initilize the model and keep until close is clicked.
 *
 * Then open the fview as HEX (this may change in the 
 * near future).
 *========================================================
 */
-(IBAction)openFile: (id) sender {
    int i = 0; /* file counter */
    
    // Create the File Open Dialog class.
    NSOpenPanel* openDlg = [NSOpenPanel openPanel];
    NSAlert *alert = [[NSAlert alloc] init];
   
    // Enable the selection of files in the dialog.
    [openDlg setCanChooseFiles:YES];
    
    // Display dialog box and open file(s) that are selected.
    if( [openDlg runModalForDirectory:nil file:nil] == NSOKButton){
        
        files = [openDlg filenames];
        for(i = 0; i < [files count]; i ++){
            hexview = [[[HexViewModel alloc] initWithFilePath:[files objectAtIndex:i]] autorelease];
            if([hexview checkFile] == NO){
                [alert setMessageText:[hexview getFileError]];
                [alert runModal];
            }
            else { 
                /* Populate buffer */
                [fview setString:[hexview getBufferAsHex: fProg]];
                
                /* Add file to recent files array */
                [[NSDocumentController sharedDocumentController]
                 noteNewRecentDocumentURL:[NSURL fileURLWithPath:[files objectAtIndex:i]]];
                
                /* turn off progress bar */
                [fProg setDisplayedWhenStopped:NO];
                [fProg setDoubleValue:0.0];
            }
        }
    }
    [alert release];
}

/*
 *========================================================
 * closeFile
 *
 * Because HexView does not keep the file open this 
 * routine just clears the buffer.
 *========================================================
 */ 
-(IBAction)closeFile: (id) sender {
    [fview setString:@""];
}
@end
