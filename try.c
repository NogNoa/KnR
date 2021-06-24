#include <stdio.h>

int charindex(char s[],char t);
int strindex_1st(char s[],char t[]);
int strindex_last(char s[], char t[]);
double sci_atof(char s[]);

int main(int argc, char *argv[])
{
    int a,b;
    double c,d;
    char s[7]="cabcab";
   
    a=strindex_last(s,"ca");
    b=strindex_1st(s,"ab");
    c=sci_atof("-314.159265359e-2");
    d=sci_atof("31415.9265359e-4");

    printf("%d %d %f %f \n",a,b,c,d);
    
    return 0;
}
