#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main()
{
	char mxchar = (unsigned char) -1 >> 1;
	char mnchar = 0;
	int i, j;
	char hest[mxchar], c;

	enum unprintables{NUL, SOH, STX, ETX, EOT, ENQ, ACK, BEL,
					   BS,  HT,  LF,  VT,  FF,  CR,  SO,  SI
					  DEL, DC1, DC2, DC3, DC4, NAK, SYN, ETB
					  CAN,  EM, SUB, ESC,  FS,  GS,  RS,  US}
	
	for (i = 0; i<mxchar; ++i)
		hest[i] = 0;
	
	while ((c = getchar()) != EOF) {
			++hest[c];
	}

	for (i=0; hest[i]==0;++i)
		mnchar=i;

	for (i=0;i<' ';++i)
		printf("%3s  ",unprintables[i]);
		for (j=0; j<=hest[i]; ++j)
			putchar('|');
		putchar('\n');

	for (;i<mxchar; ++i){
		printf("  ");putchar(i);printf("  ");
		for (j=0; j<=hest[i]; ++j)
			putchar('|');
		putchar('\n');
	}
}
