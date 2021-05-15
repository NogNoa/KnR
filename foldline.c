#include "KnR_getline.h"
#define LNSIZ 0x50

void smrt_fold (char str[])
{
	#define IN 1
	#define OUT 0
	int j;

	for (j=0;j<LNSIZ && str[j] ;++j)
		{putchar(str[j]);}
	putchar('\n');
}

void equ_fold (char str[])
{
	int j;

	for (j=0;j<LNSIZ && str[j] ;++j)
		{putchar(str[j]);}
	putchar('\n');
	if (str[j])
		equ_fold(&str[LNSIZ]);
}

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];

	while ((len = KnR_getline(line, MAXLINE)) > 0){
		if (len <= LNSIZ)
			{printf("%s", line);}
		else 
			{equ_fold(line);}
	}
	return 0;
}