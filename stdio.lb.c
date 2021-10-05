// Ritchie, D.M. and Kernighan, B.W. (1988) p157-158

#include <fcntl.h>
#include <unistd.h>

#include "stdio.lb.h"

#define PERMS 0666 /* RW for owner, group, others */

FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;
	
	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
	{	if ((fp->flag & (_READ | _WRITE)) == 0)
			break; /* found free slot */
	}
	if (fp >= _iob + OPEN_MAX) /* no free slots */
		return NULL;
	
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') 
	{	if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	
	if (fd == -1) /* couldn't access name */
		return NULL;
	
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}

FILE *fopen_fld(char *name, char *mode)
{
	int fd;
	FILE *fp;
	
	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
	{	if ((fp->flgfld.read | fp->flgfld.write) == 0)
			break; /* found free slot */
	}
	if (fp >= _iob + OPEN_MAX) /* no free slots */
		return NULL;
	
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') 
	{	if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	
	if (fd == -1) /* couldn't access name */
		return NULL;
	
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	(*mode == 'r') ? (fp->flgfld.read = 1) : (fp->flgfld.write = 1);
	return fp;
}

void *malloc(size_t size);

int _fillbuf(FILE *fp)
{  /* allocate and fill input buffer */
	int bufsize;
	if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
		return EOF;
	
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) /* no buffer yet */
	{	if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	}
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	
	if (--fp->cnt < 0) 
	{	if (fp->cnt == -1)
			fp->flag|= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

int _fillbuf_fld(FILE *fp)
{  /* allocate and fill input buffer */
	int bufsize;
	if (!(fp->flgfld.read) || (fp->flgfld.err) || (fp->flgfld.eof))
		return EOF;
	
	bufsize = (fp->flgfld.unbuf) ? 1 : BUFSIZ;
	if (fp->base == NULL) /* no buffer yet */
	{	if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	}
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	
	if (--fp->cnt < 0) 
	{	if (fp->cnt == -1)
			fp->flgfld.eof = 1;
		else
			fp->flgfld.err = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

int _flushbuf(int c, FILE *fp)
{
	if ((fp->flag&(_WRITE|_ERR)) != _WRITE)
		return EOF;
	if (fp->base == NULL)
		return EOF;
	int len = 
	if (fp->cnt < 0 || fp->cnt > BUFSIZ)
		if (fp->cnt == -1)
			fp->flag|= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF; 
	fp->ptr
	int back = write(fp->fd, fp->base, fp->cnt);

}

FILE _iob[OPEN_MAX] = 
{	/* stdin, stdout, stderr */
	{ 0, (char *) 0, (char *) 0, _READ, 0            },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1           },
	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
