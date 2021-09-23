#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char get_directive(char *direct, size_t lim);
void seperate(char *str, char sep, size_t lim, int vacount, ...);
void minprintf(char *fmt, ...);

int main(int argc, char *argv[])
{
    stdin = fopen("table_lookup.lb.c","r");

    char direct[0200];
    /*
    while (get_directive(direct, 0200) != '\0')
    {   char cmd[0100], header[0100];
        seperate(direct,' ', 0100, 1, header); //seperate don't leave side effects on direct
        seperate(direct,' ', 0100, 2, cmd, header);
        minprintf("cmd:%s header:%s\n",cmd, header);
    }
    */
    minprintf("%3d %-3x %X %o %u %g %p\n", 11, 11, 11, 11, -1, 3.12, direct);
    return 0;
}
