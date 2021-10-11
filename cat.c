#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error(char *fmt, ...);

#define STDIN 0
#define STDOUT 1

// Ritchie, D.M. and Kernighan, B.W. (1988) p144-145
//original

void main(int argc, char *argv[])
{ /*print files, concatenating them*/
	int scroll;
	void filecopy(int, int);
	char *prog = argv[0]; /* program name for errors */
	
	if (argc == 1 ) /* no args; copy standard input */
		filecopy(STDIN, STDOUT);
	else
		while (--argc > 0)
			if ((scroll = open(*++argv, O_RDONLY, 0)) == EOF)
			{	error("%s: can't open %s\n",
				prog, *argv);
				exit(1);
			} 
			else
			{	filecopy(scroll, STDOUT);
				close(scroll);
			}
	if (ferror(stdout)) {
		error("%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

void filecopy(int inf, int outf)
{ /*copy file ifp to file ofp */
	char buf[BUFSIZ];
	int n;
	
	while ((n = read(inf, buf, BUFSIZ)) > 0)
		write(outf, buf, n);
}
