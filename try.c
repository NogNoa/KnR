#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int stops[1000]={0};
    char a = '  ';

    for (int i=1;i<argc;i++)
        stops[i-1] = atoi(argv[i]);
    for (int i=0;stops[i];i++)
        printf("%d\n",stops[i]);
    int c[2]={'Ψ','\0'};
    printf("%s\n", c);
    return 0;
}
