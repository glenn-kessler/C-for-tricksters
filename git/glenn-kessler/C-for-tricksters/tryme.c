#include "stdio.h"

// https://stackoverflow.com/questions/7780809/is-it-possible-to-print-out-only-a-certain-section-of-a-c-string-without-making

int main(void)
{
	char * yourString = "Whatever";
	printf(" %*.*s the first 2 characters of your string.\n", 2,2, yourString);
	
	yourString = "x";
	printf(" %*.*s the first 2 characters of your string.\n", 2,2, yourString);

	// output will be
	//
	//  Wh the first 2 characters of your string.
	//  x the first 2 characters of your string.

	return 0;
}


/**********************************************
******  Bit-field usage                 *******
**********************************************/
#include <stdio.h>
#include <stdbool.h>

typedef union
{
    struct                     ///< bit-field of 32 bit lenght (no name given)
    {
        int file         : 1;  ///< lowest bit
        int dir          : 1;  ///< 2nd bit
        int rwx          : 3;  ///< some example crc
        int reserved     : 27; ///< the remaining 28 bits
    };
}BITFIELD_EXAMPLE;             ///< union to prevent memory 


typedef struct
{
    int u32myVar;
    BITFIELD_EXAMPLE bf;  ///< use bitfield

} ST_EXAMPLE;

static ST_EXAMPLE _container;  ///< global var

int main(void)
{


    _container.u32myVar = 0xBADU;

    _container.bf.file = true;
    _container.bf.dir  = false;
    _container.bf.rwx  = 1+2+4;

    printf("%x", _container.bf);
}

// repeat until x reaches 0
unsigned int x = 1000;
do { /* do something */ } while (--x);
