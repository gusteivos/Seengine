/*

    //TODO: 

*/

#ifndef _WIN32

    #include <stdio.h>

    #include <seengine/engine.POSIX.h>

    uint8_t SE_POSIXServiceEntry(int32_t argument_count, SECHAR *argument_values[])
    {

        uint8_t _output_value = SE_STARTED_FOR_SERVICE;

        pid_t _child_process_id = fork();

        if (_child_process_id >= 0)
        {

            if (_child_process_id > 0) goto _end_of_function;

            if (setsid() < 0)
            {

                _output_value = SE_ERROR_STARTED_FOR_SERVICE;

                goto _end_of_function;

            }

            signal(SIGCHLD, SIG_IGN);
        
            signal(SIGHUP , SIG_IGN);

            //TODO:

        }
        else
            _output_value = SE_ERROR_STARTED_FOR_SERVICE;

    _end_of_function:

        return _output_value;

    }

#endif
