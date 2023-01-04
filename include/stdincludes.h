#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stddefinitions.h"
#include "stdutils.h"

#ifdef _WIN32

    #include <windows.h>

#else /*POSIX */

    #include <errno.h>
    #include <unistd.h>
    #include <signal.h>
    #include <pthread.h>
    #include <sched.h>

#endif
