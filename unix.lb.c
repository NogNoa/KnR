#include <stdio.h>
#include <unistd.h>

// Ritchie, D.M. and Kernighan, B.W. (1988) p153-155

int KnR_getchar(int inf)
{	/* simple buffered version */
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;
	
	if (n == 0) 
	{ /* buffer is empty */
		n = read(inf, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

#include <stdarg.h>
#include <stdlib.h>

void error(char *fmt, ...)
{  /* print an error message and die */
	va_list args;
	va_start(args  , fmt      );
	fprintf (stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf (stderr, "\n"     );
	va_end  (             args);
	exit(1);
}

//original
int alt_putchar(char c, int outf)
{
	static char buf[BUFSIZ];
	static int n = 0;
	static int soutf = 1;

	if (n > BUFSIZ)
		error("stack has overflowed");
	else if (n == BUFSIZ || c == EOF || soutf != outf)
	{	write(outf, buf, sizeof buf);
		n = 0;
	}
	if (soutf != outf)
		soutf = outf;
	if (c == EOF)
		return EOF;
	else
		return (buf[n++] = c);
}

#include <fcntl.h>

#define PERMS 0666 /* RW for owner, group, others */

int cp (int argc, char *argv[])
{ /* cp: copy f1 to f2 */
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3)
	{	error("Usage: cp from to");
	}
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
	{	error("cp: can't open %s", argv[1]);
	}
	if ((f2 = creat(argv[2], PERMS)) == -1)
	{	error("cp: can't create %s, mode %03o",
		argv[2], PERMS);
	}
	while ((n = read(f1, buf, BUFSIZ)) > 0)
	{	if (write(f2, buf, n) != n)
		{	error("cp: write error on file %s", argv[2]);
		}
	}
	return 0;
}
