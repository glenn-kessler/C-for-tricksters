#include "stdio.h"

// https://stackoverflow.com/questions/7780809/is-it-possible-to-print-out-only-a-certain-section-of-a-c-string-without-making

char yourString = "Whatever";
printf("print the first two letters of your String here: %*.*s", 2, yourString);
