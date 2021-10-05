#include "stdio.lb.h"

int main(int argc, char *argv[])
{
    char a;
    FILE *scroll = fopen_fld("molon.lb.c","r");
    for (int i =0; i<100; i++)
    {   a=getc_fld(scroll);
        putchar(a);
    }
    fflush(stdout);
    return 0;
}
