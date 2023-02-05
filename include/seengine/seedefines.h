/*

    //TODO: 

*/

#ifndef SEE_DEFINES_H_
#define SEE_DEFINES_H_

    #include "types/seechar.h"

    #define SEE_ARGUMENT_START_SERVICE SEE_T("--run-see")

    #define SEE_MAXIMUM_SERVICE_NAME_LENGTH  16 * sizeof(SEECHAR);

    #define SEE_MINIMUM_SERVICE_NAME_LENGTH  4  * sizeof(SEECHAR);

    #define SEE_STACK_SIZE_FOR_WORKER_THREAD 2048000 /*2,048 MB */

    #define SEE_NOT_STARTED_FOR_SERVICE   0

    #define SEE_STARTED_FOR_SERVICE       1

    #define SEE_ERROR_STARTED_FOR_SERVICE 2

#endif
