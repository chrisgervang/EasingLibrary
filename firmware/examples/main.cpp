/*
 * Easing Functions: Copyright (c) 2010 Andy Brown
 * http://www.andybrown.me.uk
 *
 * This work is licensed under a Creative Commons
 * Attribution-ShareAlike 3.0 Unported License.
 * http://creativecommons.org/licenses/by-sa/3.0/
 */

#include <wiring.h>
#include "Tester.h"


// Compatibility stub for undefined pure virtual

extern "C" void __cxa_pure_virtual() { for(;;); }


/*
 * Main entry point
 */

int main(void)
{
	Tester tester;

	init();

// run the tester in an infinite loop

	for(;;)
		tester.run();

	return 0;
}
