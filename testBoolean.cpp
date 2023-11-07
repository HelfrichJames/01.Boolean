/***********************************************************************
 * Header:
 *    Test
 * Summary:
 *    Driver to test boolean.h
 * Author
 *    James Helfrich, PhD. (c) 2022 by Kendall Hunt
 ************************************************************************/


#ifndef DEBUG
#define DEBUG   // Remove this to skip the unit tests
#endif

#include "testBoolean.h"     // for the array unit tests


/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   
#ifdef DEBUG
   // unit tests
   TestBoolean().run();
#endif // DEBUG
   
   return 0;
}

