#include <stdio.h>
#include <math.h>
#include <string.h>

const char *units_strs[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *teens_strs[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens_strs[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *scale_strs[] = {" thousand", " million", " billion", " trillion", " quadrillion", " quintillion"};

// get amount of zeroes / 3 (1 = thousands, 2 = millions, 3 = billions, ...)
int get_scale(double number)
{
    return (int)floor(log10(fabs(number))) / 3;
}

int format_units(char *buffer, int i)
{
    strcat(buffer, units_strs[i]);
    return 0;
}

int format_teens(char *buffer, int i)
{
    strcat(buffer, teens_strs[i]);
    return 0;
}

int format_tens(char *buffer, int i)
{
    strcat(buffer, tens_strs[i - 2]);
    return 0;
}

int format_hundreds(char buffer[], unsigned long n)
{
    int divided = n / 100;
    int reminder = n % 100;
    if (divided != 0)
    {
        format_units(buffer, divided);
        strcat(buffer, " hundred");
        if (reminder != 0)
        {
            strcat(buffer, " and ");
        }
    }
    return 0;
}

int format_1_to_99(char *buffer, unsigned long n)
{
    int divided = n / 10;
    int reminder = n % 10;

    if (divided < 1)
    {
        format_units(buffer, n);
        return 0;
    }
    else if (divided < 2)
    {
        format_teens(buffer, reminder);
        return 0;
    }
    else if (divided < 10)
    {
        format_tens(buffer, divided);
        if (reminder >= 1)
        {
            format_units(buffer, reminder);
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int format_1_to_999(char *buffer, unsigned long n)
{
    if (n >= 1 && n <= 99)
    {
        format_1_to_99(buffer, n);
        return 0;
    }
    else if (n <= 999)
    {
        format_hundreds(buffer, n);
        format_1_to_99(buffer, n % 100);
        return 0;
    }
    else
    {
        return 1;
    }
}

// format numbers by grouping 3 digits (billions, millions, thousands, ...)
int format_recursive(char *buffer, unsigned long n, int scale)
{
    unsigned long divisor = scale > 0 ? pow(1000, scale) : 1;
    unsigned long quotient = n / divisor;
    unsigned long reminder = n % divisor;

    if (quotient > 0)
    {
        format_1_to_999(buffer, quotient);
        if (scale > 0)
        {
            strcat(buffer, scale_strs[scale - 1]);
            if (reminder > 0)
            {
                strcat(buffer, ", ");
            }
        }
    }
    if (scale > 0)
    {
        scale--;
        return format_recursive(buffer, reminder, scale);
    }
    return 0;
}

int wordinator(char *buffer, unsigned long n)
{

    if (n < 1)
    {
        printf("Error: number must be int bigger than 0");
        return 1;
    }
    else if (n <= 9223372036854775807)
    {
        format_recursive(buffer, n, get_scale(n));
        return 0;
    }
    else
    {
        printf("Error: number too big");
        return 1;
    }
}
