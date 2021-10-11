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

//original

/* flushbuf design: first call prepares buffer for writing to a file
	further calls to putc macro are decresing cnt and adding a charecter to buffer
	that means that the first call should set cnt to the buffer capacity, 
	and put the first charecter in it.
	Each next call write the buffer to the file and than reset the buffer 
	(cnt to capaciy and ptr to base), and again put the argument charecter in its start.
*/

int _flushbuf(int c, FILE *fp)
{
	
	if ((fp->flag&(_WRITE|_ERR)) != _WRITE)
		return EOF;
	
	int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)  /* no buffer yet */
	{	if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	}
	fp->cnt = write(fp->fd, fp->base,bufsize)-1; //one less for the char will be writing now.
		
	if (fp->cnt < 0)
	{	if (fp->cnt == -1)
			fp->flag|= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF; 
	}
	fp->ptr = fp->base;
	*fp->ptr++ = c;
	return *fp->ptr;

}

int fflush(FILE *fp)
{
	
	if (fp == NULL)
	{	int back=0;
		for (FILE *ff=stdout;(ff-_iob)<OPEN_MAX;ff++)
		{	if (ff->flag&(_WRITE))
				back |= fflush(ff);
		}
		return back;
	}
	if (fp->base == NULL || (fp->flag & _WRITE) == 0)
		return EOF;
	
	fp->cnt = 0; // restart buf size
	*fp->ptr = '\0'; //null termination
	int len = (fp->ptr-fp->base); //finding length of buffered str
	fp->ptr = fp->base; //restart buf pointer
	
	return (write(fp->fd,fp->base,len) == len) \
	? 0 : EOF;
}

void free(void *);

int fclose(FILE *fp)
{
	
	free(fp->base); //free the buffer
	fp->cnt=fp->flag=fp->fd=0;
	fp->ptr= fp->base = NULL;
	return 0;
}

int fseek(FILE *fp, long offset, int origin)
{	
	//buffer maintanace
	if (fp->flag & _WRITE)
		fflush(fp);
	else if (fp->flag & _READ)
	{	//fflush will reset it anyway
		fp->cnt = 0;
		fp->ptr = fp->base;
	}
	else
		return 2;
	
	return (lseek(fp->fd, offset, origin) < 0);

}

FILE _iob[OPEN_MAX] = 
{	/* stdin, stdout, stderr */
	{ 0, (char *) 0, (char *) 0, _READ, 0,          },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1,         },
	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
