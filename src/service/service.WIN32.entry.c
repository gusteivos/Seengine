
#ifdef _WIN32

    #include <service/service.WIN32.h>

    bool win32ServiceEntry(void)
    {

        SERVICE_TABLE_ENTRY _dispatcher_entry_table[] = 
        {

            {"", (LPSERVICE_MAIN_FUNCTION)serviceMain},
        
            {NULL, NULL}
        
        };

        if (!StartServiceCtrlDispatcher(_dispatcher_entry_table))
        {
        
            DWORD __error_code = GetLastError();
        
            if (__error_code != ERROR_FAILED_SERVICE_CONTROLLER_CONNECT) exit_code_for_service_executable = (int)__error_code;

            return false;

        }

        return true;

    }

#endif
