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

static Header stat_base; /* empty list to get started */
static Header *dyn_basep = NULL; /* start of free list */

static Header *morecore(unsigned nu);

void *KnR_malloc(long unsigned nbytes)
{  /* general-purpose storage allocator */
	Header *p, *prevp; //p to the header of the block to be allocated
	unsigned nunits;
	
	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
	if (dyn_basep == NULL) 
	{  /* no free list yet */
		stat_base.s.ptr = dyn_basep = &stat_base;
		stat_base.s.size = 0;
	}
	prevp = dyn_basep;
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
			dyn_basep = prevp;
			return (void *)(p+1);
		}
		if (p == dyn_basep) /* wrdatapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL; /* none left */
	}
}

/*
stat_base always have size 0, while the tail get all the 
space allocated from morecore. small segments of this are 
given to each block that is returned, this metadata is then
invisible while the memory is in use, but it is retained for when
free() will be called. this is while p+1 is returned, p points to the header
itself which is all that interesting to this module, but is boring to the outside
world 
*/


#define NALLOC 1024 /* minimum #units to request */

void free(void *datap);
char *sbrk(int);

static Header *morecore(unsigned nu)
{ /* ask system for more memory */
	char *charp; 
	Header *freshp; //pointer for the asked for memory
	
	if (nu < NALLOC)
		nu = NALLOC;
	charp = sbrk(nu * sizeof(Header));
	if (charp == (char *) -1) /* no space at all */
		return NULL;
	freshp = (Header *) charp;
	freshp->s.size = nu;
	free((void *)(freshp+1)); 
	/* cheaky way to put freshp in the linked list
	normaly the pointer of the content is given
	which is one after the pointer of the header */
	return dyn_basep;
}


void free(void *datap)
{  /* put block datap in free list */
	Header *freedp, *p;
	
	freedp = (Header *)datap - 1; /* point to block header */
	/*finds p such that order of it freedp and S(p) is desirea. look below */ 
	for (p = dyn_basep; !(freedp > p && freedp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (freedp > p || freedp < p->s.ptr))
			break; /* freed block at start or end of arena */
	if (freedp + freedp->s.size == p->s.ptr) 
	{  //join S(p) into freedp
		freedp->s.size += p->s.ptr->s.size;
		freedp->s.ptr = p->s.ptr->s.ptr;
	} else
		//link freedp to S(p)
		freedp->s.ptr = p->s.ptr;
	if (p + p->s.size == freedp) 
	{  // join freedp into p
		p->s.size += freedp->s.size;
		p->s.ptr = freedp->s.ptr;
	} else
		//link p to freedp instead of S(p)
		p->s.ptr = freedp;
	dyn_basep = p;
}


/*there are six orderings
for the sake of shorteness:
s = p->s.ptr
f = freedp
[p, f, s], [f, s, p], [s, p, f] break
[f, p, s], [s, f, p], [p, s, f] continue
thogh there are more with the equality cases
more precisely:
p <  f <  s,  f <= s <= p,  s <= p <  f  break
f <= p <  s,  s <= f <= p,  p <= s <= f  continue
*/
