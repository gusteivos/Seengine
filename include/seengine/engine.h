/*

    //TODO: 

*/

#ifndef SE_ENGINE_H_
#define SE_ENGINE_H_

    #include "types/seechar.h"
    #include "seedefines.h"
    #include <stdint.h>
    #include <stdbool.h>
    #include <stdlib.h>

    extern SEECHAR *SEE_service_name;

    int seemain(int32_t, SEECHAR *[]);

    void SEE_LoadServiceName(void);

    bool SEE_StartService     (int32_t, SEECHAR *[]);

    bool SEE_StartedForService(int32_t, SEECHAR *[]);

#endif
