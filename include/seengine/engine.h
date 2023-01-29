/*

    //TODO: 

*/

#ifndef S_ENGINE_H_
#define S_ENGINE_H_

    #include "types/sechar.h"
    #include "sedefines.h"
    #include <stdint.h>
    #include <stdbool.h>

    extern SECHAR *SE_service_name;

    int semain(int32_t, SECHAR *[]);

    void SE_LoadServiceName(void);

    bool SE_StartedForService(int32_t, SECHAR *[]);

#endif
