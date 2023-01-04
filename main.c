#include <service/service.h>

int main(int _argument_count, char *_argument_values[])
{

    if (!startedForService(_argument_count, _argument_values))
    {

        /*

            TODO:

        */

    }
    #ifndef _WIN32 /*POSIX */

        else
        {

            char *__argument_values_to_service_entry[0];

            int __argument_count_to_service_entry = prepareArgumentsForPosixServiceEntry(_argument_count, _argument_values, __argument_values_to_service_entry);

            posixServiceEntry(__argument_count_to_service_entry, __argument_values_to_service_entry);

        }

    #endif

    return exit_code_for_service_executable;

}
