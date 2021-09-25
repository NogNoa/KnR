#include <stdio.h>

void minprintf(char *fmt, ...);
void minscanf(char *fmt, ...);

int main(int argc, char *argv[])
{
    int i, ix, ex, o, u;
    double g;
    void  *p;

    minscanf("%d %x %X %o %u %g %p\n",&i,&ix,&ex,&o,&u, &g, &p);
    minprintf("%d %x %X %o %u %g %p\n",i,ix,ex,o,u, g, p);

    return 0;
}
