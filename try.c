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
	char *call;
	char back[0x1000];
	FILE *file = fopen("control_flow.c","r");

	byte_foolish();	
	fscanf(file, "%s", &call);
	control_flow(back,call);
	printf("%s\n",call);

}
