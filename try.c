#include <stdio.h>

int charindex(char s[],char t);
int strindex_1st(char s[],char t[]);
int strindex_last(char s[], char t[]);

int main(int argc, char *argv[])
{
    int a,b,c,d;
    char s[7]="cabcab";
   
    a=strindex_last(s,"ca");
    b=strindex_1st(s,"ab");
    c=strindex_last(s,"ba");
    d=strindex_last(s,"dd");

    printf("%d %d %d %d \n",a,b,c,d);
    
    return 0;
}
