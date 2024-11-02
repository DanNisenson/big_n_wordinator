#include <stdio.h>
#include <string.h>

int add_units(char *buffer, int i)
{
    char strs[10][6] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    strcat(buffer, strs[i]);
    return 0;
}

int add_teens(char *buffer, int i)
{
    char strs[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    strcat(buffer, strs[i]);
    return 0;
}

int add_tens(char *buffer, int i)
{
    char strs[8][8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    strcat(buffer, strs[i - 2]);
    return 0;
}

int add_hundreds(char buffer[], int n)
{
    char str[] = " hundred";
    add_units(buffer, n / 100);
    strcat(buffer, str);
    if (n > 100)
    {
        strcat(buffer, " and ");
    }
    return 0;
}

int add_0_to_99(char *buffer, int n)
{
    int divided = n / 10;
    int reminder = n % 10;

    if (divided < 1)
    {
        add_units(buffer, n);
        return 0;
    }
    else if (divided < 2)
    {
        add_teens(buffer, reminder);
        return 0;
    }
    else if (divided < 10)
    {
        add_tens(buffer, divided);
        if (reminder >= 1)
        {
            add_units(buffer, reminder);
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int wordinator(char *buffer, int n)
{

    if (n < 1)
    {
        printf("Error: number must be int bigger than 0");
        return 1;
    }
    else if (n > 0 && n < 99)
    {
        add_0_to_99(buffer, n);
        return 0;
    }
    else if (n < 999)
    {
        add_hundreds(buffer, n);
        add_0_to_99(buffer, n % 100);
        return 0;
    }
    else
    {
        printf("Error: number too big");
        return 1;
    }
}
