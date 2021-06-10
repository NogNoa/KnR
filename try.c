#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
void expand(char s1[],char s2[]);

int main(int argc, char *argv[])
{
    char call[50] = "-A a-c a-c-e !--~ d-a a-a -! ~- - z-";
    char back[0x400];
    
    printf("Original string:\n%s\n", call);
    
    expand(call, back);
    printf("Expanded string:\n%s\n", back);
    
    return 0;
}
