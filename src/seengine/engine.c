#ifdef _WIN32

    #include <seengine/engine.WIN32.h>

#else /*POSIX */

    #include <seengine/engine.POSIX.h>

#endif

SECHAR *SE_service_name = NULL;

void SE_LoadServiceName()
{



}

bool SE_StartedForService(int32_t argument_count, SECHAR *argument_values[])
{

    bool _output_value = false;

    #ifdef _WIN32

        _output_value = SE_WIN32ServiceEntry() != SE_NOT_STARTED_FOR_SERVICE;

    #endif

    if (!_output_value)
    {

        //TODO:

        /*To debug: */ SE_POSIXServiceEntry(argument_count, argument_values);

    }

    return _output_value;

}
