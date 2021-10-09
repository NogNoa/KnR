// Ritchie, D.M. and Kernighan, B.W. (1988) p161
//ported and fixed

#include <stdio.h>
#include <string.h>
#include <fcntl.h> /* flags for read and write */
//#include <sys/types.h> /* typedefs */
#include <sys/stat.h> /* structure returned by stat */
#include <dirent.h>

void fsize(char *);

int main(int argc, char **argv)
{  /* print file name */
	if (argc == 1) /* default: current directory */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}


void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name)
{  /* print the size of file "name" */
	struct stat stbuf;
	if (stat(name, &stbuf) == -1) 
	{	fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8ld %ld %ld.%ld %s\n", stbuf.st_size, stbuf.st_dev, stbuf.st_atim.tv_sec,stbuf.st_atim.tv_nsec, name);
	//It's obvious how to add the rest by refering to ./algorithms/fsize libraries.txt. But the line will get pretty long
}


#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{  /* apply fcn to all files in dir */
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;
	if ((dfd = opendir(dir)) == NULL) 
	{	fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = readdir(dfd)) != NULL) 
	{	if (strcmp(dp->d_name,  ".") == 0
		||  strcmp(dp->d_name, "..") == 0)
			continue; /* skip self and parent */
		if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
		{	fprintf(stderr, "dirwalk: name %s %s too long\n",
			dir, dp->d_name);
		}
		else 
		{	sprintf(name, "%s/%s", dir, dp->d_name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}
