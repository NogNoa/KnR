/*
now we ask malloc for an integer as in try.c 
and we go into the morecore algorithm
*/

__brk=0x7fffff6c73e0
Header base, *freep = NULL;
&base in [1,17]
base.s = {.ptr=0, .size=0}

malloc(4)
	nunits := (4+sizof(Header)-1)/sizeof(Header) + 1\
	= (3+16)/16 +1 = 2
	freep = NULL
	base.s.ptr := freep := prevp := &base = 1; 
	base.s.size := 0
	base.s = {.ptr=1, .size=0}
	p := prevp->s.ptr = &base
	p->s.size = 0 < nunits
	p = freep
	p := morcore(2) 
		(char *) cp
		NALLOC = 1024
		2< NALLOC
		2 := 1024
		cp :=sbrk(nu * sizeof(Header) = 32)
		cp = 4065 (=0xfe0+1)
		cp != -1
		up := (Header *) cp = 4065
		up->s.size := nu = 2
		free ((void *)(up+1(*16)=4081)) 

	there is space [1,49]
	p->s.ptr = base.s.ptr = 17
	base.s.ptr->s.size = 32
	prevp := p = 1
	p := p->s.ptr = 17
	p->s.size = 32 >= 2
	p->s.size -= 2 = 30
	p += (p->s.size (*16) = 32 * 16) = 512 
	p->s.size := 2
	freep := prevp = &base
	return (void*) (512 + 16 = 528)

