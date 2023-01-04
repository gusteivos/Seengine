
#ifdef _WIN32

    #include <service/service.WIN32.h>
    #include <strsafe.h>

    void WINAPI reportServiceEvent(LPSTR _to_report)
    {

        HANDLE _event_source;

        _event_source = RegisterEventSource(NULL, service_name);

        if(_event_source != NULL)
        {

           #define AMOUNT_OF_STRINGS_TO_REPORT 2

            LPCTSTR _strings_to_report[AMOUNT_OF_STRINGS_TO_REPORT];

            _strings_to_report[0] = service_name;

            TCHAR Buffer[32 + 128];

            StringCchPrintf(Buffer, 32 + 128, TEXT("%s, last error code: %d"), _to_report, GetLastError());

            _strings_to_report[1] = Buffer;

            ReportEvent(_event_source, EVENTLOG_ERROR_TYPE, 0, 0x0001, NULL, AMOUNT_OF_STRINGS_TO_REPORT, 0, _strings_to_report, NULL);

            DeregisterEventSource(_event_source);
        
        }

    }

#endif
