/*
 *  HexView.c
 *  Hex View
 *
 *  Created by Aaron Spiteri on 6/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "HexView.h"


/*
 *======================================================
 * getFileAsLong
 *
 * Take each character of a file and return it as 
 * a long value.
 *======================================================
 *
 */
int getFileAsInt(const char *fileName, int *lary, int *count) {
    
    int fildes = open(fileName, O_RDONLY|O_SHLOCK), err = 0, i = 0, *buffer = calloc(1,sizeof(int)),tmp;
    ssize_t rv = 0;
    if(fildes == -1){
        err = errno;
    }
    if(err == 0){
        do{
            tmp = 0;
            rv = read(fildes, &tmp, BYTESZ);
            if(rv == -1){
                err = errno;
            }
            
            /* Add new number to array */
            else if(rv != 0){
                buffer[i ++] = tmp;
                buffer = realloc(buffer, (1 + i * sizeof(int)));
                
                /* break loop an error has occurred */
                if(buffer == NULL){
                    err = errno;
                    rv = 0;
               }
            }
        }
        while(rv && rv != -1);
        close(fildes);
    }
    
    /* return our new pointers */
    if(! err){
        *(lary) = *(buffer);
        *(count) = i;
    }
    return err;
}