
#ifdef _WIN32

    #include <service/service.WIN32.h>

    void WINAPI serviceMain(DWORD _argument_counter, LPTSTR* _argument_values)
    {

        char *_directory_binary = se_GetDirectoryBinary();

        if (_directory_binary == NULL) goto _LEAVE_SERVICE_DIRECTLY;

        if (!se_SetCurrentDirectory(_directory_binary)) goto _LEAVE_SERVICE_DIRECTLY;

        free(_directory_binary);

        if (!loadServiceName()) goto _LEAVE_SERVICE_DIRECTLY;

        service_status_handler = RegisterServiceCtrlHandler(service_name, serviceControlHandler);

        if (!service_status_handler)
        {

            reportServiceEvent("Todo:");

            goto _LEAVE_SERVICE_DIRECTLY;

        }

        exit_code_for_service_executable = 0;

        exit_code_for_service = NO_ERROR;

        SecureZeroMemory(&service_status, sizeof(service_status));

        service_status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;

        reportServiceStatus(SERVICE_START_PENDING, 250);

        service_stop_event_handler = CreateEvent(NULL, TRUE, FALSE, NULL);

        if (service_stop_event_handler == NULL)
        {
        
            reportServiceEvent("Todo:");
        
            goto _LEAVE_SERVICE;

        }

        reportServiceStatus(SERVICE_RUNNING, 0);

        /*

            TODO: get into the work thread, with as much stack as possible.

        */

        CloseHandle(service_stop_event_handler);

    _LEAVE_SERVICE:

        service_status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;

        reportServiceStatus(SERVICE_STOPPED, 0);

    _LEAVE_SERVICE_DIRECTLY:

        return;

    }

#endif
