
#ifndef _WIN32

    #include <service/service.POSIX.h>

    void serviceMain(int _argument_count, char *_argument_values[])
    {

        char *_directory_binary = se_GetDirectoryBinary();

        if (_directory_binary == NULL) goto _LEAVE_SERVICE_DIRECTLY;

        if (!se_SetCurrentDirectory(_directory_binary)) goto _LEAVE_SERVICE_DIRECTLY;

        free(_directory_binary);

        if (!loadServiceName()) goto _LEAVE_SERVICE_DIRECTLY;

        /*

            TODO: get into the work thread, with as much stack as possible.

        */
    
    _LEAVE_SERVICE:

        

    _LEAVE_SERVICE_DIRECTLY:

        exit(exit_code_for_service);

    }
    
#endif
