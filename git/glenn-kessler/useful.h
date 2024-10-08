#ifndef USEFUL_H
#define USEFUL_H

#include <stdio.h>
#include <stdlib.h>

///< requires GCC 3.1 or higher: true: if the element is an array. false: if the element is a pointer
#define IS_STATIC_ARRAY(arr) !__builtin_types_compatible_p(typeof(arr), typeof(&arr[0]))

///< compile time size check, will raise: error: size of array 'ASSERTION_FAILURE' is negative
#define CT_ASSERT(exp) typedef int ASSERTION_FAILURE [(exp) ? 1 : -1]

#define BYTE_WISE_REVERSE_U32(n) ((uint32_t) (((n & 0x000000FF) << 24) | \
                                              ((n & 0x0000FF00) <<  8) | \
                                              ((n & 0x00FF0000) >>  8) | \
                                              ((n & 0xFF000000) >> 24)))

///< array related
#define GET_OBJECT_COUNT(arr)                       (sizeof(arr) / sizeof((arr)[0]))
#define GET_LAST_INDEX(arr)                         (GET_OBJECT_COUNT(arr) - 1)
#define GET_LAST_OBJECT(arr)                        ((arr)[GET_LAST_INDEX(arr)])

#endif // USEFUL_H
