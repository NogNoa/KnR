#include "KnR_getline.h"

void reverse(char to[], char from[],int len)
{  // copy 'from' into 'to' in reverse; */

	int i=len-1, j=0;
	
	if (from[i] == '\n')
		--i;
	for (; i >= 0; --i)
		to[j++] = from[i];
	to[j++]='\n';to[j]='\0';
} 

int main()
{  /* print each line in reverse */

	int len;
	char line[MAXLINE];
	char enil[MAXLINE];

	while ((len = KnR_getline(line, MAXLINE)) > 0){
		reverse(enil, line, len);
		printf("%s", enil);
	}
	return 0;
}
