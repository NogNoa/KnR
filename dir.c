#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

#include <sys/dir.h> /* local directory structure */

typedef struct 
{ /* portable directory entry */
	long ino; /* inode number */
	char name[NAME_MAX+1]; /* name + '\0' terminator */
} Dirent;


int fstat(int fd, struct stat *);


DIR *opendir(const char *dirname)
{  /* opendir: open a directory for readdir calls */
	int fd;
	struct stat stbuf;

	DIR *dp;
	if ((fd = open(dirname, O_RDONLY, 0)) == -1
	   || fstat(fd, &stbuf) == -1
	   || (stbuf.st_mode & S_IFMT) != S_IFDIR
	   || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}


void closedir(DIR *dp)
{  /* closedir: close directory opened by opendir */
	if (dp) 
	{	close(dp->fd);
		free(dp);
	}
}


Dirent *readdir(DIR *dp)
{  /* readdir: read directory entries in sequence */
	struct direct dirbuf; /* local directory structure */
	static Dirent d; /* return: portable structure */
	
	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
	      == sizeof(dirbuf)) 
	{	if (dirbuf.d_ino == 0) /* slot not in use */
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0'; /* ensure termination */
		return &d;
	}
	return NULL;
}