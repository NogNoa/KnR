#include <stdio.h>

char * squeeze_multi(char s1[], char s2[]);
char * squeeze(char s[], int c);
char * strcat(char s[], char t[]);
char * set(char s[]);
int any(char s1[], char s2[]);
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

void add_remove(int argc, char *argv[])
{
	int back;
	if (argc > 2){
		back = any(argv[1],argv[2]);
		printf("%d\n",back);
	}
}

int main(int argc, char *argv[])
{
	add_remove(argc,argv);
	printf("%x\n",rightrot(0xa6, 3));
}
