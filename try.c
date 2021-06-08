#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
char * file_stringise(char * filename);

void control_flow(char s[], char t[])
{
	descape(s, t);
	escape(t, s);
}

int main(int argc, char *argv[])
{
	char * call;
	char back[0x1000];
	char filename[15]  = "control_flow.c";
	//FILE *file = fopen("./control_flow.c","r");

	call = file_stringise(filename);
	control_flow(back,call);
	printf("%s\n",call);
	printf("The value of EOF is %x\n", EOF);
}
