
#ifndef _WIN32 /*POSIX */

    #include <service/service.POSIX.h>

    int prepareArgumentsForPosixServiceEntry(int _in_argument_count, char *_in_argument_values[], char *_out_argument_values[])
    {

        int _output_value = 0;

        /*

            TODO:

        */

        return _output_value;

    }

    void posixServiceEntry(int _argument_count, char *_argument_values[])
    {

        pid_t _child_process_id = fork();

        if (_child_process_id < 0)
        {

            exit_code_for_service_executable = se_GetLastError();

            return;

        }

        if (_child_process_id > 0)
            return;

        if (setsid() < 0)
            exit(EXIT_FAILURE);
        
        signal(SIGCHLD, SIG_IGN);
        
        signal(SIGHUP , SIG_IGN);

        pid_t _second_child_process_id = fork();

        if (_second_child_process_id < 0)
        {

            exit_code_for_service_executable = se_GetLastError();

            exit(exit_code_for_service_executable);

        }

        if (_second_child_process_id > 0)
            exit(EXIT_SUCCESS);

        for (int __q = sysconf(_SC_OPEN_MAX); __q > 0; __q--)
            close(__q);

        close(STDIN_FILENO);

        close(STDOUT_FILENO);
        
        close(STDERR_FILENO);

        serviceMain(_argument_count, _argument_values);

    }

#endif
