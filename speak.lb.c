// Ritchie, D. and Kernighan, W. (1988) p128

#ifndef va_list
	#include <stdarg.h>
#endif
#ifndef putchar
	#include <stdio.h>
#endif
#ifndef strlen
	#include <string.h>
#endif
#ifndef isdigit
	#include <ctype.h>
#endif
#ifndef atoi
	#include <stdlib.h>
#endif


void minprintf(char *fmt, ...)
{  /* minprintf: minimal printf with variable argument list */
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval, minfmt[3],back[0200];
	int ival;
	unsigned uval;
	double dval;
	
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		int fldwd=0, perc=~0;
		
		if (*p != '%') 
		{	putchar(*p);
			continue;
		}

		sscanf(++p,"%d",&fldwd);
		while(isdigit(*p) || *p=='-')
			p++;
		if (*p == '.')
		{	sscanf(++p,"%d",&perc);
			while(isdigit(*p) || *p=='-')
				p++;
		}
		switch (*p)
		{case 'd':
		case 'i':
		case 'x':
		case 'X':
		case 'o':
			ival = va_arg(ap, int);
			sprintf(minfmt,"%%%c",*p);
			sprintf(back, minfmt, ival);
			break;
		case 'u':
			uval = va_arg(ap, unsigned);
			printf("%u", uval);
			break;
		case 'f':
		case 'e':
		case 'E':
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			sprintf(minfmt,"%%%c",*p);
			sprintf(back, minfmt, dval);
			break;
		case 'p':
			sprintf(back, "%p", va_arg(ap, void *));
			break;
		case 's':
			sval = va_arg(ap, char*);
			if (strlen(sval) > perc)
				sval[perc] = '\0';
			sprintf(back,"%s",sval);
			break;
		default:
			sprintf(back,"%c",*p);
			break;
		}
		for (int i=strlen(back);i<fldwd;i++) 
			/*if fldwd is ≤ than strlen(back)
			 inc. if it negative, than nop */
			putchar(' ');
		printf("%s",back);
		for (int i=strlen(back);i<(-fldwd);i++) 
			/*Again but the opposite.*/
			 putchar(' ');

	}
	va_end(ap); /* clean up when done */
}
