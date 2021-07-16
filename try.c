#include <stdio.h>
//#include <string.h>
#include "stoi.lb.c"
int rcrs_itoa(int n, char s[], int i);

int main(int argc, char *argv[])
{
    int n;
    char s[1024];

    scanf("%d",&n);

    rcrs_itoa(n,s, 0);
    printf("%s\n",s);
    
    return 0;
}
