#include <types.h>
#include <kern/errno.h>
#include <kern/unistd.h>
#include <lib.h>
#include <uio.h>
#include <syscall.h>
#include <vnode.h>
#include <vfs.h>
#include <current.h>
#include <synch.h>

int sys___exit(int code) {

	// Assign the code to the exitCode of thread struct
  	curthread->exitCode = code;

	// Close the thread which will release the sem
  	thread_exit();

	//Return
  	return 0;

}
