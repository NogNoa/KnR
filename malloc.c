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


#define NALLOC 1024 /* minimum #units to request */

void free(void *ap);

static Header *morecore(unsigned nu)
{ /* ask system for more memory */
	char *cp, *sbrk(int);
	Header *up;
	
	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) -1) /* no space at all */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free((void *)(up+1));
	return freep;
}


void free(void *ap)
{  /* put block ap in free list */
	Header *bp, *p;
	
	bp = (Header *)ap - 1; /* point to block header */
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break; /* freed block at start or end of arena */
	if (bp + bp->s.size == p->s.ptr) 
	{  /* join to upper nbr */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
	bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) 
	{  /* join to lower nbr */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
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
