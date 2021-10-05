#include "stdio.lb.h"

int main(int argc, char *argv[])
{
    char a;
    FILE *scroll = fopen("molon.lb.c","r");
    for (int i =0; i<100; i++)
    {   a=getc(scroll);
        putchar(a);
    }
    fflush(stdout);
    fclose(scroll);
    return 0;
}
