/*

    //TODO: 

*/

#ifndef SE_ENGINE_POSIX_H_
#define SE_ENGINE_POSIX_H_

    #include "engine.h"

    #include <errno.h>
    #include <unistd.h>
    #include <signal.h>
    #include <pthread.h>
    #include <sched.h>

    uint8_t SEE_POSIXServiceEntry(int32_t, SEECHAR *[]);

    void    SEE_POSIXServiceMain (int32_t, SEECHAR *[]);

#endif
