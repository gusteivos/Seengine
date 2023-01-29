#ifdef _WIN32

    #include <seengine/engine.WIN32.h>

#else /*POSIX */

    #include <seengine/engine.POSIX.h>

#endif
#include <stdio.h>

int semain(int32_t argument_count, SECHAR *argument_values[])
{

    

    return 0;

}

int main(int argument_count, SECHAR *argument_values[])
{
    
    if (!SE_StartedForService(argument_count, argument_values))
    {

        

    }

    return 0;

}
