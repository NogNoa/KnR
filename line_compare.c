#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIN_S 0120

int main(int argc, char* argv[])
{
	FILE *comperer, *comperand;
	int iline;
	
	if (argc>2)
	{	comperer = fopen(argv[1],"r");
		comperand = fopen(argv[2],"r");
	}
	else
		printf("please name two files");

	char *liner=malloc(LIN_S), *linand=malloc(LIN_S);

	for (iline=0;( liner = fgets(liner, LIN_S, comperer) ) && ( linand = fgets(linand, LIN_S, comperand) ); iline++)
	{
		if (strcmp(liner,linand) != 0)
			break;
	}
	if (liner && linand)
	{	printf("The first difference between %s and %s is on line %d.\n\n\n",argv[1],argv[2],iline);
		printf("%s line %d:\n%s\n",argv[1],iline,liner);
		printf("%s line %d:\n%s\n",argv[2],iline,linand);
	}
	
}
