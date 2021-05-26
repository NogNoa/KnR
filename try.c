#include <stdio.h>

int htoi(char s[]);
int squeeze_multi(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	char *back;

	for (int i=1;i<argc;++i)
		printf("%d\n",htoi(argv[i]));
	back = squeeze_multi(argv[1],argv[2]);
	printf("%s",back);
}
