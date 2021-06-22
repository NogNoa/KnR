#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
void expand(char s1[],char s2[]);
void itoa(int n, char s[]);
void KnR_itoa(int n, char s[]);
short itob(int n, char s[], short b);

int main(int argc, char *argv[])
{
    const int lng=0x20;
    char a[lng],b[lng],c[lng],d[lng];

    itob(-2, a,36);
    itob(20, b,1);
    itob((~(~0U >> 1)), c, 2);
    itob((~(~0U >> 1)), d, 3);


    printf("%s %s  %s %s\n",a,b,c,d);
    
    return 0;
}
