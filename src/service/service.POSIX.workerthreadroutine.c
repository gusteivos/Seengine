
#ifndef _WIN32

    #include <service/service.POSIX.h>
    
    void *posixServiceWorkerThreadRoutine(void *t)
    {

        while (1)
        {

            Sleep(10);
        
        }

        return NULL;

    }
    
#endif
