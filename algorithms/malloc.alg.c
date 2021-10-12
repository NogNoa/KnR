/*
now we ask malloc for an integer as in try.c 
and we go into the morecore algorithm
*/

__brk=0x7fffff6c73e0
Header base, *freep = NULL;
&base in [1,0x11]
base.s = {.ptr=0, .size=0}

base->base

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
		cp = 0x1000 
		/* actually it was alligned from 0x8004020 to 800500
		adding 0xfe1. no reason to no align it myself for my
		convenience*/
		cp != -1
		up := (Header *) cp = 0x1000
		up->s.size := nu = 0x400
		up->s= {.ptr=0, .size=0x400}
		free ((void *)(up+1(*0x10)=0x1010)) 
			void *ap = 0x1010
			Header *bp, *p
			bp := (Header *)ap -1(*0x10)=0x1000
			p := freep = 1
			!(bp > p && bp < (p->s.ptr = p)) = !(1 && 0) = 1
			(p >= p->s.ptr && (bp > p || bp < p->s.ptr) = (1 && (1 || ...))= 1
			break
			bp + bp->s.size (*0x10) = 0x1000 + 0x4000 = 0x5000\
			!= p->s.ptr = 1
			bp->s.ptr = p->s.ptr = 1
			(bp=0x1000)->s={.ptr=1, .size=0400}
			p + p->s.size = 1 + 0 =1 != bp
			p->s.ptr = bp
			(p=1)->s = {.ptr=0x1000=bp, .size=0}
			freep = p
		(up=0x1000)->s = {.ptr=1=&base, .size=0400}
		base->0x1000->base
		//base=freep leads to up and back
		return freep
	effective space is [1,0x1021]
	one block at 1 and one at 0x1000
	p->s = {.ptr=0x1000, .size=0} != NULL
	base.s = p->s
	prevp := p = 1
	p := p->s.ptr = 0x1000
	p->s.size = 0x400 > 2
	p->s.size -= 2 = 0x3fe
	p += (p->s.size (*0x10) = 0x3fe * 0x10 =  0x3fe0) = 0x4fe0
	effective space is [1,0x5001]
	p->s.size := 2
	(p=0x4fe0)->s={.ptr=0, .size=2}
	freep := prevp = &base
	return (void*) (0x4fe0 + 1 * (0x10) = 0x4ff0)
a = 0x4ff0
base->0x1000->base
b := malloc(4)
	nunits := 2
	freep = 1 != NULL
	prevp := freep = &base
	p := prevp->s.ptr = 0x1000
	p->s.size = 0x3fe > nunits
	p->s.size -= nunit = 0x3fe - 2 = 0x3fc
	p += (p->s.size (*0x10) = 0x3fc0) = 0x4fc0
	p->s.size = nunits = 2
	freep := prevp = &base
	return (void*) (0x4fd0)
b = 0x4fd0
free(a)
	void *ap = 0x4ff0
	bp := (Header *)ap -1(*0x10)=0x4fe0
	p := freep = &base
	&base->s.ptr= 0x1000
	!(bp > p && bp < p->s.ptr) = !(1 && 0) = 1
	(p >= p->s.ptr && (bp > p || bp < p->s.ptr) = (0 && ...)= 0
	p:= p->s.ptr = 0x1000
	p->s.ptr = 1
	!(bp > p && bp < p->s.ptr) = !(1 && 0) = 1
	(p >= p->s.ptr && (bp > p || bp < p->s.ptr) = (1 && (1 || ...))= 1
	break
	bp + bp->s.size (*0x10) = 0x4fe0 + 0x20 = 0x5000\
	!= p->s.ptr = 1
	bp->s.ptr = p->s.ptr = 1
	(bp=0x4fe0)->s={.ptr=1, .size=0x20}
	p + p->s.size = 0x1000 + 0x3fc (*10) =0x4fc0 != bp=0x4fe0
	p->s.ptr = bp
	(p=0x1000)->s = {.ptr=0x4fe0=bp, .size=0}
	freep = p
base->0x1000->0x4fe0->base
b := malloc(4)
	nunits := 2
	freep = 0x1000 != NULL
	prevp := freep = 0x1000
	p := prevp->s.ptr = 0x4fe0
	p->s.size = 0x20 > nunits
	p->s.size -= nunit = 0x20 - 2 = 0x18
	p += (p->s.size (*0x10) = 0x180) = 0x4fe0 + 0x180 = 0x5160
	p->s.size = nunits = 2
	(p=0x5160)->s = {.pnt=0, .size=2}
	freep := prevp = &base
	return (void*) (0x4fd0)
	
	
