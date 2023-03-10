#include <seengine/see.h>

  #include <stdio.h> /*debug*/

SEECHAR *SEE_service_name = NULL;

void SEE_LoadServiceName()
{



}

bool SEE_StartService     (int32_t argument_count, SEECHAR *argument_values[])
{

    #ifdef _WIN32

        SEE_LoadServiceName();

        

    #else /*POSIX */

        SEE_POSIXServiceEntry(argument_count, argument_values);

    #endif

}

bool SEE_StartedForService(int32_t argument_count, SEECHAR *argument_values[])
{

    bool _output_value = false;

    #ifdef _WIN32

        _output_value = SEE_WIN32ServiceEntry() == SEE_NOT_STARTED_FOR_SERVICE;

    #endif

    if (!_output_value)
    {

        if (argument_count > 1 && !SEE_strcasecmp(argument_values[1], SEE_ARGUMENT_START_SERVICE))
        {

            _output_value = true;

            int32_t ___argument_count_to_start = argument_count - 1;

            SEECHAR **___argument_values_to_start = malloc(___argument_count_to_start * sizeof(SEECHAR *));

            if (___argument_values_to_start == NULL) goto _end_of_function;

            int ___q = 0;

            for (int32_t ____w = 0; ____w < argument_count; ____w++)
                if (____w != 1)
                {

                    ___argument_values_to_start[___q] = argument_values[____w];

                    ___q++;

                }

                for (int q = 0; q < ___argument_count_to_start; q++) /*debug*/
                        printf("%s", ___argument_values_to_start[q]);

           SEE_StartService(___argument_count_to_start, ___argument_values_to_start);

        }

    }

_end_of_function:

    return _output_value;

}
