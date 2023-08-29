#include "verror.h"
#include <stdio.h>
#include <stdarg.h>

void verror(const char *description, ...)
{
    fprintf (stderr, "ERROR: ");

    va_list args;
    va_start (args, description);
    vfprintf (stderr, description, args);
    va_end (args);
}
