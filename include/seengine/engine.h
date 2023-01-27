/*

    //TODO: 

*/

#ifndef S_ENGINE_H_
#define S_ENGINE_H_

    #include "types/sechar.h"
    #include "sedefines.h"
    #include <stdint.h>
    #include <stdbool.h>

    #ifdef _WIN32

        #include "engine.WIN32.h"

    #else /*POSIX */

        #include "engine.POSIX.h"

    #endif

    extern TCHAR *SE_service_name;

    int semain(int32_t, SECHAR *[]);

    void SE_LoadServiceName();

    bool SE_StartedForService(int32_t, SECHAR *[]);

#endif
