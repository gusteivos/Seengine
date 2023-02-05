/*

    //TODO: 

*/

#ifndef SEE_H_
#define SEE_H_

    #ifdef _WIN32

        #include "seengine/engine.WIN32.h"

    #else /*POSIX */

        #include "seengine/engine.POSIX.h"

    #endif

#endif
