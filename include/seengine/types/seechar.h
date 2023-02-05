/*

    //TODO: 

*/

#ifndef SEE_CHAR_H_
#define SEE_CHAR_H_

    #ifdef _WIN32

        #include <tchar.h>

        #define SEE_T(text) _T(text)

        #define SEE_strcasecmp(stra, strb) _tcsicmp(stra, strb)

        typedef TCHAR see_char_t;

    #else /*POSIX */

        #include <string.h>

        #define SEE_T(text) text

        #define SEE_strcasecmp(stra, strb) strcasecmp(stra, strb)

        typedef char see_char_t;

    #endif

    typedef see_char_t SEECHAR;

#endif
