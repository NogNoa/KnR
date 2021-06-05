#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);
char * file_stringise(char * filename);

void control_flow(char s[], char t[])
{
	escape(s, t);
}

int main(int argc, char *argv[])
{
	char * call;
	char back[0x1000];
	char filename[15]  = {'c','o','n','t','r','o','l','_','f','l','o','w','.','c'};
	//FILE *file = fopen("./control_flow.c","r");

	call = file_stringise(filename);
	control_flow(back,call);
	printf("%s\n",back);
	printf("The value of EOF is %x\n\n", EOF);
}
