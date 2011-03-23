/*
 *  HexView.h
 *  Hex View
 *
 *  Created by Aaron Spiteri on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 * This is the model file of the applications.
 */


#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define BYTESZ 1

int getFileAsInt(const char *fileName, int *lary, int *count);
