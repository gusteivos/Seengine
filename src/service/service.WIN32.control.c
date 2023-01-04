
#ifdef _WIN32

    #include <service/service.WIN32.h>

    SERVICE_STATUS          service_status              = {0};

    SERVICE_STATUS_HANDLE   service_status_handler      = NULL;

    HANDLE                  service_stop_event_handler  = INVALID_HANDLE_VALUE;

    void WINAPI reportServiceStatus(DWORD _current_state, DWORD _wait_hint)
    {

        static DWORD _checkpoint = 1;

        service_status.dwCurrentState = _current_state;

        service_status.dwServiceSpecificExitCode = exit_code_for_service;

        service_status.dwWaitHint = _wait_hint;

        service_status.dwWin32ExitCode = exit_code_for_service_executable;

        if (_current_state == SERVICE_START_PENDING)
            service_status.dwControlsAccepted = 0;
        else
            service_status.dwControlsAccepted = SERVICE_ACCEPT_STOP;

        if ((_current_state == SERVICE_RUNNING) || (_current_state == SERVICE_STOPPED))
            service_status.dwCheckPoint = 0;
        else 
            service_status.dwCheckPoint = _checkpoint++;

        SetServiceStatus(service_status_handler, &service_status);
    
    }

    void WINAPI serviceControlHandler(DWORD _control_code)
    {

        switch(_control_code)
        {

            case SERVICE_CONTROL_STOP:

                exit_code_for_service_executable = NO_ERROR;

                reportServiceStatus(SERVICE_STOP_PENDING, 0);
                
                SetEvent(service_stop_event_handler);

                reportServiceStatus(service_status.dwCurrentState, 0);

                break;

            case SERVICE_CONTROL_INTERROGATE:

                SetServiceStatus(service_status_handler, &service_status);
            
                break;

        }

    }

#endif
