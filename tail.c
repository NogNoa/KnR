#include "KnR_getline.h"

int main(int argc, char *argv[])
{
	int tail=10, nline;

	//stdin = fopen("tail.c", "r");
	
	nline = linearise();
	if (argc > 1 && argv[1][0] == '-')
		tail=atoi(argv[1]+1);
	tail = (tail < nline) ? tail : nline;
	for (int i;(i=nline-tail)<nline;tail--)
		printf("%s",lini[i]);
}

/* todo?: hard to identify sementation fault on printing line 4:"{\n"*/
