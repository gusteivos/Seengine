/*

    TODO:

*/
#ifndef SERVICE_POSIX_H_
#define SERVICE_POSIX_H_

    #include "service.h"

    #define SERVICE_NAME_FILE_PATH "./service-name.txt"

    #define ARGUMENT_START_SERVICE "--run"

    void *posixServiceWorkerThreadRoutine(void *);

    int prepareArgumentsForPosixServiceEntry(int, char *[], char *[]);

    void posixServiceEntry(int, char *[]);

    void serviceMain(int, char *[]);

#endif /*SERVICE_POSIX_H_ */
