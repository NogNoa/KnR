#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MXWRD 20

void measure(int hest[]);
void expose(int hest[]);

void main()
{
	int hest[(MXWRD+1)];

	measure(hest);
	expose(hest);
}

void measure(int hest[])
{
	int i,c;
	int len = 0;
	int state = OUT;

	for (i = 0; i<(MXWRD+1); ++i)
		hest[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t'){
			state = IN;
			++len;
		}
		else if (state == IN){
			if (len > MXWRD)
				len = MXWRD;
			++hest[len];
			state = OUT;
			len = 0;
		}
	}
}

void expose(int hest[])
{
	void mkrow(char row[], int len);

	int i,j;
	//char plus;
	char row[768]; //arbitrary 0x300

	for (i=1; i<=(MXWRD); ++i){
		mkrow(row, hest[i]);
		/*
		if (i == MXWRD)
			plus = "+";
		else
			plus = " ";
			*/
		printf("%2d  %s\n",i, row);
	}
}

void mkrow(char row[], int len)
{
	int j;
	for (j=0; j<len; ++j)
		row[j] ='|';
	row[j] = '\0';
}
