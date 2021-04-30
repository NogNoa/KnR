#include "KnR_getline.h"
#define LNSIZ 0x50

void fold (char string[], int nline)
{
	for (int i=0;i<nline;++i)
	{
		int start = i*LNSIZ, end = (i+1)*LNSIZ;
		for (int j=start;j<end && string[j] ;++j)
			{putchar(string[j]);}
		putchar('\n');
	}
}

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];

	while ((len = KnR_getline(line, MAXLINE)) > 0){
		if (len <= LNSIZ)
			{printf("%s", line);}
		else 
			{fold(line, (len + LNSIZ - 1) / LNSIZ);}
	}
	return 0;
}