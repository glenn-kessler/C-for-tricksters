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

/**
 * @struct ST_UNION_EXAMPLE
 * @union  provide different types for the same data
 * @brief  provide type to access single bits as bitfield
 */
typedef struct
{
    union
    {
        uint8_t value;
        struct
        {
            uint8_t Bit_0 : 1;
            uint8_t Bit_1 : 1;
            uint8_t Bit_2 : 1;
            uint8_t Bit_3 : 1;
            uint8_t Bit_4 : 1;
            uint8_t Bit_5 : 1;
            uint8_t Bit_6 : 1;
            uint8_t Bit_7 : 1;
        };
    };
} ST_UNION_EXAMPLE;

static ST_EXAMPLE _container;  ///< global var

static ST_UNION_EXAMPLE _union_example_array[2]  = {{.value = 0}}; // init to zero by using the union

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
