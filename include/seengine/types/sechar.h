/*

    //TODO: 

*/

#ifndef SE_CHAR_H_
#define SE_CHAR_H_

    #ifdef _WIN32

        #include <tchar.h>

        #define SE_Text(text) _T(text)

        #define SE_strcasecmp(stra, strb) _tcsicmp(stra, strb)

        typedef TCHAR se_char_t;

    #else /*POSIX */

        #include <string.h>

        #define SE_Text(text) text

        #define SE_strcasecmp(stra, strb) strcasecmp (stra, strb)

        typedef char se_char_t;

    #endif

    typedef se_char_t SECHAR;

#endif
