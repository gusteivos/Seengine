#include <stdutils.h>

int se_GetLastError()
{

    int _output_value = 0x00;

    #if _WIN32
    
        _output_value = (int)_doserrno;

    #else /*POSIX */

        _output_value = errno;

    #endif

    return _output_value;

}

char *se_GetDirectory(const char *_path)
{

    if (_path == NULL)
        return NULL;

    char *_last_separator_bar = NULL;

    #ifdef _WIN32

        _last_separator_bar = strrchr(_path, '\\');

    #else /*POSIX */

        _last_separator_bar = strrchr(_path, '/');

    #endif

    if (_last_separator_bar == NULL)
        return NULL;

    *(_last_separator_bar + 1) = '\0';

    char* _directory = malloc((strlen(_path) * sizeof(char)) + 1);

    strcpy(_directory, _path);

    return _directory;

}

char *se_GetDirectoryBinary()
{

    char _binary_path[256];

    #ifdef _WIN32

        DWORD _binary_path_length = GetModuleFileName(NULL, _binary_path, sizeof(_binary_path));

    #else /*POSIX */

        ssize_t _binary_path_length = readlink("/proc/self/exe", _binary_path, sizeof(_binary_path));

    #endif

    if (_binary_path_length <= 0)
        return NULL;

    _binary_path[_binary_path_length] = '\0';

    char *_directory_binary = se_GetDirectory(_binary_path);

    return _directory_binary;

}

bool se_SetCurrentDirectory(const char *_directory_path)
{

    bool _output_value = false;

    #ifdef _WIN32

        BOOL _for_output_value = SetCurrentDirectory(_directory_path);

        _output_value = (bool)_for_output_value;

    #else /*POSIX */

        int _for_output_value = chdir(_directory_path);

        if (_for_output_value == 0) _output_value = true;

    #endif

    return _output_value;

}
