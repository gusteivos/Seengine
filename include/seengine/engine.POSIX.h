/*

    //TODO: 

*/

#ifndef S_ENGINE_POSIX_H_
#define S_ENGINE_POSIX_H_

    #include "engine.h"

    #include <errno.h>
    #include <unistd.h>
    #include <signal.h>
    #include <pthread.h>
    #include <sched.h>

    uint8_t SE_POSIXServiceEntry(int32_t, SECHAR *[]);

#endif
