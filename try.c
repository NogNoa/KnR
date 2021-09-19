#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char get_directive(char *direct, int lim);
int seperate(char *str, char sep, int lim, int vacount, ...);

int main(int argc, char *argv[])
{
    stdin = fopen("try.c","r");

    char direct[0200];
    
    while (get_directive(direct, 0200) != EOF)
    {   char cmd[0100], file[0100];
        seperate(direct,' ', 0100, 2, cmd, file);
        printf("cmd:%s file:%s\n",cmd, file);
    }
    return 0;
}
