#include "KnR_getline.h"

int main(int argc, char *argv[])
{
	int tail=10, nline;
	
	nline = linearise();
	if (argc > 1 && argv[1][0] == '-')
		tail=atoi(argv[1]+1);
	for (int i;(i=nline-tail)<nline;tail--)
		printf("%s",lini[i]);
}
