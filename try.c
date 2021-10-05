#include "stdio.lb.h"

FILE *fopen_fld(char *name, char *mode);

int main(int argc, char *argv[])
{
    char a;
    FILE *scroll = fopen_fld("molon.lb.c","r");
    for (int i =0; i<1025; i++)
    {   a=getc_fld(scroll);
        putc(a, stdout);
    }
    return 0;
}
