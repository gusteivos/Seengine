/*

    //TODO: 

*/

#ifndef SE_DEFINES_H_
#define SE_DEFINES_H_

    #include "types/sechar.h"

    #define ARGUMENT_START_SERVICE SE_Text("--run-se")

    #define MAXIMUM_SERVICE_NAME_LENGTH 16 * sizeof(se_char_t);

    #define MINIMUM_SERVICE_NAME_LENGTH 4  * sizeof(se_char_t);

    #define STACK_SIZE_FOR_WORKER_THREAD 2048000 /*2,048 MB */

#endif
