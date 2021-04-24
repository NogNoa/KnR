#include <stdio.h>
#define MAXLINE 1000


int KnR_getline(char s[], int lim)
{  // read a line into s, return lenght

	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c== '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

void reverse(char to[], char from[],int len)
{  // copy 'from' into 'to' in reverse; */

	to[len] = '\0';
	for (int i = 0; i < len -1; ++i)
		to[len - i - 1] = from[i];
	if (from[len - 1] == '\n'){
		to[len] = '\n';
		to[len + 1] = '\0';
		to[0] = '\r';
	}
	else{
		to[0] = from[len - 1];
		to[len] = '\0';
	}
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
