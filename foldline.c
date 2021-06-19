#include "KnR_getline.h"
#define LNSIZ 0x50 //maximum line is 80 chars

void smrt_fold(char*);

void equ_fold (char str[])
{
	int j;

	for (j=0;j<LNSIZ && str[j] ;++j)
		{putchar(str[j]);}
	if (str[j])
	//j reached LNSIZ rather than the terminating '\0'
	{
		putchar('\n');putchar('-');
		smrt_fold(&str[LNSIZ]);
	}
}


void smrt_fold (char str[])
{
	_Bool const IN=1;
	_Bool const OUT=0;
	
	int j;
	_Bool state = IN ;
	int last = 0;

	for (j=0;j<LNSIZ && str[j];++j)
	{
		if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			state = OUT;
		else if (state == OUT)
		{
			last = j;
			state = IN;
		}
	}
	if (last == 0)
	//the function found no whitespace, so a simpler one would be called
		equ_fold(str);
	else
	{
		for(int i=0;i<last;++i)
			putchar(str[i]);
		putchar('\n');
		if (str[j])
		//j reached LNSIZ rather than the terminating '\0'
			smrt_fold(&str[last]);
		else
		{
			printf("%s", str+last);
		}
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
			{smrt_fold(line);}
	}
	return 0;
}
