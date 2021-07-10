#include <stdio.h>
//#include <string.h>
void escape(char s[], char t[]);
void descape(char s[], char t[]);
char * file_stringise(char * filename);

int main(int argc, char *argv[])
{
    char *scroll,codex[2048];

    scroll = file_stringise(argv[1]);
    escape(codex,scroll);
    printf("%s\n",codex);
    
    return 0;
}
