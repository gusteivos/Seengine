#include <service.h>

int exit_code_for_service_executable = 0;

int exit_code_for_service = 0;

char *service_name = NULL;

bool loadServiceName()
{

    FILE *_service_name_file_descriptor = fopen(SERVICE_NAME_FILE_PATH, "r");

    if (_service_name_file_descriptor == NULL)
        return false;

    char *_service_name_file_contents = malloc(MAXIMUM_SERVICE_NAME_LENGTH + 1);

    *(_service_name_file_contents + MAXIMUM_SERVICE_NAME_LENGTH + 1) = '\0';

    fgets(_service_name_file_contents, MAXIMUM_SERVICE_NAME_LENGTH + 1, _service_name_file_descriptor);

    fclose(_service_name_file_descriptor);

    if (strlen(_service_name_file_contents) < 4)
        return false;

    service_name = _service_name_file_contents;

    return true;

}

bool startedForService(int _argument_count, char *_argument_values[])
{

    #ifdef _WIN32

        return win32ServiceEntry();

    #else /*POSIX */

        for (int __q = 0; __q < _argument_count; __q++)
            if (!strcasecmp(_argument_values[__q], ARGUMENT_START_SERVICE))
                return true;

        return false;

    #endif

}
