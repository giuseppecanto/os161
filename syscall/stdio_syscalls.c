/*
 * Copyright (c) 2000, 2001, 2002, 2003, 2004, 2005, 2008, 2009
 *	The President and Fellows of Harvard College.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE UNIVERSITY AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <lib.h>
#include <uio.h>
#include <syscall.h>
#include <vnode.h>
#include <vfs.h>
#include <current.h>

#define BUFF_SIZE 31

int sys_write(userptr_t buffer, int nBytes, int *retval) {

	// Define variables
	int i;

	// Print out the buffer char by char
	for (i=0; i<nBytes; i++)
   		kprintf("%c", ((char*)buffer)[i]);
  	
	// Return the number of written char by reference
	*retval = i;

	// Return the function
  	return 0;
	
}

/*
* ASSUMPTION: nbytes = 1, always
*
*/
int sys_read(userptr_t buffer, int nbyte, int *retval) {

	// Defining variables
	static char myBuffer[BUFF_SIZE];
  	static int i=-1;
  	char *bufferX;
  
  	if ( !(i == -1) && !(myBuffer[i] == '\0') ) {
    		
		// Fill the buffer from stdin
    		kgets(myBuffer, BUFF_SIZE);

		// Zeroing
		i = -1;
  	}
  
	// Copy myBuffer to buffer (using bufferX as cast of buffer)
  	i += 1;
  	bufferX = (char*) buffer;  	
	bufferX[0] = myBuffer[i];

	// Return the number of written chars by reference
 	*retval = nbyte;

	// Return the function
  	return 0;

}
