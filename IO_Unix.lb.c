// Ritchie, D. and Kernighan, W. (1988) p128

#ifndef va_list
	#include <stdarg.h>
#endif
#ifndef putchar
	#include <stdio.h>
#endif


void minprintf(char *fmt, ...)
{  /* minprintf: minimal printf with variable argument list */
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval, minfmt[3];
	int ival;
	unsigned uval;
	double dval;
	
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') 
		{	putchar(*p);
			continue;
		}
		
		switch (*++p)
		{case 'd':
		case 'i':
		case 'x':
		case 'X':
		case 'o':
			ival = va_arg(ap, int);
			sprintf(minfmt,"%%%c",*p);
			printf(minfmt, ival);
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
			printf(minfmt, dval);
			break;
		case 'p':
			printf("%p", va_arg(ap, void *));
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); /* clean up when done */
}
