#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
void expand(char s1[],char s2[]);
void itoa(int n, char s[]);
void KnR_itoa(int n, char s[]);

int main(int argc, char *argv[])
{
    const int lng=0x20;
    char a[lng],b[lng],c[lng],d[lng];

    itoa(-1, a);
    KnR_itoa(-1, b);
    itoa(~(~0U >> 1), c);
    KnR_itoa(~(~0U >> 1), d);


    printf("%s %s  %s %s\n",a,b,c,d);
    
    return 0;
}
