/*

    TODO:

*/
#ifndef SERVICE_H_
#define SERVICE_H_

    #include "./../stdincludes.h"

    #ifdef _WIN32

        #include "service.WIN32.h"

    #else /* POSIX */

        #include "service.POSIX.h"

    #endif

    #define MAXIMUM_SERVICE_NAME_LENGTH 16

    #define MINIMUM_SERVICE_NAME_LENGTH 4

    #define STACK_SIZE_FOR_WORKER_THREAD 2048000 /*2,048 MB */

    extern int exit_code_for_service_executable;

    extern int exit_code_for_service;

    extern char *service_name;

    bool loadServiceName(void);

    bool startedForService(int, char *[]);

#endif /*SERVICE_H_ */
