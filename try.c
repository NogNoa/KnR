#include <stdio.h>
#ifndef getint
    #include "molon.lb.c"
#endif


int main(int argc, char *argv[])
{
    int n[0x100]={0};
    double m[0x100]={0};

    getint(n);
    printf("%d\n",*n);
    getfloat(m);
    printf("%f\n",*m);

    return 0;

}
