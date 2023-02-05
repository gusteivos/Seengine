/*

    //TODO: 

*/

#ifdef _WIN32

    #include <seengine/engine.WIN32.h>

    uint8_t SEE_WIN32ServiceEntry()
    {

        uint8_t _output_value = SEE_STARTED_FOR_SERVICE;

        SERVICE_TABLE_ENTRY _dispatcher_entry_table[] =
        {

            {"", (LPSERVICE_MAIN_FUNCTION)SEE_WIN32ServiceMain},
        
            {NULL, NULL}
        
        };

        if (StartServiceCtrlDispatcher(_dispatcher_entry_table))
        {
        
            _output_value = SEE_ERROR_STARTED_FOR_SERVICE;
        
            if (GetLastError() == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT)
                _output_value = SEE_NOT_STARTED_FOR_SERVICE;

        }

        return _output_value;

    }

#endif
