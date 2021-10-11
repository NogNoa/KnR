/* in x86_64 systems long long is 8 bytes, like long, and long doubles are 16 bytes. 
It's possible there are other factors for being "restrictive", 
but for the sake of excercise let's go with that
*/

#include <stddef.h>

// Ritchie, D.M. and Kernighan, B.W. (1988) p165-166
//fixed

typedef long double Align; /* for alignment to long double boundary */

union header 
{  /* block header */
	struct 
	{	union header *ptr; /* next block if on free list */
		size_t size; /* size of this block */
	} s;
	Align x; /* force alignment of blocks */
};

typedef union header Header;

static Header base; /* empty list to get started */
static Header *freep = NULL; /* start of free list */

static Header *morecore(unsigned nu);

void *malloc(long unsigned nbytes)
{  /* general-purpose storage allocator */
	Header *p, *prevp;
	unsigned nunits;
	
	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
	if (freep == NULL) 
	{  /* no free list yet */
		base.s.ptr = freep = &base;
		base.s.size = 0;
	}
	prevp = freep;
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) 
	{	if (p->s.size >= nunits) 
		{  /* big enough */
			if (p->s.size == nunits) /* exactly */
				prevp->s.ptr = p->s.ptr;
			else 
			{  /* allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}
		if (p == freep) /* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL; /* none left */
	}
}

/*
base always have size 0, while the tail get all the 
space allocated from morecore. small segments of this are 
given to each block that is returned, this metadata is then
invisible while the memory is in use, but it is retained for when
free() will be called. this is while p+1 is returned, p points to the header
itself which is all that interesting to this module, but is boring to the outside
world 
*/


#define NALLOC 1024 /* minimum #units to request */

void free(void *ap);

static Header *morecore(unsigned nu)
{ /* ask system for more memory */
	char *cp; 
	Header *up;
	
	char *sbrk(int);
	
	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) -1) /* no space at all */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free((void *)(up+1)); 
	/* cheaky way to put up in the linked list
	normaly the pointer of the content is given
	which is one after the pointer of the header */
	return freep;
}


void free(void *ap)
{  /* put block ap in free list */
	Header *bp, *p;
	
	bp = (Header *)ap - 1; /* point to block header */
	//finds p such that order of it bp and S(p) is desireable
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break; /* freed block at start or end of arena */
	if (bp + bp->s.size == p->s.ptr) 
	{  //join S(p) into bp
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
		//put bp before S(p)
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) 
	{  // join bp into p
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		//put p before bp instead of S(p)
		p->s.ptr = bp;
	freep = p;
}


/*there are six orderings
for the sake of shorteness
s = p->s.ptr
[p, bp, s], [bp, s, p], [s, p, bp] break
[bp, p, s], [s, bp, p], [p, s, bp] continue
thogh there are more with the equality cases
*/
