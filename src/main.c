#include <stdio.h>
#include "lib.c"

void addNumber(char *buffer, int n);

int main()
{
    char buffer[1000] = "";
    addNumber(buffer, 15);
    printf("%s", buffer);
    return 0;
}
