/*

    TODO:

*/
#ifndef STD_UTILS_H
#define STD_UTILS_H

    #include "stdincludes.h"

    int se_GetLastError(void);

    char *se_GetDirectory(const char *);

    char *se_GetDirectoryBinary(void);

    bool se_SetCurrentDirectory(const char *);

#endif /*STD_UTILS_H*/
