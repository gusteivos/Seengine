/*

    //TODO: 

*/

#ifdef _WIN32

    #include <seengine/engine.WIN32.h>

    uint8_t SE_WIN32ServiceEntry()
    {

        SERVICE_TABLE_ENTRY _dispatcher_entry_table[] = 
        {

            {"", (LPSERVICE_MAIN_FUNCTION)NULL}, /*TODO: */
        
            {NULL, NULL}
        
        };

        uint8_t _output_value = SE_STARTED_FOR_SERVICE;

        if (StartServiceCtrlDispatcher(_dispatcher_entry_table))
        {
        
            _output_value = SE_ERROR_STARTED_FOR_SERVICE;
        
            if (GetLastError() == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT)
                _output_value = SE_NOT_STARTED_FOR_SERVICE;

        }

        return _output_value;

    }

#endif
