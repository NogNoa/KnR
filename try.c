#include <stdio.h>
#include "stoi.lb.c"
#ifndef recrs_reverse
    #include "control_flow.lb.c"
#endif
#ifndef getint
    #include "molon.lb.c"
#endif
void rcrs_itoa(int n, char s[]);
void recrs_reverse(char s[]);

int main(int argc, char *argv[])
{
    int n, m[0x100]={0};
    char s[1024];

    scanf("%d",&n);

    rcrs_itoa(n,s);
    recrs_reverse(s);
    printf("%s\n",s);

    getint(m);
    printf("%d\n",*m);

    return 0;

}
