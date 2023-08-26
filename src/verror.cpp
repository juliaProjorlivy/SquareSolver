/*
 * ============================================================================
 *
 *       Filename:  verror.cpp
 *
 *    Description:  Find an error
 *
 *        Created:  24/08/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdarg.h>
#include "verror.h"

/*!
    \brief Print the error description, file and line where an error happened.
*/
void verror(const char *description, ...)
{
    fprintf(stderr, "ERROR: ");

    va_list args;
    va_start(args, description);
    vfprintf(stderr, description, args);
    va_end(args);

    fprintf(stderr, END_OF_COLOR);
}
