/*
now we ask malloc for an integer as in try.c 
and we go into the morecore algorithm
*/

__brk=0x7fffff6c73e0
Header base, *freep = NULL;
&base in [1,0x11]
base.s = {.ptr=0, .size=0}

malloc(4)
	nunits := (4+sizof(Header)-1)/sizeof(Header) + 1\
	= (3+0x10)/0x10 +1 = 2
	freep = NULL
	base.s.ptr := freep := prevp := &base = 1; 
	base.s.size := 0
	base.s = {.ptr=1, .size=0}
	p := prevp->s.ptr = &base
	p->s.size = 0 < nunits
	p = freep
	p := morcore(2)
		nu=2
		(char *) cp
		NALLOC = 0x400
		2< NALLOC
		nu := 0x400
		cp :=sbrk(nu * sizeof(Header) = 0x4000)
		cp = 0xfe1
		cp != -1
		up := (Header *) cp = 0xfe1
		up->s.size := nu = 0x400
		up->s= {.ptr=0, .size=0x400}
		free ((void *)(up+1(*0x10)=0xff1)) 
			void *ap = 0xff1
			Header *bp, *p
			bp := (Header *)ap -1(*0x10)=0xfe1
			p := freep = 1
			!(bp > p && bp < (p->s.ptr = p)) = !(1 && 0) = 1
			(p >= p->s.ptr && (bp > p || bp < p->s.ptr) = (1 && (1 || ...))= 1
			break
			bp + bp->s.size (*0x10) = 0xfe1 + 0x4000 = 0x4fe1\
			!= p->s.ptr = 1

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

