#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char get_directive(char *direct, int lim);

int main(int argc, char *argv[])
{
    stdin = fopen("try.c","r");

    char direct[0200];
    
    while (get_directive(direct, 0200) != EOF)
        printf("%s",direct);
    return 0;
}
