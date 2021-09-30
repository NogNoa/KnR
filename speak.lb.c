// Ritchie, D.M. and Kernighan, B.W. (1988) p128

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
	char *p, *sval,back[0200], temp[4]="%";
	int pnt_pntae;
	long int ival;
	unsigned long uval;
	double dval;
	;
	
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) 
	{	int fldwd=0;
		unsigned prec=~0;
		char minfmt[5]="%";
		
		if (*p != '%') 
		{	putchar(*p);
			continue;
		}

		sscanf(++p,"%d",&fldwd);
		while(isdigit(*p) || *p=='-')
			p++;
		if (*p == '.')
		{	sscanf(++p,"%u",&prec);
			while(isdigit(*p) || *p=='-')
				p++;
		}

		if (*p == 'l' || *p == 'h')
			sprintf(minfmt,"%%%c",*p);

		switch (*p)
		{case 'd':
		case 'i':
			ival = va_arg(ap, int);
			strcpy(temp,minfmt);
			sprintf(minfmt,"%s%c",temp,*p);
			sprintf(back, minfmt, ival);
			break;
		case 'u':
		case 'x':
		case 'X':
		case 'o':
			uval = va_arg(ap, unsigned);
			strcpy(temp,minfmt);
			sprintf(minfmt,"%s%c",temp,*p);
			sprintf(back,minfmt, uval);
			break;
		case 'f':
		case 'e':
		case 'E':
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			sprintf(minfmt,"%%%c",*p);
			sprintf(back, minfmt, dval);
			for (pnt_pntae=0; back[pnt_pntae] && back[pnt_pntae++] != '.';)
				; //++ intentionaly in the middle part of for
			if(strlen(back)-pnt_pntae > prec)
				back[pnt_pntae+prec] = '\0';
			break;
		case 'p':
			sprintf(back, "%p", va_arg(ap, void *));
			break;
		case 's':
			sval = va_arg(ap, char*);
			if (strlen(sval) > prec)
				sval[prec] = '\0';
			sprintf(back,"%s",sval);
			break;
		case 'c':
			sprintf(back,"%c",va_arg(ap, int));
		default:
			sprintf(back,"%c",*p);
			break;
		}
		for (int i=strlen(back);i<fldwd;i++) 
			/*if fldwd is ≤ than strlen(back)
			 inc. if it negative, than nop */
			putchar(' ');
		puts(back);
		for (int i=strlen(back);i<(-fldwd);i++) 
			/*Again but the opposite.*/
			 putchar(' ');

	}
	va_end(ap); /* clean up when done */
}

/* fputs: put string s on file iop */
int KnR_fputs(char *s, FILE *iop)
{
	int c;
	while ((c = *s++))
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}
