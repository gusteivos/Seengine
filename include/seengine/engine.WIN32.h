/*

    TODO: 

*/

#ifdef _WIN32

    #ifndef SE_ENGINE_WIN32_H_
    #define SE_ENGINE_WIN32_H_

        #include "engine.h"
        #include <windows.h>

        uint8_t SEE_WIN32ServiceEntry(void);

        void    SEE_WIN32ServiceMain (int32_t, SEECHAR *[]);

    #endif

#endif
