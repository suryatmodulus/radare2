
static char *get_reg_profile(RAnal *anal) {
	const char *p;
	if (anal->bits == 64) {
		p = \
		"=PC	pc\n"
		"=SP	sp\n"
		"=BP	x29\n"
		"=A0	x0\n"
		"=A1	x1\n"
		"=A2	x2\n"
		"=A3	x3\n"
		"=ZF	zf\n"
		"=SF	nf\n"
		"=OF	vf\n"
		"=CF	cf\n"
		"=SN	x16\n" // x8 on linux?

		/* 8bit sub-registers */
		"fpu	b0	.8	0	0\n"
		"fpu	b1	.8	8	0\n"
		"fpu	b2	.8	16	0\n"
		"fpu	b3	.8	24	0\n"
		"fpu	b4	.8	32	0\n"
		"fpu	b5	.8	40	0\n"
		"fpu	b6	.8	48	0\n"
		"fpu	b7	.8	56	0\n"
		"fpu	b8	.8	64	0\n"
		"fpu	b9	.8	72	0\n"
		"fpu	b10	.8	80	0\n"
		"fpu	b11	.8	88	0\n"
		"fpu	b12	.8	96	0\n"
		"fpu	b13	.8	104	0\n"
		"fpu	b14	.8	112	0\n"
		"fpu	b15	.8	120	0\n"
		"fpu	b16	.8	128	0\n"
		"fpu	b17	.8	136	0\n"
		"fpu	b18	.8	144	0\n"
		"fpu	b19	.8	152	0\n"
		"fpu	b20	.8	160	0\n"
		"fpu	b21	.8	168	0\n"
		"fpu	b22	.8	176	0\n"
		"fpu	b23	.8	184	0\n"
		"fpu	b24	.8	192	0\n"
		"fpu	b25	.8	200	0\n"
		"fpu	b26	.8	208	0\n"
		"fpu	b27	.8	216	0\n"
		"fpu	b28	.8	224	0\n"
		"fpu	b29	.8	232	0\n"
		"fpu	b30	.8	240	0\n"
		"fpu	bsp	.8	248	0\n"

		/* 16bit sub-registers */
		"fpu	h0	.16	0	0\n"
		"fpu	h1	.16	8	0\n"
		"fpu	h2	.16	16	0\n"
		"fpu	h3	.16	24	0\n"
		"fpu	h4	.16	32	0\n"
		"fpu	h5	.16	40	0\n"
		"fpu	h6	.16	48	0\n"
		"fpu	h7	.16	56	0\n"
		"fpu	h8	.16	64	0\n"
		"fpu	h9	.16	72	0\n"
		"fpu	h10	.16	80	0\n"
		"fpu	h11	.16	88	0\n"
		"fpu	h12	.16	96	0\n"
		"fpu	h13	.16	104	0\n"
		"fpu	h14	.16	112	0\n"
		"fpu	h15	.16	120	0\n"
		"fpu	h16	.16	128	0\n"
		"fpu	h17	.16	136	0\n"
		"fpu	h18	.16	144	0\n"
		"fpu	h19	.16	152	0\n"
		"fpu	h20	.16	160	0\n"
		"fpu	h21	.16	168	0\n"
		"fpu	h22	.16	176	0\n"
		"fpu	h23	.16	184	0\n"
		"fpu	h24	.16	192	0\n"
		"fpu	h25	.16	200	0\n"
		"fpu	h26	.16	208	0\n"
		"fpu	h27	.16	216	0\n"
		"fpu	h28	.16	224	0\n"
		"fpu	h29	.16	232	0\n"
		"fpu	h30	.16	240	0\n"

		/* 32bit sub-registers */
		"gpr	w0	.32	0	0\n"
		"gpr	w1	.32	8	0\n"
		"gpr	w2	.32	16	0\n"
		"gpr	w3	.32	24	0\n"
		"gpr	w4	.32	32	0\n"
		"gpr	w5	.32	40	0\n"
		"gpr	w6	.32	48	0\n"
		"gpr	w7	.32	56	0\n"
		"gpr	w8	.32	64	0\n"
		"gpr	w9	.32	72	0\n"
		"gpr	w10	.32	80	0\n"
		"gpr	w11	.32	88	0\n"
		"gpr	w12	.32	96	0\n"
		"gpr	w13	.32	104	0\n"
		"gpr	w14	.32	112	0\n"
		"gpr	w15	.32	120	0\n"
		"gpr	w16	.32	128	0\n"
		"gpr	w17	.32	136	0\n"
		"gpr	w18	.32	144	0\n"
		"gpr	w19	.32	152	0\n"
		"gpr	w20	.32	160	0\n"
		"gpr	w21	.32	168	0\n"
		"gpr	w22	.32	176	0\n"
		"gpr	w23	.32	184	0\n"
		"gpr	w24	.32	192	0\n"
		"gpr	w25	.32	200	0\n"
		"gpr	w26	.32	208	0\n"
		"gpr	w27	.32	216	0\n"
		"gpr	w28	.32	224	0\n"
		"gpr	w29	.32	232	0\n"
		"gpr	w30	.32	240	0\n"
		"gpr	wsp	.32	248	0\n"
		"gpr	wzr	.32	?	0\n"

		/* 32bit float sub-registers */
		"fpu	s0	.32	288	0\n"
		"fpu	s1	.32	304	0\n"
		"fpu	s2	.32	320	0\n"
		"fpu	s3	.32	336	0\n"
		"fpu	s4	.32	352	0\n"
		"fpu	s5	.32	368	0\n"
		"fpu	s6	.32	384	0\n"
		"fpu	s7	.32	400	0\n"
		"fpu	s8	.32	416	0\n"
		"fpu	s9	.32	432	0\n"
		"fpu	s10	.32	448	0\n"
		"fpu	s11	.32	464	0\n"
		"fpu	s12	.32	480	0\n"
		"fpu	s13	.32	496	0\n"
		"fpu	s14	.32	512	0\n"
		"fpu	s15	.32	528	0\n"
		"fpu	s16	.32	544	0\n"
		"fpu	s17	.32	560	0\n"
		"fpu	s18	.32	576	0\n"
		"fpu	s19	.32	592	0\n"
		"fpu	s20	.32	608	0\n"
		"fpu	s21	.32	624	0\n"
		"fpu	s22	.32	640	0\n"
		"fpu	s23	.32	656	0\n"
		"fpu	s24	.32	672	0\n"
		"fpu	s25	.32	688	0\n"
		"fpu	s26	.32	704	0\n"
		"fpu	s27	.32	720	0\n"
		"fpu	s28	.32	736	0\n"
		"fpu	s29	.32	752	0\n"
		"fpu	s30	.32	768	0\n"
		"fpu	s31	.32	784	0\n"

		/* 64bit */
		"gpr	x0	.64	0	0\n" // x0
		"gpr	x1	.64	8	0\n" // x0
		"gpr	x2	.64	16	0\n" // x0
		"gpr	x3	.64	24	0\n" // x0
		"gpr	x4	.64	32	0\n" // x0
		"gpr	x5	.64	40	0\n" // x0
		"gpr	x6	.64	48	0\n" // x0
		"gpr	x7	.64	56	0\n" // x0
		"gpr	x8	.64	64	0\n" // x0
		"gpr	x9	.64	72	0\n" // x0
		"gpr	x10	.64	80	0\n" // x0
		"gpr	x11	.64	88	0\n" // x0
		"gpr	x12	.64	96	0\n" // x0
		"gpr	x13	.64	104	0\n" // x0
		"gpr	x14	.64	112	0\n" // x0
		"gpr	x15	.64	120	0\n" // x0
		"gpr	x16	.64	128	0\n" // x0
		"gpr	x17	.64	136	0\n" // x0
		"gpr	x18	.64	144	0\n" // x0
		"gpr	x19	.64	152	0\n" // x0
		"gpr	x20	.64	160	0\n" // x0
		"gpr	x21	.64	168	0\n" // x0
		"gpr	x22	.64	176	0\n" // x0
		"gpr	x23	.64	184	0\n" // x0
		"gpr	x24	.64	192	0\n" // x0
		"gpr	x25	.64	200	0\n" // x0
		"gpr	x26	.64	208	0\n" // x0
		"gpr	x27	.64	216	0\n"
		"gpr	x28	.64	224	0\n"
		"gpr	x29	.64	232	0\n"
		"gpr	x30	.64	240	0\n"
		"gpr	tmp	.64	800	0\n"

		/* 64bit double */
		"fpu	d0	.64	288	0\n"
		"fpu	d1	.64	304	0\n"
		"fpu	d2	.64	320	0\n"
		"fpu	d3	.64	336	0\n"
		"fpu	d4	.64	352	0\n"
		"fpu	d5	.64	368	0\n"
		"fpu	d6	.64	384	0\n"
		"fpu	d7	.64	400	0\n"
		"fpu	d8	.64	416	0\n"
		"fpu	d9	.64	432	0\n"
		"fpu	d10	.64	448	0\n"
		"fpu	d11	.64	464	0\n"
		"fpu	d12	.64	480	0\n"
		"fpu	d13	.64	496	0\n"
		"fpu	d14	.64	512	0\n"
		"fpu	d15	.64	528	0\n"
		"fpu	d16	.64	544	0\n"
		"fpu	d17	.64	560	0\n"
		"fpu	d18	.64	576	0\n"
		"fpu	d19	.64	592	0\n"
		"fpu	d20	.64	608	0\n"
		"fpu	d21	.64	624	0\n"
		"fpu	d22	.64	640	0\n"
		"fpu	d23	.64	656	0\n"
		"fpu	d24	.64	672	0\n"
		"fpu	d25	.64	688	0\n"
		"fpu	d26	.64	704	0\n"
		"fpu	d27	.64	720	0\n"
		"fpu	d28	.64	736	0\n"
		"fpu	d29	.64	752	0\n"
		"fpu	d30	.64	768	0\n"
		"fpu	d31	.64	784	0\n"

		/* 128 bit vector */
		"fpu	v0	.128	288	0\n"
		"fpu	v1	.128	304	0\n"
		"fpu	v2	.128	320	0\n"
		"fpu	v3	.128	336	0\n"
		"fpu	v4	.128	352	0\n"
		"fpu	v5	.128	368	0\n"
		"fpu	v6	.128	384	0\n"
		"fpu	v7	.128	400	0\n"
		"fpu	v8	.128	416	0\n"
		"fpu	v9	.128	432	0\n"
		"fpu	v10	.128	448	0\n"
		"fpu	v11	.128	464	0\n"
		"fpu	v12	.128	480	0\n"
		"fpu	v13	.128	496	0\n"
		"fpu	v14	.128	512	0\n"
		"fpu	v15	.128	528	0\n"
		"fpu	v16	.128	544	0\n"
		"fpu	v17	.128	560	0\n"
		"fpu	v18	.128	576	0\n"
		"fpu	v19	.128	592	0\n"
		"fpu	v20	.128	608	0\n"
		"fpu	v21	.128	624	0\n"
		"fpu	v22	.128	640	0\n"
		"fpu	v23	.128	656	0\n"
		"fpu	v24	.128	672	0\n"
		"fpu	v25	.128	688	0\n"
		"fpu	v26	.128	704	0\n"
		"fpu	v27	.128	720	0\n"
		"fpu	v28	.128	736	0\n"
		"fpu	v29	.128	752	0\n"
		"fpu	v30	.128	768	0\n"
		"fpu	v31	.128	784	0\n"

		/* 64bit double */
		"fpu	v0l		.64	288	0\n"
		"fpu	v1l		.64	304	0\n"
		"fpu	v2l		.64	320	0\n"
		"fpu	v3l		.64	336	0\n"
		"fpu	v4l		.64	352	0\n"
		"fpu	v5l		.64	368	0\n"
		"fpu	v6l		.64	384	0\n"
		"fpu	v7l		.64	400	0\n"
		"fpu	v8l		.64	416	0\n"
		"fpu	v9l		.64	432	0\n"
		"fpu	v10l	.64	448	0\n"
		"fpu	v11l	.64	464	0\n"
		"fpu	v12l	.64	480	0\n"
		"fpu	v13l	.64	496	0\n"
		"fpu	v14l	.64	512	0\n"
		"fpu	v15l	.64	528	0\n"
		"fpu	v16l	.64	544	0\n"
		"fpu	v17l	.64	560	0\n"
		"fpu	v18l	.64	576	0\n"
		"fpu	v19l	.64	592	0\n"
		"fpu	v20l	.64	608	0\n"
		"fpu	v21l	.64	624	0\n"
		"fpu	v22l	.64	640	0\n"
		"fpu	v23l	.64	656	0\n"
		"fpu	v24l	.64	672	0\n"
		"fpu	v25l	.64	688	0\n"
		"fpu	v26l	.64	704	0\n"
		"fpu	v27l	.64	720	0\n"
		"fpu	v28l	.64	736	0\n"
		"fpu	v29l	.64	752	0\n"
		"fpu	v30l	.64	768	0\n"
		"fpu	v31l	.64	784	0\n"

		/* 128 bit vector high 64 */
		"fpu	v0h		.64	296	0\n"
		"fpu	v1h		.64	312	0\n"
		"fpu	v2h		.64	328	0\n"
		"fpu	v3h		.64	344	0\n"
		"fpu	v4h		.64	360	0\n"
		"fpu	v5h		.64	376	0\n"
		"fpu	v6h		.64	392	0\n"
		"fpu	v7h		.64	408	0\n"
		"fpu	v8h		.64	424	0\n"
		"fpu	v9h		.64	440	0\n"
		"fpu	v10h	.64	456	0\n"
		"fpu	v11h	.64	472	0\n"
		"fpu	v12h	.64	488	0\n"
		"fpu	v13h	.64	504	0\n"
		"fpu	v14h	.64	520	0\n"
		"fpu	v15h	.64	536	0\n"
		"fpu	v16h	.64	552	0\n"
		"fpu	v17h	.64	568	0\n"
		"fpu	v18h	.64	584	0\n"
		"fpu	v19h	.64	600	0\n"
		"fpu	v20h	.64	616	0\n"
		"fpu	v21h	.64	632	0\n"
		"fpu	v22h	.64	648	0\n"
		"fpu	v23h	.64	664	0\n"
		"fpu	v24h	.64	680	0\n"
		"fpu	v25h	.64	696	0\n"
		"fpu	v26h	.64	712	0\n"
		"fpu	v27h	.64	728	0\n"
		"fpu	v28h	.64	744	0\n"
		"fpu	v29h	.64	760	0\n"
		"fpu	v30h	.64	776	0\n"
		"fpu	v31h	.64	792	0\n"

		/*  foo */
		"gpr	fp	.64	232	0\n" // fp = x29
		"gpr	lr	.64	240	0\n" // lr = x30
		"gpr	sp	.64	248	0\n"
		"gpr	pc	.64	256	0\n"
		"gpr	zr	.64	?	0\n"
		"gpr	xzr	.64	?	0\n"
		"flg	pstate	.64	280	0   _____tfiae_____________j__qvczn\n" // x0
		//"flg	cpsr	.32	280	0\n" //	_____tfiae_____________j__qvczn\n"
		"flg	vf	.1	280.28	0	overflow\n" // set if overflows
		"flg	cf	.1	280.29	0	carry\n" // set if last op carries
		"flg	zf	.1	280.30	0	zero\n" // set if last op is 0
		"flg	nf	.1	280.31	0	sign\n"; // msb bit of last op
	} else {
		p = \
		"=PC	r15\n"
		"=LR	r14\n"
		"=SP	sp\n"
		"=BP	fp\n"
		"=A0	r0\n"
		"=A1	r1\n"
		"=A2	r2\n"
		"=A3	r3\n"
		"=ZF	zf\n"
		"=SF	nf\n"
		"=OF	vf\n"
		"=CF	cf\n"
		"=SN	r7\n"
		"gpr	sb	.32	36	0\n" // r9
		"gpr	sl	.32	40	0\n" // rl0
		"gpr	fp	.32	44	0\n" // r11
		"gpr	ip	.32	48	0\n" // r12
		"gpr	sp	.32	52	0\n" // r13
		"gpr	lr	.32	56	0\n" // r14
		"gpr	pc	.32	60	0\n" // r15

		"gpr	r0	.32	0	0\n"
		"gpr	r1	.32	4	0\n"
		"gpr	r2	.32	8	0\n"
		"gpr	r3	.32	12	0\n"
		"gpr	r4	.32	16	0\n"
		"gpr	r5	.32	20	0\n"
		"gpr	r6	.32	24	0\n"
		"gpr	r7	.32	28	0\n"
		"gpr	r8	.32	32	0\n"
		"gpr	r9	.32	36	0\n"
		"gpr	r10	.32	40	0\n"
		"gpr	r11	.32	44	0\n"
		"gpr	r12	.32	48	0\n"
		"gpr	r13	.32	52	0\n"
		"gpr	r14	.32	56	0\n"
		"gpr	r15	.32	60	0\n"
		"flg	cpsr	.32	64	0\n"

		  // CPSR bit fields:
		  // 576-580 Mode fields (and register sets associated to each field):
		  //10000 	User 	R0-R14, CPSR, PC
		  //10001 	FIQ 	R0-R7, R8_fiq-R14_fiq, CPSR, SPSR_fiq, PC
		  //10010 	IRQ 	R0-R12, R13_irq, R14_irq, CPSR, SPSR_irq, PC
		  //10011 	SVC (supervisor) 	R0-R12, R13_svc R14_svc CPSR, SPSR_irq, PC
		  //10111 	Abort 	R0-R12, R13_abt R14_abt CPSR, SPSR_abt PC
		  //11011 	Undefined 	R0-R12, R13_und R14_und, CPSR, SPSR_und PC
		  //11111 	System (ARMv4+) 	R0-R14, CPSR, PC
		"flg	tf	.1	.517	0	thumb\n" // +5
		  // 582 FIQ disable bit
		  // 583 IRQ disable bit
		  // 584 Disable imprecise aborts flag
		"flg	ef	.1	.521	0	endian\n" // +9
		"flg	itc	.4	.522	0	if_then_count\n" // +10
		  // Reserved
		"flg	gef	.4	.528	0	great_or_equal\n" // +16
		"flg	jf	.1	.536	0	java\n" // +24
		  // Reserved
		"flg	qf	.1	.539	0	sticky_overflow\n" // +27
		"flg	vf	.1	.540	0	overflow\n" // +28
		"flg	cf	.1	.541	0	carry\n" // +29
		"flg	zf	.1	.542	0	zero\n" // +30
		"flg	nf	.1	.543	0	negative\n" // +31

		/* NEON and VFP registers */
		/* 32bit float sub-registers */
		"fpu	s0	.32	68	0\n"
		"fpu	s1	.32	72	0\n"
		"fpu	s2	.32	76	0\n"
		"fpu	s3	.32	80	0\n"
		"fpu	s4	.32	84	0\n"
		"fpu	s5	.32	88	0\n"
		"fpu	s6	.32	92	0\n"
		"fpu	s7	.32	96	0\n"
		"fpu	s8	.32	100	0\n"
		"fpu	s9	.32	104	0\n"
		"fpu	s10	.32	108	0\n"
		"fpu	s11	.32	112	0\n"
		"fpu	s12	.32	116	0\n"
		"fpu	s13	.32	120	0\n"
		"fpu	s14	.32	124	0\n"
		"fpu	s15	.32	128	0\n"
		"fpu	s16	.32	132	0\n"
		"fpu	s17	.32	136	0\n"
		"fpu	s18	.32	140	0\n"
		"fpu	s19	.32	144	0\n"
		"fpu	s20	.32	148	0\n"
		"fpu	s21	.32	152	0\n"
		"fpu	s22	.32	156	0\n"
		"fpu	s23	.32	160	0\n"
		"fpu	s24	.32	164	0\n"
		"fpu	s25	.32	168	0\n"
		"fpu	s26	.32	172	0\n"
		"fpu	s27	.32	176	0\n"
		"fpu	s28	.32	180	0\n"
		"fpu	s29	.32	184	0\n"
		"fpu	s30	.32	188	0\n"
		"fpu	s31	.32	192	0\n"

		/* 64bit double */
		"fpu	d0	.64	68	0\n"
		"fpu	d1	.64	76	0\n"
		"fpu	d2	.64	84	0\n"
		"fpu	d3	.64	92	0\n"
		"fpu	d4	.64	100	0\n"
		"fpu	d5	.64	108	0\n"
		"fpu	d6	.64	116	0\n"
		"fpu	d7	.64	124	0\n"
		"fpu	d8	.64	132	0\n"
		"fpu	d9	.64	140	0\n"
		"fpu	d10	.64	148	0\n"
		"fpu	d11	.64	156	0\n"
		"fpu	d12	.64	164	0\n"
		"fpu	d13	.64	172	0\n"
		"fpu	d14	.64	180	0\n"
		"fpu	d15	.64	188	0\n"
		"fpu	d16	.64	196	0\n"
		"fpu	d17	.64	204	0\n"
		"fpu	d18	.64	212	0\n"
		"fpu	d19	.64	220	0\n"
		"fpu	d20	.64	228	0\n"
		"fpu	d21	.64	236	0\n"
		"fpu	d22	.64	244	0\n"
		"fpu	d23	.64	252	0\n"
		"fpu	d24	.64	260	0\n"
		"fpu	d25	.64	268	0\n"
		"fpu	d26	.64	276	0\n"
		"fpu	d27	.64	284	0\n"
		"fpu	d28	.64	292	0\n"
		"fpu	d29	.64	300	0\n"
		"fpu	d30	.64	308	0\n"
		"fpu	d31	.64	316	0\n"

		/* 128bit double */
		"fpu	q0	.128	68	0\n"
		"fpu	q1	.128	84	0\n"
		"fpu	q2	.128	100	0\n"
		"fpu	q3	.128	116	0\n"
		"fpu	q4	.128	132	0\n"
		"fpu	q5	.128	148	0\n"
		"fpu	q6	.128	164	0\n"
		"fpu	q7	.128	180	0\n"
		"fpu	q8	.128	196	0\n"
		"fpu	q9	.128	212	0\n"
		"fpu	q10	.128	228	0\n"
		"fpu	q11	.128	244	0\n"
		"fpu	q12	.128	260	0\n"
		"fpu	q13	.128	276	0\n"
		"fpu	q14	.128	292	0\n"
		"fpu	q15	.128	308	0\n"
		;
	}
	const char *snReg = (!strcmp (anal->os, "android") || !strcmp (anal->os, "linux"))? "x8": "x16";
	return r_str_newf (p, snReg);
}