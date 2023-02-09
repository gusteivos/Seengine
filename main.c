#include <seengine/see.h>
#include <stdio.h>

int seemain(int32_t argument_count, SEECHAR *argument_values[])
{

    /*Service code here. */

    return 0;

}

int main(int32_t argument_count, SEECHAR *argument_values[])
{

    if (!SEE_StartedForService(argument_count, argument_values))
    {

        /*Program Code Here. */

    }

    return 0;

}
