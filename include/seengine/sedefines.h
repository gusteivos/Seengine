/*

    //TODO: 

*/

#ifndef SE_DEFINES_H_
#define SE_DEFINES_H_

    #include "types/sechar.h"

    #define SE_ARGUMENT_START_SERVICE _SE_T("--run-se")

    #define SE_MAXIMUM_SERVICE_NAME_LENGTH  16 * sizeof(se_char_t);

    #define SE_MINIMUM_SERVICE_NAME_LENGTH  4  * sizeof(se_char_t);

    #define SE_STACK_SIZE_FOR_WORKER_THREAD 2048000 /*2,048 MB */

    #define SE_NOT_STARTED_FOR_SERVICE   0

    #define SE_STARTED_FOR_SERVICE       1

    #define SE_ERROR_STARTED_FOR_SERVICE 2

#endif
