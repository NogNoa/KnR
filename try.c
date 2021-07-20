#include <stdio.h>
#ifndef getint
    #include "molon.lb.c"
#endif


int main(int argc, char *argv[])
{
    int n[0x100]={0}, r;
    double m[0x100]={0};

    r=getint(n);
    printf("%d %x\n",*n,r);
    getfloat(m);
    printf("%f\n",*m);

    return 0;

}
