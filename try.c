#include <stdio.h>

int htoi(char s[]);
char * squeeze_multi(char s1[], char s2[]);
char * squeeze(char s[], int c);
char * strcat(char s[], char t[]);
char * set(char s[]);
char * any(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	char * back;

	for (int i=1;i<argc;++i)
		printf("%d\n",htoi(argv[i]));
	back = set(argv[1]);
	printf("%s\n",back);
}
