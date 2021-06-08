#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);

int main(int argc, char *argv[])
{
    char text1[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char text2[51];
    
    printf("Original string:\n%s\n", text1);
    
    escape(text2, text1);
    printf("Escaped string:\n%s\n", text2);
    
    descape(text1, text2);
    printf("Unescaped string:\n%s\n", text1);
    
    return 0;
}
