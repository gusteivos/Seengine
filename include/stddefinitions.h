/*

    TODO:

*/
#ifndef STD_DEFINITIONS_H_
#define STD_DEFINITIONS_H_

    #include "stdincludes.h"

    #ifdef _WIN32

        

    #else

        #define Sleep(milliseconds) usleep(milliseconds)

    #endif

#endif /*STD_DEFINITIONS_H_*/
