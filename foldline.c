#include "KnR_getline.h"
#define LNSIZ 0x50

void smrt_fold (char str[])
{
	#define IN 1
	#define OUT 0
	int j;
	_Bool state = IN ;
	int last = 0;

	for (j=0;str[j];++j)
	{
		if (str[j] == ' ' || str[j] == '\t')
			state = OUT;
		else if (state == OUT)
		{
			if (j>=LNSIZ)
				break;
			last = j;
			state = IN;
		}
	}
	for(int i=0;i<last;++i)
		putchar(str[i]);
	putchar('\n');
	if (str[j])
		smrt_fold(&str[last]);
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
			{smrt_fold(line);}
	}
	return 0;
}
