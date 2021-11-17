#include "KnR_getline.h"

int main(int argc, char *argv[])
{
	int tail=10;

	//stdin = fopen("tail.c", "r");
	
	page pg = linearise();
	if (argc > 1 && argv[1][0] == '-')
		tail=atoi(argv[1]+1);
	tail = (tail < pg.nline) ? tail : pg.nline;
	for (int i;(i=pg.nline-tail) < pg.nline;tail--)
		printf("%s",pg.lini[i]);
}

