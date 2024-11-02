#include <stdio.h>

void addNumber(char *buffer, int buflen, int n)
{
    char units[10][6] = {" ", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char tens[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    double divided = n / 10;
    int reminder = n % 10;

    if (divided < 1)
    {
        snprintf(buffer, buflen, "%s", units[n]);
    }
    else if (divided < 2)
    {
        snprintf(buffer, buflen, "%s", tens[reminder]);
    }
}
