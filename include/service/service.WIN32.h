/*

    TODO:

*/
#ifndef SERVICE_WIN32_H_
#define SERVICE_WIN32_H_

    #include "service.h"

    #define SERVICE_NAME_FILE_PATH ".\\service-name.txt"

    extern SERVICE_STATUS           service_status;

    extern SERVICE_STATUS_HANDLE    service_status_handler;

    extern HANDLE                   service_stop_event_handler;

    DWORD WINAPI win32ServiceWorkerThreadRoutine(LPVOID);

    void WINAPI reportServiceStatus(DWORD, DWORD);

    void WINAPI serviceControlHandler(DWORD);

    void WINAPI reportServiceEvent(LPSTR);

    void WINAPI serviceMain(DWORD, LPTSTR *);

    bool win32ServiceEntry(void);

#endif /*SERVICE_WIN32_H_ */
