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

