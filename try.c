#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
void expand(char s1[],char s2[]);

int main(int argc, char *argv[])
{
    char text1[50] = "-A a-c a-c-e a--~ d-a a-a -! ~- - z-";
    char text2[0x400];
    
    printf("Original string:\n%s\n", text1);
    
    expand(text1, text2);
    printf("Expanded string:\n%s\n", text2);
    
    return 0;
}
