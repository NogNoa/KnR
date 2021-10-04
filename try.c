#include "stdio.lb.h"

FILE *fopen_fld(char *name, char *mode);

int main(int argc, char *argv[])
{
    char a;
    FILE *scroll = fopen_fld("a.txt","r");
    for (int i =0; i<100; i++)
        a=getc_fld(scroll);
    
    return 0;
}
