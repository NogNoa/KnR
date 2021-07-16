#include <stdio.h>
#include <ctype.h>
#include "stoi.lb.c"
void rcrs_itoa(int n, char s[]);

int main(int argc, char *argv[])
{
    int n;
    char s[1024];

    scanf("%d",&n);

    rcrs_itoa(n,s);
    rcrs_reverse(0,s);
    printf("%s\n",s);
    
    printf("size_t:%lx signed int:%lx unsigned int:%lx \n int:%x char:%x\n",sizeof(size_t),sizeof(int signed),sizeof(int unsigned),(int)EOF,(char)EOF);


    return 0;

}
