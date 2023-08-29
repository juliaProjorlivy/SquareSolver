 /* ============================================================================
 *
 *       Filename:  error.h
 *
 *    Description:  Header file for error
 *
 *        Created:  24/03/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#ifndef VERROR_H
#define VERROR_H

#define RED          "\x1b[31;1m"  /**< paint command line text red */  
#define END_OF_COLOR "\n\x1b[39;49m"  /**< paint command line default color */


/*!
    \brief Print the error description, file and line where an error happened.
*/
#define VERROR(...) do {                                       \
        fprintf (stderr, RED "%s (%d): ", __FILE__, __LINE__); \
        verror (__VA_ARGS__);                                  \
        fprintf (stderr, END_OF_COLOR);                        \
    } while (0)

void verror (const char *description, ...);

#endif
