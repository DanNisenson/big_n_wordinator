#include <stdio.h>
#include <string.h>

void addUnit(char *buffer, int i)
{
    char words[10][6] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    strcat(buffer, words[i]);
}

void addTeens(char *buffer, int i)
{
    char words[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    strcat(buffer, words[i]);
}

void addTens(char *buffer, int i)
{
    char words[8][8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    strcat(buffer, words[i - 2]);
}

void addNumber(char *buffer, int n)
{
    double divided = n / 10;
    int reminder = n % 10;

    if (divided < 1)
    {
        addUnit(buffer, n);
    }
    else if (divided < 2)
    {
        addTeens(buffer, reminder);
    }
    else if (divided < 10)
    {
        addTens(buffer, divided);
        if (reminder >= 1)
        {
            addUnit(buffer, reminder);
        }
    }
}
