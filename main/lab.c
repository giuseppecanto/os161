#include <types.h>
#include <kern/errno.h>
#include <kern/reboot.h>
#include <kern/unistd.h>
#include <limits.h>
#include <lib.h>
#include <test.h>
#include "opt-sfs.h"
#include "opt-net.h"
#include "opt-lab.h"

#define NEW_LINE "\n"

#if OPT_LAB
	void lab(void);
#endif

void lab(void) {
	
	kprintf(NEW_LINE);
	kprintf("## THIS IS THE BEGINNING OF THE GAMES.##\n");
	kprintf(NEW_LINE);

}
