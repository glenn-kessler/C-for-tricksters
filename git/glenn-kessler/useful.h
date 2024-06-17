#ifndef USEFUL_H
#define USEFUL_H

#define BYTE_WISE_REVERSE_U32(n) ((uint32_t) (((n & 0x000000FF) << 24) | \
                                              ((n & 0x0000FF00) <<  8) | \
                                              ((n & 0x00FF0000) >>  8) | \
                                              ((n & 0xFF000000) >> 24)))

#endif // USEFUL_H
