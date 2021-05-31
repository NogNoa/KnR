#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
void escape(char s[], char t[]);
void descape(char s[], char t[]);

void byte_foolish(void)
{
	printf("%x\n",rightrot(0xa6, 3));
}

void control_flow(char s[], char t[])
{
	descape(s, t);
}

int main(int argc, char *argv[])
{
	char back[0x100];

	byte_foolish();
	control_flow(back,argv[1]);
	printf("%s\n",back);

}
