#include <stdio.h>
#include "stoi.lb.c"
#ifndef swap
    #include "add_remove-string.lb.c"
#endif
void rcrs_itoa(int n, char s[]);

int main(int argc, char *argv[])
{
    int n;
    char s[1024];

    scanf("%d",&n);

    rcrs_itoa(n,s);
    rcrs_reverse(0,s);
    printf("%s\n",s);
    
    int a = 14, b=23;
    swap(int, a, b);
    printf("%x\n %x\n",a,b);

    return 0;

}
