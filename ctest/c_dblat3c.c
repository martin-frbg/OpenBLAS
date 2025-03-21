#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <complex.h>
#ifdef complex
#undef complex
#endif
#ifdef I
#undef I
#endif

#include "common.h"

typedef blasint integer;

typedef unsigned int uinteger;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
#ifdef _MSC_VER
static inline _Fcomplex Cf(complex *z) {_Fcomplex zz={z->r , z->i}; return zz;}
static inline _Dcomplex Cd(doublecomplex *z) {_Dcomplex zz={z->r , z->i};return zz;}
static inline _Fcomplex * _pCf(complex *z) {return (_Fcomplex*)z;}
static inline _Dcomplex * _pCd(doublecomplex *z) {return (_Dcomplex*)z;}
#else
static inline _Complex float Cf(complex *z) {return z->r + z->i*_Complex_I;}
static inline _Complex double Cd(doublecomplex *z) {return z->r + z->i*_Complex_I;}
static inline _Complex float * _pCf(complex *z) {return (_Complex float*)z;}
static inline _Complex double * _pCd(doublecomplex *z) {return (_Complex double*)z;}
#endif
#define pCf(z) (*_pCf(z))
#define pCd(z) (*_pCd(z))
typedef int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* I/O stuff */

typedef int flag;
typedef int ftnlen;
typedef int ftnint;

/*external read, write*/
typedef struct
{	flag cierr;
	ftnint ciunit;
	flag ciend;
	char *cifmt;
	ftnint cirec;
} cilist;

/*internal read, write*/
typedef struct
{	flag icierr;
	char *iciunit;
	flag iciend;
	char *icifmt;
	ftnint icirlen;
	ftnint icirnum;
} icilist;

/*open*/
typedef struct
{	flag oerr;
	ftnint ounit;
	char *ofnm;
	ftnlen ofnmlen;
	char *osta;
	char *oacc;
	char *ofm;
	ftnint orl;
	char *oblnk;
} olist;

/*close*/
typedef struct
{	flag cerr;
	ftnint cunit;
	char *csta;
} cllist;

/*rewind, backspace, endfile*/
typedef struct
{	flag aerr;
	ftnint aunit;
} alist;

/* inquire */
typedef struct
{	flag inerr;
	ftnint inunit;
	char *infile;
	ftnlen infilen;
	ftnint	*inex;	/*parameters in standard's order*/
	ftnint	*inopen;
	ftnint	*innum;
	ftnint	*innamed;
	char	*inname;
	ftnlen	innamlen;
	char	*inacc;
	ftnlen	inacclen;
	char	*inseq;
	ftnlen	inseqlen;
	char 	*indir;
	ftnlen	indirlen;
	char	*infmt;
	ftnlen	infmtlen;
	char	*inform;
	ftnint	informlen;
	char	*inunf;
	ftnlen	inunflen;
	ftnint	*inrecl;
	ftnint	*innrec;
	char	*inblank;
	ftnlen	inblanklen;
} inlist;

#define VOID void

union Multitype {	/* for multiple entry points */
	integer1 g;
	shortint h;
	integer i;
	/* longint j; */
	real r;
	doublereal d;
	complex c;
	doublecomplex z;
	};

typedef union Multitype Multitype;

struct Vardesc {	/* for Namelist */
	char *name;
	char *addr;
	ftnlen *dims;
	int  type;
	};
typedef struct Vardesc Vardesc;

struct Namelist {
	char *name;
	Vardesc **vars;
	int nvars;
	};
typedef struct Namelist Namelist;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (fabs(x))
#define f2cmin(a,b) ((a) <= (b) ? (a) : (b))
#define f2cmax(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (f2cmin(a,b))
#define dmax(a,b) (f2cmax(a,b))
#define bit_test(a,b)	((a) >> (b) & 1)
#define bit_clear(a,b)	((a) & ~((uinteger)1 << (b)))
#define bit_set(a,b)	((a) |  ((uinteger)1 << (b)))

#define abort_() { sig_die("Fortran abort routine called", 1); }
#define c_abs(z) (cabsf(Cf(z)))
#define c_cos(R,Z) { pCf(R)=ccos(Cf(Z)); }
#ifdef _MSC_VER
#define c_div(c, a, b) {Cf(c)._Val[0] = (Cf(a)._Val[0]/Cf(b)._Val[0]); Cf(c)._Val[1]=(Cf(a)._Val[1]/Cf(b)._Val[1]);}
#define z_div(c, a, b) {Cd(c)._Val[0] = (Cd(a)._Val[0]/Cd(b)._Val[0]); Cd(c)._Val[1]=(Cd(a)._Val[1]/Cd(b)._Val[1]);}
#else
#define c_div(c, a, b) {pCf(c) = Cf(a)/Cf(b);}
#define z_div(c, a, b) {pCd(c) = Cd(a)/Cd(b);}
#endif
#define c_exp(R, Z) {pCf(R) = cexpf(Cf(Z));}
#define c_log(R, Z) {pCf(R) = clogf(Cf(Z));}
#define c_sin(R, Z) {pCf(R) = csinf(Cf(Z));}
//#define c_sqrt(R, Z) {*(R) = csqrtf(Cf(Z));}
#define c_sqrt(R, Z) {pCf(R) = csqrtf(Cf(Z));}
#define d_abs(x) (fabs(*(x)))
#define d_acos(x) (acos(*(x)))
#define d_asin(x) (asin(*(x)))
#define d_atan(x) (atan(*(x)))
#define d_atn2(x, y) (atan2(*(x),*(y)))
#define d_cnjg(R, Z) { pCd(R) = conj(Cd(Z)); }
#define r_cnjg(R, Z) { pCf(R) = conjf(Cf(Z)); }
#define d_cos(x) (cos(*(x)))
#define d_cosh(x) (cosh(*(x)))
#define d_dim(__a, __b) ( *(__a) > *(__b) ? *(__a) - *(__b) : 0.0 )
#define d_exp(x) (exp(*(x)))
#define d_imag(z) (cimag(Cd(z)))
#define r_imag(z) (cimagf(Cf(z)))
#define d_int(__x) (*(__x)>0 ? floor(*(__x)) : -floor(- *(__x)))
#define r_int(__x) (*(__x)>0 ? floor(*(__x)) : -floor(- *(__x)))
#define d_lg10(x) ( 0.43429448190325182765 * log(*(x)) )
#define r_lg10(x) ( 0.43429448190325182765 * log(*(x)) )
#define d_log(x) (log(*(x)))
#define d_mod(x, y) (fmod(*(x), *(y)))
#define u_nint(__x) ((__x)>=0 ? floor((__x) + .5) : -floor(.5 - (__x)))
#define d_nint(x) u_nint(*(x))
#define u_sign(__a,__b) ((__b) >= 0 ? ((__a) >= 0 ? (__a) : -(__a)) : -((__a) >= 0 ? (__a) : -(__a)))
#define d_sign(a,b) u_sign(*(a),*(b))
#define r_sign(a,b) u_sign(*(a),*(b))
#define d_sin(x) (sin(*(x)))
#define d_sinh(x) (sinh(*(x)))
#define d_sqrt(x) (sqrt(*(x)))
#define d_tan(x) (tan(*(x)))
#define d_tanh(x) (tanh(*(x)))
#define i_abs(x) abs(*(x))
#define i_dnnt(x) ((integer)u_nint(*(x)))
#define i_len(s, n) (n)
#define i_nint(x) ((integer)u_nint(*(x)))
#define i_sign(a,b) ((integer)u_sign((integer)*(a),(integer)*(b)))
#define pow_dd(ap, bp) ( pow(*(ap), *(bp)))
#define pow_si(B,E) spow_ui(*(B),*(E))
#define pow_ri(B,E) spow_ui(*(B),*(E))
#define pow_di(B,E) dpow_ui(*(B),*(E))
#define pow_zi(p, a, b) {pCd(p) = zpow_ui(Cd(a), *(b));}
#define pow_ci(p, a, b) {pCf(p) = cpow_ui(Cf(a), *(b));}
#define pow_zz(R,A,B) {pCd(R) = cpow(Cd(A),*(B));}
#define s_cat(lpp, rpp, rnp, np, llp) { 	ftnlen i, nc, ll; char *f__rp, *lp; 	ll = (llp); lp = (lpp); 	for(i=0; i < (int)*(np); ++i) {         	nc = ll; 	        if((rnp)[i] < nc) nc = (rnp)[i]; 	        ll -= nc;         	f__rp = (rpp)[i]; 	        while(--nc >= 0) *lp++ = *(f__rp)++;         } 	while(--ll >= 0) *lp++ = ' '; }
#define s_cmp(a,b,c,d) ((integer)strncmp((a),(b),f2cmin((c),(d))))
#define s_copy(A,B,C,D) { int __i,__m; for (__i=0, __m=f2cmin((C),(D)); __i<__m && (B)[__i] != 0; ++__i) (A)[__i] = (B)[__i]; }
#define sig_die(s, kill) { exit(1); }
#define s_stop(s, n) {exit(0);}
#define z_abs(z) (cabs(Cd(z)))
#define z_exp(R, Z) {pCd(R) = cexp(Cd(Z));}
#define z_sqrt(R, Z) {pCd(R) = csqrt(Cd(Z));}
#define myexit_() break;
#define mycycle_() continue;
#define myceiling_(w) {ceil(w)}
#define myhuge_(w) {HUGE_VAL}

/* procedure parameter types for -A and -C++ */

#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef logical (*L_fp)(...);
#else
typedef logical (*L_fp)();
#endif

static float spow_ui(float x, integer n) {
	float pow=1.0; unsigned long int u;
	if(n != 0) {
		if(n < 0) n = -n, x = 1/x;
		for(u = n; ; ) {
			if(u & 01) pow *= x;
			if(u >>= 1) x *= x;
			else break;
		}
	}
	return pow;
}
static double dpow_ui(double x, integer n) {
	double pow=1.0; unsigned long int u;
	if(n != 0) {
		if(n < 0) n = -n, x = 1/x;
		for(u = n; ; ) {
			if(u & 01) pow *= x;
			if(u >>= 1) x *= x;
			else break;
		}
	}
	return pow;
}
#ifdef _MSC_VER
static _Fcomplex cpow_ui(complex x, integer n) {
	complex pow={1.0,0.0}; unsigned long int u;
		if(n != 0) {
		if(n < 0) n = -n, x.r = 1/x.r, x.i=1/x.i;
		for(u = n; ; ) {
			if(u & 01) pow.r *= x.r, pow.i *= x.i;
			if(u >>= 1) x.r *= x.r, x.i *= x.i;
			else break;
		}
	}
	_Fcomplex p={pow.r, pow.i};
	return p;
}
#else
static _Complex float cpow_ui(_Complex float x, integer n) {
	_Complex float pow=1.0; unsigned long int u;
	if(n != 0) {
		if(n < 0) n = -n, x = 1/x;
		for(u = n; ; ) {
			if(u & 01) pow *= x;
			if(u >>= 1) x *= x;
			else break;
		}
	}
	return pow;
}
#endif
#ifdef _MSC_VER
static _Dcomplex zpow_ui(_Dcomplex x, integer n) {
	_Dcomplex pow={1.0,0.0}; unsigned long int u;
	if(n != 0) {
		if(n < 0) n = -n, x._Val[0] = 1/x._Val[0], x._Val[1] =1/x._Val[1];
		for(u = n; ; ) {
			if(u & 01) pow._Val[0] *= x._Val[0], pow._Val[1] *= x._Val[1];
			if(u >>= 1) x._Val[0] *= x._Val[0], x._Val[1] *= x._Val[1];
			else break;
		}
	}
	_Dcomplex p = {pow._Val[0], pow._Val[1]};
	return p;
}
#else
static _Complex double zpow_ui(_Complex double x, integer n) {
	_Complex double pow=1.0; unsigned long int u;
	if(n != 0) {
		if(n < 0) n = -n, x = 1/x;
		for(u = n; ; ) {
			if(u & 01) pow *= x;
			if(u >>= 1) x *= x;
			else break;
		}
	}
	return pow;
}
#endif
static integer pow_ii(integer x, integer n) {
	integer pow; unsigned long int u;
	if (n <= 0) {
		if (n == 0 || x == 1) pow = 1;
		else if (x != -1) pow = x == 0 ? 1/x : 0;
		else n = -n;
	}
	if ((n > 0) || !(n == 0 || x == 1 || x != -1)) {
		u = n;
		for(pow = 1; ; ) {
			if(u & 01) pow *= x;
			if(u >>= 1) x *= x;
			else break;
		}
	}
	return pow;
}

/* Common Block Declarations */

union {
    struct {
	integer infot, noutc;
	logical ok;
    } _1;
    struct {
	integer infot, noutc;
	logical ok, lerr;
    } _2;
} infoc_;

#define infoc_1 (infoc_._1)
#define infoc_2 (infoc_._2)

struct {
    char srnamt[13];
} srnamc_;

#define srnamc_1 srnamc_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__65 = 65;
static integer c__7 = 7;
static doublereal c_b90 = 1.;
static doublereal c_b104 = 0.;
static integer c__6 = 6;
static logical c_true = TRUE_;
static integer c__0 = 0;
static logical c_false = FALSE_;

/* Main program */ int main(void)
{
    /* Initialized data */

    static char snames[13*7] = "cblas_dgemm  " "cblas_dsymm  " "cblas_dtrmm  "
	     "cblas_dtrsm  " "cblas_dsyrk  " "cblas_dsyr2k " "cblas_dgemmtr";

    /* Format strings */
    static char fmt_9997[] = "(\002 NUMBER OF VALUES OF \002,a,\002 IS LESS "
	    "THAN 1 OR GREATER \002,\002THAN \002,i2)";
    static char fmt_9996[] = "(\002 VALUE OF N IS LESS THAN 0 OR GREATER THA"
	    "N \002,i2)";
    static char fmt_9995[] = "(\002 TESTS OF THE DOUBLE PRECISION LEVEL 3 BL"
	    "AS\002,//\002 THE F\002,\002OLLOWING PARAMETER VALUES WILL BE US"
	    "ED:\002)";
    static char fmt_9994[] = "(\002   FOR N              \002,9i6)";
    static char fmt_9993[] = "(\002   FOR ALPHA          \002,7f6.1)";
    static char fmt_9992[] = "(\002   FOR BETA           \002,7f6.1)";
    static char fmt_9984[] = "(\002 ERROR-CALL MYEXITS WILL NOT BE TESTED"
	    "\002)";
    static char fmt_9999[] = "(\002 ROUTINES PASS COMPUTATIONAL TESTS IF TES"
	    "T RATIO IS LES\002,\002S THAN\002,f8.2)";
    static char fmt_10002[] = "(\002 COLUMN-MAJOR AND ROW-MAJOR DATA LAYOUTS"
	    " ARE TESTED\002)";
    static char fmt_10001[] = "(\002 ROW-MAJOR DATA LAYOUT IS TESTED\002)";
    static char fmt_10000[] = "(\002 COLUMN-MAJOR DATA LAYOUT IS TESTED\002)";
    static char fmt_9988[] = "(a13,l2)";
    static char fmt_9990[] = "(\002 SUBPROGRAM NAME \002,a13,\002 NOT RECOGN"
	    "IZED\002,/\002 ******* T\002,\002ESTS ABANDONED *******\002)";
    static char fmt_9998[] = "(\002 RELATIVE MACHINE PRECISION IS TAKEN TO"
	    " BE\002,1p,d9.1)";
    static char fmt_9989[] = "(\002 ERROR IN DMMCH -  IN-LINE DOT PRODUCTS A"
	    "RE BEING EVALU\002,\002ATED WRONGLY.\002,/\002 DMMCH WAS CALLED "
	    "WITH TRANSA = \002,a1,\002 AND TRANSB = \002,a1,/\002 AND RETURN"
	    "ED SAME = \002,l1,\002 AND \002,\002ERR = \002,f12.3,\002.\002,"
	    "/\002 THIS MAY BE DUE TO FAULTS IN THE \002,\002ARITHMETIC OR TH"
	    "E COMPILER.\002,/\002 ******* TESTS ABANDONED \002,\002******"
	    "*\002)";
    static char fmt_9987[] = "(1x,a13,\002 WAS NOT TESTED\002)";
    static char fmt_9986[] = "(/\002 END OF TESTS\002)";
    static char fmt_9985[] = "(/\002 ******* FATAL ERROR - TESTS ABANDONED *"
	    "******\002)";
    static char fmt_9991[] = "(\002 AMEND DATA FILE OR INCREASE ARRAY SIZES "
	    "IN PROGRAM\002,/\002 ******* TESTS ABANDONED *******\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;
    olist o__1;
    cllist cl__1;

    /* Local variables */
    doublereal c__[4225]	/* was [65][65] */, g[65];
    integer i__, j, n;
    doublereal w[130], aa[4225], ab[8450]	/* was [65][130] */, bb[4225],
	     cc[4225], as[4225], bs[4225], cs[4225], ct[65], alf[7];
    extern logical lde_(doublereal *, doublereal *, integer *);
    doublereal bet[7], eps, err;
    integer nalf, idim[9];
    logical same;
    integer nbet, ntra;
    logical rewi;
    extern /* Subroutine */ int dchk1_(char *, doublereal *, doublereal *, 
	    integer *, integer *, logical *, logical *, logical *, integer *, 
	    integer *, integer *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *), 
	    dchk2_(char *, doublereal *, doublereal *, integer *, integer *, 
	    logical *, logical *, logical *, integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), dchk3_(char *, 
	    doublereal *, doublereal *, integer *, integer *, logical *, 
	    logical *, logical *, integer *, integer *, integer *, doublereal 
	    *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), dchk4_(char *, 
	    doublereal *, doublereal *, integer *, integer *, logical *, 
	    logical *, logical *, integer *, integer *, integer *, doublereal 
	    *, integer *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), dchk5_(char *, doublereal *, 
	    doublereal *, integer *, integer *, logical *, logical *, logical 
	    *, integer *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *), dchk6_(char *, doublereal *, doublereal *, integer *, 
	    integer *, logical *, logical *, logical *, integer *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    extern doublereal ddiff_(doublereal *, doublereal *);
    logical fatal;
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical trace;
    integer nidim;
    char snaps[32];
    integer isnum;
    logical ltest[7], sfatal, corder;
    char snamet[13], transa[1], transb[1];
    doublereal thresh;
    logical rorder;
    extern /* Subroutine */ int cd3chke_(char *);
    integer layout;
    logical ltestt, tsterr;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 5, 0, 0, 0 };
    static cilist io___4 = { 0, 5, 0, 0, 0 };
    static cilist io___7 = { 0, 5, 0, 0, 0 };
    static cilist io___9 = { 0, 5, 0, 0, 0 };
    static cilist io___11 = { 0, 5, 0, 0, 0 };
    static cilist io___13 = { 0, 5, 0, 0, 0 };
    static cilist io___15 = { 0, 5, 0, 0, 0 };
    static cilist io___17 = { 0, 5, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, fmt_9997, 0 };
    static cilist io___20 = { 0, 5, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_9996, 0 };
    static cilist io___24 = { 0, 5, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_9997, 0 };
    static cilist io___27 = { 0, 5, 0, 0, 0 };
    static cilist io___29 = { 0, 5, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_9997, 0 };
    static cilist io___32 = { 0, 5, 0, 0, 0 };
    static cilist io___34 = { 0, 6, 0, fmt_9995, 0 };
    static cilist io___35 = { 0, 6, 0, fmt_9994, 0 };
    static cilist io___36 = { 0, 6, 0, fmt_9993, 0 };
    static cilist io___37 = { 0, 6, 0, fmt_9992, 0 };
    static cilist io___38 = { 0, 6, 0, 0, 0 };
    static cilist io___39 = { 0, 6, 0, fmt_9984, 0 };
    static cilist io___40 = { 0, 6, 0, 0, 0 };
    static cilist io___41 = { 0, 6, 0, fmt_9999, 0 };
    static cilist io___42 = { 0, 6, 0, 0, 0 };
    static cilist io___45 = { 0, 6, 0, fmt_10002, 0 };
    static cilist io___46 = { 0, 6, 0, fmt_10001, 0 };
    static cilist io___47 = { 0, 6, 0, fmt_10000, 0 };
    static cilist io___48 = { 0, 6, 0, 0, 0 };
    static cilist io___50 = { 0, 5, 1, fmt_9988, 0 };
    static cilist io___53 = { 0, 6, 0, fmt_9990, 0 };
    static cilist io___55 = { 0, 6, 0, fmt_9998, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_9989, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_9989, 0 };
    static cilist io___70 = { 0, 6, 0, fmt_9989, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_9989, 0 };
    static cilist io___73 = { 0, 6, 0, 0, 0 };
    static cilist io___74 = { 0, 6, 0, fmt_9987, 0 };
    static cilist io___75 = { 0, 6, 0, 0, 0 };
    static cilist io___82 = { 0, 6, 0, fmt_9986, 0 };
    static cilist io___83 = { 0, 6, 0, fmt_9985, 0 };
    static cilist io___84 = { 0, 6, 0, fmt_9991, 0 };



/*  Test program for the DOUBLE PRECISION Level 3 Blas. */

/*  The program must be driven by a short data file. The first 13 records */
/*  of the file are read using list-directed input, the last 6 records */
/*  are read using the format ( A13, L2 ). An annotated example of a data */
/*  file can be obtained by deleting the first 3 characters from the */
/*  following 19 lines: */
/*  'DBLAT3.SNAP'     NAME OF SNAPSHOT OUTPUT FILE */
/*  -1                UNIT NUMBER OF SNAPSHOT FILE (NOT USED IF .LT. 0) */
/*  F        LOGICAL FLAG, T TO REWIND SNAPSHOT FILE AFTER EACH RECORD. */
/*  F        LOGICAL FLAG, T TO STOP ON FAILURES. */
/*  T        LOGICAL FLAG, T TO TEST ERROR CALL MYEXITS. */
/*  2        0 TO TEST COLUMN-MAJOR, 1 TO TEST ROW-MAJOR, 2 TO TEST BOTH */
/*  16.0     THRESHOLD VALUE OF TEST RATIO */
/*  6                 NUMBER OF VALUES OF N */
/*  0 1 2 3 5 9       VALUES OF N */
/*  3                 NUMBER OF VALUES OF ALPHA */
/*  0.0 1.0 0.7       VALUES OF ALPHA */
/*  3                 NUMBER OF VALUES OF BETA */
/*  0.0 1.0 1.3       VALUES OF BETA */
/*  cblas_dgemm   T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dsymm   T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dtrmm   T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dtrsm   T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dsyrk   T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dsyr2k  T PUT F FOR NO TEST. SAME COLUMNS. */
/*  cblas_dgemmtr T PUT F FOR NO TEST. SAME COLUMNS. */

/*  See: */

/*     Dongarra J. J., Du Croz J. J., Duff I. S. and Hammarling S. */
/*     A Set of Level 3 Basic Linear Algebra Subprograms. */

/*     Technical Memorandum No.88 (Revision 1), Mathematics and */
/*     Computer Science Division, Argonne National Laboratory, 9700 */
/*     South Cass Avenue, Argonne, Illinois 60439, US. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */


/*     Read name and unit number for summary output file and open file. */

    infoc_1.noutc = 6;
/*     Read name and unit number for snapshot output file and open file. */

    s_rsle(&io___2);
    do_lio(&c__9, &c__1, snaps, (ftnlen)32);
    e_rsle();
    s_rsle(&io___4);
    do_lio(&c__3, &c__1, (char *)&ntra, (ftnlen)sizeof(integer));
    e_rsle();
    trace = ntra >= 0;
    if (trace) {
	o__1.oerr = 0;
	o__1.ounit = ntra;
	o__1.ofnmlen = 32;
	o__1.ofnm = snaps;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*     Read the flag that directs rewinding of the snapshot file. */
    s_rsle(&io___7);
    do_lio(&c__8, &c__1, (char *)&rewi, (ftnlen)sizeof(logical));
    e_rsle();
    rewi = rewi && trace;
/*     Read the flag that directs stopping on any failure. */
    s_rsle(&io___9);
    do_lio(&c__8, &c__1, (char *)&sfatal, (ftnlen)sizeof(logical));
    e_rsle();
/*     Read the flag that indicates whether error exits are to be tested. */
    s_rsle(&io___11);
    do_lio(&c__8, &c__1, (char *)&tsterr, (ftnlen)sizeof(logical));
    e_rsle();
/*     Read the flag that indicates whether row-major data layout to be tested. */
    s_rsle(&io___13);
    do_lio(&c__3, &c__1, (char *)&layout, (ftnlen)sizeof(integer));
    e_rsle();
/*     Read the threshold value of the test ratio */
    s_rsle(&io___15);
    do_lio(&c__5, &c__1, (char *)&thresh, (ftnlen)sizeof(doublereal));
    e_rsle();

/*     Read and check the parameter values for the tests. */

/*     Values of N */
    s_rsle(&io___17);
    do_lio(&c__3, &c__1, (char *)&nidim, (ftnlen)sizeof(integer));
    e_rsle();
    if (nidim < 1 || nidim > 9) {
	s_wsfe(&io___19);
	do_fio(&c__1, "N", (ftnlen)1);
	do_fio(&c__1, (char *)&c__9, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L220;
    }
    s_rsle(&io___20);
    i__1 = nidim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__3, &c__1, (char *)&idim[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_rsle();
    i__1 = nidim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (idim[i__ - 1] < 0 || idim[i__ - 1] > 65) {
	    s_wsfe(&io___23);
	    do_fio(&c__1, (char *)&c__65, (ftnlen)sizeof(integer));
	    e_wsfe();
	    goto L220;
	}
/* L10: */
    }
/*     Values of ALPHA */
    s_rsle(&io___24);
    do_lio(&c__3, &c__1, (char *)&nalf, (ftnlen)sizeof(integer));
    e_rsle();
    if (nalf < 1 || nalf > 7) {
	s_wsfe(&io___26);
	do_fio(&c__1, "ALPHA", (ftnlen)5);
	do_fio(&c__1, (char *)&c__7, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L220;
    }
    s_rsle(&io___27);
    i__1 = nalf;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__5, &c__1, (char *)&alf[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsle();
/*     Values of BETA */
    s_rsle(&io___29);
    do_lio(&c__3, &c__1, (char *)&nbet, (ftnlen)sizeof(integer));
    e_rsle();
    if (nbet < 1 || nbet > 7) {
	s_wsfe(&io___31);
	do_fio(&c__1, "BETA", (ftnlen)4);
	do_fio(&c__1, (char *)&c__7, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L220;
    }
    s_rsle(&io___32);
    i__1 = nbet;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_lio(&c__5, &c__1, (char *)&bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsle();

/*     Report values of parameters. */

    s_wsfe(&io___34);
    e_wsfe();
    s_wsfe(&io___35);
    i__1 = nidim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&idim[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsfe(&io___36);
    i__1 = nalf;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&alf[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    s_wsfe(&io___37);
    i__1 = nbet;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&bet[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (! tsterr) {
	s_wsle(&io___38);
	e_wsle();
	s_wsfe(&io___39);
	e_wsfe();
    }
    s_wsle(&io___40);
    e_wsle();
    s_wsfe(&io___41);
    do_fio(&c__1, (char *)&thresh, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsle(&io___42);
    e_wsle();
    rorder = FALSE_;
    corder = FALSE_;
    if (layout == 2) {
	rorder = TRUE_;
	corder = TRUE_;
	s_wsfe(&io___45);
	e_wsfe();
    } else if (layout == 1) {
	rorder = TRUE_;
	s_wsfe(&io___46);
	e_wsfe();
    } else if (layout == 0) {
	corder = TRUE_;
	s_wsfe(&io___47);
	e_wsfe();
    }
    s_wsle(&io___48);
    e_wsle();

/*     Read names of subroutines and flags which indicate */
/*     whether they are to be tested. */

    for (i__ = 1; i__ <= 7; ++i__) {
	ltest[i__ - 1] = FALSE_;
/* L20: */
    }
L30:
    i__1 = s_rsfe(&io___50);
    if (i__1 != 0) {
	goto L60;
    }
    i__1 = do_fio(&c__1, snamet, (ftnlen)13);
    if (i__1 != 0) {
	goto L60;
    }
    i__1 = do_fio(&c__1, (char *)&ltestt, (ftnlen)sizeof(logical));
    if (i__1 != 0) {
	goto L60;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L60;
    }
    for (i__ = 1; i__ <= 7; ++i__) {
	if (s_cmp(snamet, snames + (i__ - 1) * 13, (ftnlen)13, (ftnlen)13) == 
		0) {
	    goto L50;
	}
/* L40: */
    }
    s_wsfe(&io___53);
    do_fio(&c__1, snamet, (ftnlen)13);
    e_wsfe();
    s_stop("", (ftnlen)0);
L50:
    ltest[i__ - 1] = ltestt;
    goto L30;

L60:
    cl__1.cerr = 0;
    cl__1.cunit = 5;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*     Compute EPS (the machine precision). */

    eps = 1.;
L70:
    d__1 = eps + 1.;
    if (ddiff_(&d__1, &c_b90) == 0.) {
	goto L80;
    }
    eps *= .5;
    goto L70;
L80:
    eps += eps;
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&eps, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     Check the reliability of DMMCH using exact data. */

    n = 32;
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing MAX */
	    i__3 = i__ - j + 1;
	    ab[i__ + j * 65 - 66] = (doublereal) f2cmax(i__3,0);
/* L90: */
	}
	ab[j + 4224] = (doublereal) j;
	ab[(j + 65) * 65 - 65] = (doublereal) j;
	c__[j - 1] = 0.;
/* L100: */
    }
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	cc[j - 1] = (doublereal) (j * ((j + 1) * j) / 2 - (j + 1) * j * (j - 
		1) / 3);
/* L110: */
    }
/*     CC holds the exact result. On exit from DMMCH CT holds */
/*     the result computed by DMMCH. */
    *(unsigned char *)transa = 'N';
    *(unsigned char *)transb = 'N';
    dmmch_(transa, transb, &n, &c__1, &n, &c_b90, ab, &c__65, &ab[4225], &
	    c__65, &c_b104, c__, &c__65, ct, g, cc, &c__65, &eps, &err, &
	    fatal, &c__6, &c_true);
    same = lde_(cc, ct, &n);
    if (! same || err != 0.) {
	s_wsfe(&io___68);
	do_fio(&c__1, transa, (ftnlen)1);
	do_fio(&c__1, transb, (ftnlen)1);
	do_fio(&c__1, (char *)&same, (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&err, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    *(unsigned char *)transb = 'T';
    dmmch_(transa, transb, &n, &c__1, &n, &c_b90, ab, &c__65, &ab[4225], &
	    c__65, &c_b104, c__, &c__65, ct, g, cc, &c__65, &eps, &err, &
	    fatal, &c__6, &c_true);
    same = lde_(cc, ct, &n);
    if (! same || err != 0.) {
	s_wsfe(&io___69);
	do_fio(&c__1, transa, (ftnlen)1);
	do_fio(&c__1, transb, (ftnlen)1);
	do_fio(&c__1, (char *)&same, (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&err, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	ab[j + 4224] = (doublereal) (n - j + 1);
	ab[(j + 65) * 65 - 65] = (doublereal) (n - j + 1);
/* L120: */
    }
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	cc[n - j] = (doublereal) (j * ((j + 1) * j) / 2 - (j + 1) * j * (j - 
		1) / 3);
/* L130: */
    }
    *(unsigned char *)transa = 'T';
    *(unsigned char *)transb = 'N';
    dmmch_(transa, transb, &n, &c__1, &n, &c_b90, ab, &c__65, &ab[4225], &
	    c__65, &c_b104, c__, &c__65, ct, g, cc, &c__65, &eps, &err, &
	    fatal, &c__6, &c_true);
    same = lde_(cc, ct, &n);
    if (! same || err != 0.) {
	s_wsfe(&io___70);
	do_fio(&c__1, transa, (ftnlen)1);
	do_fio(&c__1, transb, (ftnlen)1);
	do_fio(&c__1, (char *)&same, (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&err, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    *(unsigned char *)transb = 'T';
    dmmch_(transa, transb, &n, &c__1, &n, &c_b90, ab, &c__65, &ab[4225], &
	    c__65, &c_b104, c__, &c__65, ct, g, cc, &c__65, &eps, &err, &
	    fatal, &c__6, &c_true);
    same = lde_(cc, ct, &n);
    if (! same || err != 0.) {
	s_wsfe(&io___71);
	do_fio(&c__1, transa, (ftnlen)1);
	do_fio(&c__1, transb, (ftnlen)1);
	do_fio(&c__1, (char *)&same, (ftnlen)sizeof(logical));
	do_fio(&c__1, (char *)&err, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     Test each subroutine in turn. */

    for (isnum = 1; isnum <= 7; ++isnum) {
	s_wsle(&io___73);
	e_wsle();
	if (! ltest[isnum - 1]) {
/*           Subprogram is not to be tested. */
	    s_wsfe(&io___74);
	    do_fio(&c__1, snames + (isnum - 1) * 13, (ftnlen)13);
	    e_wsfe();
	} else {
	    s_copy(srnamc_1.srnamt, snames + (isnum - 1) * 13, (ftnlen)13, (
		    ftnlen)13);
/*           Test error exits. */
	    if (tsterr) {
		cd3chke_(snames + (isnum - 1) * 13);
		s_wsle(&io___75);
		e_wsle();
	    }
/*           Test computations. */
	    infoc_1.infot = 0;
	    infoc_1.ok = TRUE_;
	    fatal = FALSE_;
	    switch (isnum) {
		case 1:  goto L140;
		case 2:  goto L150;
		case 3:  goto L160;
		case 4:  goto L160;
		case 5:  goto L170;
		case 6:  goto L180;
		case 7:  goto L185;
	    }
/*           Test DGEMM, 01. */
L140:
	    if (corder) {
		dchk1_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__0);
	    }
	    if (rorder) {
		dchk1_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__1);
	    }
	    goto L190;
/*           Test DSYMM, 02. */
L150:
	    if (corder) {
		dchk2_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__0);
	    }
	    if (rorder) {
		dchk2_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__1);
	    }
	    goto L190;
/*           Test DTRMM, 03, DTRSM, 04. */
L160:
	    if (corder) {
		dchk3_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			c__65, ab, aa, as, &ab[4225], bb, bs, ct, g, c__, &
			c__0);
	    }
	    if (rorder) {
		dchk3_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			c__65, ab, aa, as, &ab[4225], bb, bs, ct, g, c__, &
			c__1);
	    }
	    goto L190;
/*           Test DSYRK, 05. */
L170:
	    if (corder) {
		dchk4_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__0);
	    }
	    if (rorder) {
		dchk4_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, &ab[4225], bb, bs, c__,
			 cc, cs, ct, g, &c__1);
	    }
	    goto L190;
/*           Test DSYR2K, 06. */
L180:
	    if (corder) {
		dchk5_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, bb, bs, c__, cc, cs, 
			ct, g, w, &c__0);
	    }
	    if (rorder) {
		dchk5_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, bb, bs, c__, cc, cs, 
			ct, g, w, &c__1);
	    }
	    goto L190;
/*           Test DGEMMTR, 07. */
L185:
	    if (corder) {
		dchk6_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, bb, bs, c__, cc, cs, 
			ct, g, w, &c__0);
	    }
	    if (rorder) {
		dchk6_(snames + (isnum - 1) * 13, &eps, &thresh, &c__6, &ntra,
			 &trace, &rewi, &fatal, &nidim, idim, &nalf, alf, &
			nbet, bet, &c__65, ab, aa, as, bb, bs, c__, cc, cs, 
			ct, g, w, &c__1);
	    }
	    goto L190;

L190:
	    if (fatal && sfatal) {
		goto L210;
	    }
	}
/* L200: */
    }
    s_wsfe(&io___82);
    e_wsfe();
    goto L230;

L210:
    s_wsfe(&io___83);
    e_wsfe();
    goto L230;

L220:
    s_wsfe(&io___84);
    e_wsfe();

L230:
    if (trace) {
	cl__1.cerr = 0;
	cl__1.cunit = ntra;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    cl__1.cerr = 0;
    cl__1.cunit = 6;
    cl__1.csta = 0;
    f_clos(&cl__1);
    s_stop("", (ftnlen)0);


/*     End of DBLAT3. */

    return 0;
} /* MAIN__ */

/* Subroutine */ int dchk1_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nbet, doublereal *bet, integer *nmax, doublereal *a, 
	doublereal *aa, doublereal *as, doublereal *b, doublereal *bb, 
	doublereal *bs, doublereal *c__, doublereal *cc, doublereal *cs, 
	doublereal *ct, doublereal *g, integer *iorder)
{
    /* Initialized data */

    static char ich[3] = "NTC";

    /* Format strings */
    static char fmt_9994[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3, i__4, i__5, i__6;
    alist al__1;

    /* Local variables */
    integer i__, k, m, n, ia, ib, ma, mb, na, nb, nc, ik, im, in, ks, ms, ns, 
	    ica, icb, laa, lbb, lda, lcc, ldb, ldc;
    extern logical lde_(doublereal *, doublereal *, integer *);
    doublereal als, bls, err, beta;
    integer ldas, ldbs, ldcs;
    logical same, null;
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical isame[13], trana, tranb;
    integer nargs;
    logical reset;
    extern /* Subroutine */ int dprcn1_(integer *, integer *, char *, integer 
	    *, char *, char *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *), cdgemm_(integer *, char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    char tranas[1], tranbs[1], transa[1], transb[1];
    doublereal errmax;

    /* Fortran I/O blocks */
    static cilist io___128 = { 0, 0, 0, fmt_9994, 0 };
    static cilist io___131 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___133 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___134 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___135 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___137 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DGEMM. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --idim;
    --alf;
    --bet;
    --g;
    --ct;
    --cs;
    --cc;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --bs;
    --bb;
    b_dim1 = *nmax;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    --as;
    --aa;
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */

    nargs = 13;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;

    i__1 = *nidim;
    for (im = 1; im <= i__1; ++im) {
	m = idim[im];

	i__2 = *nidim;
	for (in = 1; in <= i__2; ++in) {
	    n = idim[in];
/*           Set LDC to 1 more than minimum value if room. */
	    ldc = m;
	    if (ldc < *nmax) {
		++ldc;
	    }
/*           Skip tests if not enough room. */
	    if (ldc > *nmax) {
		goto L100;
	    }
	    lcc = ldc * n;
	    null = n <= 0 || m <= 0;

	    i__3 = *nidim;
	    for (ik = 1; ik <= i__3; ++ik) {
		k = idim[ik];

		for (ica = 1; ica <= 3; ++ica) {
		    *(unsigned char *)transa = *(unsigned char *)&ich[ica - 1]
			    ;
		    trana = *(unsigned char *)transa == 'T' || *(unsigned 
			    char *)transa == 'C';

		    if (trana) {
			ma = k;
			na = m;
		    } else {
			ma = m;
			na = k;
		    }
/*                 Set LDA to 1 more than minimum value if room. */
		    lda = ma;
		    if (lda < *nmax) {
			++lda;
		    }
/*                 Skip tests if not enough room. */
		    if (lda > *nmax) {
			goto L80;
		    }
		    laa = lda * na;

/*                 Generate the matrix A. */

		    dmake_("GE", " ", " ", &ma, &na, &a[a_offset], nmax, &aa[
			    1], &lda, &reset, &c_b104);

		    for (icb = 1; icb <= 3; ++icb) {
			*(unsigned char *)transb = *(unsigned char *)&ich[icb 
				- 1];
			tranb = *(unsigned char *)transb == 'T' || *(unsigned 
				char *)transb == 'C';

			if (tranb) {
			    mb = n;
			    nb = k;
			} else {
			    mb = k;
			    nb = n;
			}
/*                    Set LDB to 1 more than minimum value if room. */
			ldb = mb;
			if (ldb < *nmax) {
			    ++ldb;
			}
/*                    Skip tests if not enough room. */
			if (ldb > *nmax) {
			    goto L70;
			}
			lbb = ldb * nb;

/*                    Generate the matrix B. */

			dmake_("GE", " ", " ", &mb, &nb, &b[b_offset], nmax, &
				bb[1], &ldb, &reset, &c_b104);

			i__4 = *nalf;
			for (ia = 1; ia <= i__4; ++ia) {
			    alpha = alf[ia];

			    i__5 = *nbet;
			    for (ib = 1; ib <= i__5; ++ib) {
				beta = bet[ib];

/*                          Generate the matrix C. */

				dmake_("GE", " ", " ", &m, &n, &c__[c_offset],
					 nmax, &cc[1], &ldc, &reset, &c_b104);

				++nc;

/*                          Save every datum before calling the */
/*                          subroutine. */

				*(unsigned char *)tranas = *(unsigned char *)
					transa;
				*(unsigned char *)tranbs = *(unsigned char *)
					transb;
				ms = m;
				ns = n;
				ks = k;
				als = alpha;
				i__6 = laa;
				for (i__ = 1; i__ <= i__6; ++i__) {
				    as[i__] = aa[i__];
/* L10: */
				}
				ldas = lda;
				i__6 = lbb;
				for (i__ = 1; i__ <= i__6; ++i__) {
				    bs[i__] = bb[i__];
/* L20: */
				}
				ldbs = ldb;
				bls = beta;
				i__6 = lcc;
				for (i__ = 1; i__ <= i__6; ++i__) {
				    cs[i__] = cc[i__];
/* L30: */
				}
				ldcs = ldc;

/*                          Call the subroutine. */

				if (*trace) {
				    dprcn1_(ntra, &nc, sname, iorder, transa, 
					    transb, &m, &n, &k, &alpha, &lda, 
					    &ldb, &beta, &ldc);
				}
				if (*rewi) {
				    al__1.aerr = 0;
				    al__1.aunit = *ntra;
				    f_rew(&al__1);
				}
				cdgemm_(iorder, transa, transb, &m, &n, &k, &
					alpha, &aa[1], &lda, &bb[1], &ldb, &
					beta, &cc[1], &ldc);

/*                          Check if error-exit was taken incorrectly. */

				if (! infoc_1.ok) {
				    io___128.ciunit = *nout;
				    s_wsfe(&io___128);
				    e_wsfe();
				    *fatal = TRUE_;
				    goto L120;
				}

/*                          See what data changed inside subroutines. */

				isame[0] = *(unsigned char *)transa == *(
					unsigned char *)tranas;
				isame[1] = *(unsigned char *)transb == *(
					unsigned char *)tranbs;
				isame[2] = ms == m;
				isame[3] = ns == n;
				isame[4] = ks == k;
				isame[5] = als == alpha;
				isame[6] = lde_(&as[1], &aa[1], &laa);
				isame[7] = ldas == lda;
				isame[8] = lde_(&bs[1], &bb[1], &lbb);
				isame[9] = ldbs == ldb;
				isame[10] = bls == beta;
				if (null) {
				    isame[11] = lde_(&cs[1], &cc[1], &lcc);
				} else {
				    isame[11] = lderes_("GE", " ", &m, &n, &
					    cs[1], &cc[1], &ldc);
				}
				isame[12] = ldcs == ldc;

/*                          If data was incorrectly changed, report */
/*                          and return. */

				same = TRUE_;
				i__6 = nargs;
				for (i__ = 1; i__ <= i__6; ++i__) {
				    same = same && isame[i__ - 1];
				    if (! isame[i__ - 1]) {
					io___131.ciunit = *nout;
					s_wsfe(&io___131);
					do_fio(&c__1, (char *)&i__, (ftnlen)
						sizeof(integer));
					e_wsfe();
				    }
/* L40: */
				}
				if (! same) {
				    *fatal = TRUE_;
				    goto L120;
				}

				if (! null) {

/*                             Check the result. */

				    dmmch_(transa, transb, &m, &n, &k, &alpha,
					     &a[a_offset], nmax, &b[b_offset],
					     nmax, &beta, &c__[c_offset], 
					    nmax, &ct[1], &g[1], &cc[1], &ldc,
					     eps, &err, fatal, nout, &c_true);
				    errmax = f2cmax(errmax,err);
/*                             If got really bad answer, report and */
/*                             return. */
				    if (*fatal) {
					goto L120;
				    }
				}

/* L50: */
			    }

/* L60: */
			}

L70:
			;
		    }

L80:
		    ;
		}

/* L90: */
	    }

L100:
	    ;
	}

/* L110: */
    }

/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___133.ciunit = *nout;
	    s_wsfe(&io___133);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___134.ciunit = *nout;
	    s_wsfe(&io___134);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___135.ciunit = *nout;
	    s_wsfe(&io___135);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___136.ciunit = *nout;
	    s_wsfe(&io___136);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L130;

L120:
    io___137.ciunit = *nout;
    s_wsfe(&io___137);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    dprcn1_(nout, &nc, sname, iorder, transa, transb, &m, &n, &k, &alpha, &
	    lda, &ldb, &beta, &ldc);

L130:
    return 0;

/* L9995: */

/*     End of DCHK1. */

} /* dchk1_ */

/* Subroutine */ int dprcn1_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *transa, char *transb, integer *m, integer *n, integer *
	k, doublereal *alpha, integer *lda, integer *ldb, doublereal *beta, 
	integer *ldc)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,a14,\002,\002,"
	    "a14,\002,\002,a14,\002,\002)";
    static char fmt_9994[] = "(20x,3(i3,\002,\002),f4.1,\002, A,\002,i3,\002"
	    ", B,\002,i3,\002,\002,f4.1,\002, \002,\002C,\002,i3,\002).\002)";

    /* Local variables */
    char crc[14], cta[14], ctb[14];

    /* Fortran I/O blocks */
    static cilist io___141 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___142 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)transa == 'N') {
	s_copy(cta, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transa == 'T') {
	s_copy(cta, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cta, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)transb == 'N') {
	s_copy(ctb, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transb == 'T') {
	s_copy(ctb, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(ctb, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___141.ciunit = *nout;
    s_wsfe(&io___141);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cta, (ftnlen)14);
    do_fio(&c__1, ctb, (ftnlen)14);
    e_wsfe();
    io___142.ciunit = *nout;
    s_wsfe(&io___142);
    do_fio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ldb), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*beta), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*ldc), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn1_ */


/* Subroutine */ int dchk2_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nbet, doublereal *bet, integer *nmax, doublereal *a, 
	doublereal *aa, doublereal *as, doublereal *b, doublereal *bb, 
	doublereal *bs, doublereal *c__, doublereal *cc, doublereal *cs, 
	doublereal *ct, doublereal *g, integer *iorder)
{
    /* Initialized data */

    static char ichs[2] = "LR";
    static char ichu[2] = "UL";

    /* Format strings */
    static char fmt_9994[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    alist al__1;

    /* Local variables */
    integer i__, m, n, ia, ib, na, nc, im, in, ms, ns, laa, lbb, lda, lcc, 
	    ldb, ldc;
    extern logical lde_(doublereal *, doublereal *, integer *);
    integer ics;
    doublereal als, bls;
    integer icu;
    doublereal err, beta;
    integer ldas, ldbs, ldcs;
    logical same;
    char side[1];
    logical left, null;
    char uplo[1];
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical isame[13];
    char sides[1];
    integer nargs;
    logical reset;
    char uplos[1];
    extern /* Subroutine */ int dprcn2_(integer *, integer *, char *, integer 
	    *, char *, char *, integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    extern /* Subroutine */ int cdsymm_(integer *, char *, char *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *);
    doublereal errmax;

    /* Fortran I/O blocks */
    static cilist io___180 = { 0, 0, 0, fmt_9994, 0 };
    static cilist io___183 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___185 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___186 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___187 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___188 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___189 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DSYMM. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --idim;
    --alf;
    --bet;
    --g;
    --ct;
    --cs;
    --cc;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --bs;
    --bb;
    b_dim1 = *nmax;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    --as;
    --aa;
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */

    nargs = 12;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;

    i__1 = *nidim;
    for (im = 1; im <= i__1; ++im) {
	m = idim[im];

	i__2 = *nidim;
	for (in = 1; in <= i__2; ++in) {
	    n = idim[in];
/*           Set LDC to 1 more than minimum value if room. */
	    ldc = m;
	    if (ldc < *nmax) {
		++ldc;
	    }
/*           Skip tests if not enough room. */
	    if (ldc > *nmax) {
		goto L90;
	    }
	    lcc = ldc * n;
	    null = n <= 0 || m <= 0;

/*           Set LDB to 1 more than minimum value if room. */
	    ldb = m;
	    if (ldb < *nmax) {
		++ldb;
	    }
/*           Skip tests if not enough room. */
	    if (ldb > *nmax) {
		goto L90;
	    }
	    lbb = ldb * n;

/*           Generate the matrix B. */

	    dmake_("GE", " ", " ", &m, &n, &b[b_offset], nmax, &bb[1], &ldb, &
		    reset, &c_b104);

	    for (ics = 1; ics <= 2; ++ics) {
		*(unsigned char *)side = *(unsigned char *)&ichs[ics - 1];
		left = *(unsigned char *)side == 'L';

		if (left) {
		    na = m;
		} else {
		    na = n;
		}
/*              Set LDA to 1 more than minimum value if room. */
		lda = na;
		if (lda < *nmax) {
		    ++lda;
		}
/*              Skip tests if not enough room. */
		if (lda > *nmax) {
		    goto L80;
		}
		laa = lda * na;

		for (icu = 1; icu <= 2; ++icu) {
		    *(unsigned char *)uplo = *(unsigned char *)&ichu[icu - 1];

/*                 Generate the symmetric matrix A. */

		    dmake_("SY", uplo, " ", &na, &na, &a[a_offset], nmax, &aa[
			    1], &lda, &reset, &c_b104);

		    i__3 = *nalf;
		    for (ia = 1; ia <= i__3; ++ia) {
			alpha = alf[ia];

			i__4 = *nbet;
			for (ib = 1; ib <= i__4; ++ib) {
			    beta = bet[ib];

/*                       Generate the matrix C. */

			    dmake_("GE", " ", " ", &m, &n, &c__[c_offset], 
				    nmax, &cc[1], &ldc, &reset, &c_b104);

			    ++nc;

/*                       Save every datum before calling the */
/*                       subroutine. */

			    *(unsigned char *)sides = *(unsigned char *)side;
			    *(unsigned char *)uplos = *(unsigned char *)uplo;
			    ms = m;
			    ns = n;
			    als = alpha;
			    i__5 = laa;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				as[i__] = aa[i__];
/* L10: */
			    }
			    ldas = lda;
			    i__5 = lbb;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				bs[i__] = bb[i__];
/* L20: */
			    }
			    ldbs = ldb;
			    bls = beta;
			    i__5 = lcc;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				cs[i__] = cc[i__];
/* L30: */
			    }
			    ldcs = ldc;

/*                       Call the subroutine. */

			    if (*trace) {
				dprcn2_(ntra, &nc, sname, iorder, side, uplo, 
					&m, &n, &alpha, &lda, &ldb, &beta, &
					ldc)
					;
			    }
			    if (*rewi) {
				al__1.aerr = 0;
				al__1.aunit = *ntra;
				f_rew(&al__1);
			    }
			    cdsymm_(iorder, side, uplo, &m, &n, &alpha, &aa[1]
				    , &lda, &bb[1], &ldb, &beta, &cc[1], &ldc);

/*                       Check if error-exit was taken incorrectly. */

			    if (! infoc_1.ok) {
				io___180.ciunit = *nout;
				s_wsfe(&io___180);
				e_wsfe();
				*fatal = TRUE_;
				goto L110;
			    }

/*                       See what data changed inside subroutines. */

			    isame[0] = *(unsigned char *)sides == *(unsigned 
				    char *)side;
			    isame[1] = *(unsigned char *)uplos == *(unsigned 
				    char *)uplo;
			    isame[2] = ms == m;
			    isame[3] = ns == n;
			    isame[4] = als == alpha;
			    isame[5] = lde_(&as[1], &aa[1], &laa);
			    isame[6] = ldas == lda;
			    isame[7] = lde_(&bs[1], &bb[1], &lbb);
			    isame[8] = ldbs == ldb;
			    isame[9] = bls == beta;
			    if (null) {
				isame[10] = lde_(&cs[1], &cc[1], &lcc);
			    } else {
				isame[10] = lderes_("GE", " ", &m, &n, &cs[1],
					 &cc[1], &ldc);
			    }
			    isame[11] = ldcs == ldc;

/*                       If data was incorrectly changed, report and */
/*                       return. */

			    same = TRUE_;
			    i__5 = nargs;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				same = same && isame[i__ - 1];
				if (! isame[i__ - 1]) {
				    io___183.ciunit = *nout;
				    s_wsfe(&io___183);
				    do_fio(&c__1, (char *)&i__, (ftnlen)
					    sizeof(integer));
				    e_wsfe();
				}
/* L40: */
			    }
			    if (! same) {
				*fatal = TRUE_;
				goto L110;
			    }

			    if (! null) {

/*                          Check the result. */

				if (left) {
				    dmmch_("N", "N", &m, &n, &m, &alpha, &a[
					    a_offset], nmax, &b[b_offset], 
					    nmax, &beta, &c__[c_offset], nmax,
					     &ct[1], &g[1], &cc[1], &ldc, eps,
					     &err, fatal, nout, &c_true);
				} else {
				    dmmch_("N", "N", &m, &n, &n, &alpha, &b[
					    b_offset], nmax, &a[a_offset], 
					    nmax, &beta, &c__[c_offset], nmax,
					     &ct[1], &g[1], &cc[1], &ldc, eps,
					     &err, fatal, nout, &c_true);
				}
				errmax = f2cmax(errmax,err);
/*                          If got really bad answer, report and */
/*                          return. */
				if (*fatal) {
				    goto L110;
				}
			    }

/* L50: */
			}

/* L60: */
		    }

/* L70: */
		}

L80:
		;
	    }

L90:
	    ;
	}

/* L100: */
    }

/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___185.ciunit = *nout;
	    s_wsfe(&io___185);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___186.ciunit = *nout;
	    s_wsfe(&io___186);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___187.ciunit = *nout;
	    s_wsfe(&io___187);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___188.ciunit = *nout;
	    s_wsfe(&io___188);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L120;

L110:
    io___189.ciunit = *nout;
    s_wsfe(&io___189);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    dprcn2_(nout, &nc, sname, iorder, side, uplo, &m, &n, &alpha, &lda, &ldb, 
	    &beta, &ldc);

L120:
    return 0;

/* L9995: */

/*     End of DCHK2. */

} /* dchk2_ */


/* Subroutine */ int dprcn2_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *side, char *uplo, integer *m, integer *n, doublereal *
	alpha, integer *lda, integer *ldb, doublereal *beta, integer *ldc)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,a14,\002,\002,"
	    "a14,\002,\002,a14,\002,\002)";
    static char fmt_9994[] = "(20x,2(i3,\002,\002),f4.1,\002, A,\002,i3,\002"
	    ", B,\002,i3,\002,\002,f4.1,\002, \002,\002C,\002,i3,\002).\002)";

    /* Local variables */
    char cs[14], cu[14], crc[14];

    /* Fortran I/O blocks */
    static cilist io___193 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___194 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)side == 'L') {
	s_copy(cs, "     CblasLeft", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cs, "    CblasRight", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)uplo == 'U') {
	s_copy(cu, "    CblasUpper", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cu, "    CblasLower", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___193.ciunit = *nout;
    s_wsfe(&io___193);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cs, (ftnlen)14);
    do_fio(&c__1, cu, (ftnlen)14);
    e_wsfe();
    io___194.ciunit = *nout;
    s_wsfe(&io___194);
    do_fio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ldb), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*beta), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*ldc), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn2_ */


/* Subroutine */ int dchk3_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nmax, doublereal *a, doublereal *aa, doublereal *as, 
	doublereal *b, doublereal *bb, doublereal *bs, doublereal *ct, 
	doublereal *g, doublereal *c__, integer *iorder)
{
    /* Initialized data */

    static char ichu[2] = "UL";
    static char icht[3] = "NTC";
    static char ichd[2] = "UN";
    static char ichs[2] = "LR";

    /* Format strings */
    static char fmt_9994[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    alist al__1;

    /* Local variables */
    integer i__, j, m, n, ia, na, nc, im, in, ms, ns, laa, icd, lbb, lda, ldb;
    extern logical lde_(doublereal *, doublereal *, integer *);
    integer ics;
    doublereal als;
    integer ict, icu;
    doublereal err;
    char diag[1];
    integer ldas, ldbs;
    logical same;
    char side[1];
    logical left, null;
    char uplo[1];
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    char diags[1];
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical isame[13];
    char sides[1];
    integer nargs;
    logical reset;
    char uplos[1];
    extern /* Subroutine */ int dprcn3_(integer *, integer *, char *, integer 
	    *, char *, char *, char *, char *, integer *, integer *, 
	    doublereal *, integer *, integer *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    extern /* Subroutine */ int cdtrmm_(integer *, char *, char *, char *, 
	    char *, integer *, integer *, doublereal *, doublereal *, integer 
	    *, doublereal *, integer *);
    char tranas[1], transa[1];
    extern /* Subroutine */ int cdtrsm_(integer *, char *, char *, char *, 
	    char *, integer *, integer *, doublereal *, doublereal *, integer 
	    *, doublereal *, integer *);
    doublereal errmax;

    /* Fortran I/O blocks */
    static cilist io___235 = { 0, 0, 0, fmt_9994, 0 };
    static cilist io___238 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___240 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___241 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___242 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___243 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___244 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DTRMM and DTRSM. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --idim;
    --alf;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --g;
    --ct;
    --bs;
    --bb;
    b_dim1 = *nmax;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    --as;
    --aa;
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */

    nargs = 11;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;
/*     Set up zero matrix for DMMCH. */
    i__1 = *nmax;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nmax;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    c__[i__ + j * c_dim1] = 0.;
/* L10: */
	}
/* L20: */
    }

    i__1 = *nidim;
    for (im = 1; im <= i__1; ++im) {
	m = idim[im];

	i__2 = *nidim;
	for (in = 1; in <= i__2; ++in) {
	    n = idim[in];
/*           Set LDB to 1 more than minimum value if room. */
	    ldb = m;
	    if (ldb < *nmax) {
		++ldb;
	    }
/*           Skip tests if not enough room. */
	    if (ldb > *nmax) {
		goto L130;
	    }
	    lbb = ldb * n;
	    null = m <= 0 || n <= 0;

	    for (ics = 1; ics <= 2; ++ics) {
		*(unsigned char *)side = *(unsigned char *)&ichs[ics - 1];
		left = *(unsigned char *)side == 'L';
		if (left) {
		    na = m;
		} else {
		    na = n;
		}
/*              Set LDA to 1 more than minimum value if room. */
		lda = na;
		if (lda < *nmax) {
		    ++lda;
		}
/*              Skip tests if not enough room. */
		if (lda > *nmax) {
		    goto L130;
		}
		laa = lda * na;

		for (icu = 1; icu <= 2; ++icu) {
		    *(unsigned char *)uplo = *(unsigned char *)&ichu[icu - 1];

		    for (ict = 1; ict <= 3; ++ict) {
			*(unsigned char *)transa = *(unsigned char *)&icht[
				ict - 1];

			for (icd = 1; icd <= 2; ++icd) {
			    *(unsigned char *)diag = *(unsigned char *)&ichd[
				    icd - 1];

			    i__3 = *nalf;
			    for (ia = 1; ia <= i__3; ++ia) {
				alpha = alf[ia];

/*                          Generate the matrix A. */

				dmake_("TR", uplo, diag, &na, &na, &a[
					a_offset], nmax, &aa[1], &lda, &reset,
					 &c_b104);

/*                          Generate the matrix B. */

				dmake_("GE", " ", " ", &m, &n, &b[b_offset], 
					nmax, &bb[1], &ldb, &reset, &c_b104);

				++nc;

/*                          Save every datum before calling the */
/*                          subroutine. */

				*(unsigned char *)sides = *(unsigned char *)
					side;
				*(unsigned char *)uplos = *(unsigned char *)
					uplo;
				*(unsigned char *)tranas = *(unsigned char *)
					transa;
				*(unsigned char *)diags = *(unsigned char *)
					diag;
				ms = m;
				ns = n;
				als = alpha;
				i__4 = laa;
				for (i__ = 1; i__ <= i__4; ++i__) {
				    as[i__] = aa[i__];
/* L30: */
				}
				ldas = lda;
				i__4 = lbb;
				for (i__ = 1; i__ <= i__4; ++i__) {
				    bs[i__] = bb[i__];
/* L40: */
				}
				ldbs = ldb;

/*                          Call the subroutine. */

				if (s_cmp(sname + 9, "mm", (ftnlen)2, (ftnlen)
					2) == 0) {
				    if (*trace) {
					dprcn3_(ntra, &nc, sname, iorder, 
						side, uplo, transa, diag, &m, 
						&n, &alpha, &lda, &ldb, (
						ftnlen)13, (ftnlen)1, (ftnlen)
						1, (ftnlen)1, (ftnlen)1);
				    }
				    if (*rewi) {
					al__1.aerr = 0;
					al__1.aunit = *ntra;
					f_rew(&al__1);
				    }
				    cdtrmm_(iorder, side, uplo, transa, diag, 
					    &m, &n, &alpha, &aa[1], &lda, &bb[
					    1], &ldb);
				} else if (s_cmp(sname + 9, "sm", (ftnlen)2, (
					ftnlen)2) == 0) {
				    if (*trace) {
					dprcn3_(ntra, &nc, sname, iorder, 
						side, uplo, transa, diag, &m, 
						&n, &alpha, &lda, &ldb, (
						ftnlen)13, (ftnlen)1, (ftnlen)
						1, (ftnlen)1, (ftnlen)1);
				    }
				    if (*rewi) {
					al__1.aerr = 0;
					al__1.aunit = *ntra;
					f_rew(&al__1);
				    }
				    cdtrsm_(iorder, side, uplo, transa, diag, 
					    &m, &n, &alpha, &aa[1], &lda, &bb[
					    1], &ldb);
				}

/*                          Check if error-exit was taken incorrectly. */

				if (! infoc_1.ok) {
				    io___235.ciunit = *nout;
				    s_wsfe(&io___235);
				    e_wsfe();
				    *fatal = TRUE_;
				    goto L150;
				}

/*                          See what data changed inside subroutines. */

				isame[0] = *(unsigned char *)sides == *(
					unsigned char *)side;
				isame[1] = *(unsigned char *)uplos == *(
					unsigned char *)uplo;
				isame[2] = *(unsigned char *)tranas == *(
					unsigned char *)transa;
				isame[3] = *(unsigned char *)diags == *(
					unsigned char *)diag;
				isame[4] = ms == m;
				isame[5] = ns == n;
				isame[6] = als == alpha;
				isame[7] = lde_(&as[1], &aa[1], &laa);
				isame[8] = ldas == lda;
				if (null) {
				    isame[9] = lde_(&bs[1], &bb[1], &lbb);
				} else {
				    isame[9] = lderes_("GE", " ", &m, &n, &bs[
					    1], &bb[1], &ldb);
				}
				isame[10] = ldbs == ldb;

/*                          If data was incorrectly changed, report and */
/*                          return. */

				same = TRUE_;
				i__4 = nargs;
				for (i__ = 1; i__ <= i__4; ++i__) {
				    same = same && isame[i__ - 1];
				    if (! isame[i__ - 1]) {
					io___238.ciunit = *nout;
					s_wsfe(&io___238);
					do_fio(&c__1, (char *)&i__, (ftnlen)
						sizeof(integer));
					e_wsfe();
				    }
/* L50: */
				}
				if (! same) {
				    *fatal = TRUE_;
				    goto L150;
				}

				if (! null) {
				    if (s_cmp(sname + 9, "mm", (ftnlen)2, (
					    ftnlen)2) == 0) {

/*                                Check the result. */

					if (left) {
					    dmmch_(transa, "N", &m, &n, &m, &
						    alpha, &a[a_offset], nmax,
						     &b[b_offset], nmax, &
						    c_b104, &c__[c_offset], 
						    nmax, &ct[1], &g[1], &bb[
						    1], &ldb, eps, &err, 
						    fatal, nout, &c_true, (
						    ftnlen)1, (ftnlen)1);
					} else {
					    dmmch_("N", transa, &m, &n, &n, &
						    alpha, &b[b_offset], nmax,
						     &a[a_offset], nmax, &
						    c_b104, &c__[c_offset], 
						    nmax, &ct[1], &g[1], &bb[
						    1], &ldb, eps, &err, 
						    fatal, nout, &c_true);
					}
				    } else if (s_cmp(sname + 9, "sm", (ftnlen)
					    2, (ftnlen)2) == 0) {

/*                                Compute approximation to original */
/*                                matrix. */

					i__4 = n;
					for (j = 1; j <= i__4; ++j) {
					    i__5 = m;
					    for (i__ = 1; i__ <= i__5; ++i__) 
						    {
			  c__[i__ + j * c_dim1] = bb[i__ + (j - 1) * ldb];
			  bb[i__ + (j - 1) * ldb] = alpha * b[i__ + j * 
				  b_dim1];
/* L60: */
					    }
/* L70: */
					}

					if (left) {
					    dmmch_(transa, "N", &m, &n, &m, &
						    c_b90, &a[a_offset], nmax,
						     &c__[c_offset], nmax, &
						    c_b104, &b[b_offset], 
						    nmax, &ct[1], &g[1], &bb[
						    1], &ldb, eps, &err, 
						    fatal, nout, &c_false);
					} else {
					    dmmch_("N", transa, &m, &n, &n, &
						    c_b90, &c__[c_offset], 
						    nmax, &a[a_offset], nmax, 
						    &c_b104, &b[b_offset], 
						    nmax, &ct[1], &g[1], &bb[
						    1], &ldb, eps, &err, 
						    fatal, nout, &c_false);
					}
				    }
				    errmax = f2cmax(errmax,err);
/*                             If got really bad answer, report and */
/*                             return. */
				    if (*fatal) {
					goto L150;
				    }
				}

/* L80: */
			    }

/* L90: */
			}

/* L100: */
		    }

/* L110: */
		}

/* L120: */
	    }

L130:
	    ;
	}

/* L140: */
    }

/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___240.ciunit = *nout;
	    s_wsfe(&io___240);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___241.ciunit = *nout;
	    s_wsfe(&io___241);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___242.ciunit = *nout;
	    s_wsfe(&io___242);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___243.ciunit = *nout;
	    s_wsfe(&io___243);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L160;

L150:
    io___244.ciunit = *nout;
    s_wsfe(&io___244);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    if (*trace) {
	dprcn3_(ntra, &nc, sname, iorder, side, uplo, transa, diag, &m, &n, &
		alpha, &lda, &ldb);
    }

L160:
    return 0;

/* L9995: */

/*     End of DCHK3. */

} /* dchk3_ */


/* Subroutine */ int dprcn3_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *side, char *uplo, char *transa, char *diag, integer *m,
	 integer *n, doublereal *alpha, integer *lda, integer *ldb)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,a14,\002,\002,"
	    "a14,\002,\002,a14,\002,\002)";
    static char fmt_9994[] = "(22x,2(a14,\002,\002),2(i3,\002,\002),f4.1,"
	    "\002, A,\002,i3,\002, B,\002,i3,\002).\002)";

    /* Local variables */
    char ca[14], cd[14], cs[14], cu[14], crc[14];

    /* Fortran I/O blocks */
    static cilist io___250 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___251 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)side == 'L') {
	s_copy(cs, "     CblasLeft", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cs, "    CblasRight", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)uplo == 'U') {
	s_copy(cu, "    CblasUpper", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cu, "    CblasLower", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)transa == 'N') {
	s_copy(ca, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transa == 'T') {
	s_copy(ca, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(ca, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)diag == 'N') {
	s_copy(cd, "  CblasNonUnit", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cd, "     CblasUnit", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___250.ciunit = *nout;
    s_wsfe(&io___250);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cs, (ftnlen)14);
    do_fio(&c__1, cu, (ftnlen)14);
    e_wsfe();
    io___251.ciunit = *nout;
    s_wsfe(&io___251);
    do_fio(&c__1, ca, (ftnlen)14);
    do_fio(&c__1, cd, (ftnlen)14);
    do_fio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ldb), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn3_ */


/* Subroutine */ int dchk4_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nbet, doublereal *bet, integer *nmax, doublereal *a, 
	doublereal *aa, doublereal *as, doublereal *b, doublereal *bb, 
	doublereal *bs, doublereal *c__, doublereal *cc, doublereal *cs, 
	doublereal *ct, doublereal *g, integer *iorder)
{
    /* Initialized data */

    static char icht[3] = "NTC";
    static char ichu[2] = "UL";

    /* Format strings */
    static char fmt_9993[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9995[] = "(\002      THESE ARE THE RESULTS FOR COLUMN"
	    " \002,i3)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    alist al__1;

    /* Local variables */
    integer i__, j, k, n, ia, ib, jc, ma, na, nc, ik, in, jj, lj, ks, ns, laa,
	     lda, lcc, ldc;
    extern logical lde_(doublereal *, doublereal *, integer *);
    doublereal als;
    integer ict, icu;
    doublereal err, beta;
    integer ldas, ldcs;
    logical same;
    doublereal bets;
    logical tran, null;
    char uplo[1];
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical isame[13];
    integer nargs;
    logical reset;
    char trans[1];
    logical upper;
    char uplos[1];
    extern /* Subroutine */ int dprcn4_(integer *, integer *, char *, integer 
	    *, char *, char *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    doublereal errmax;
    extern /* Subroutine */ int cdsyrk_(integer *, char *, char *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, integer *);
    char transs[1];

    /* Fortran I/O blocks */
    static cilist io___288 = { 0, 0, 0, fmt_9993, 0 };
    static cilist io___291 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___297 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___298 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___299 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___300 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___301 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___302 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DSYRK. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --idim;
    --alf;
    --bet;
    --g;
    --ct;
    --cs;
    --cc;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --bs;
    --bb;
    b_dim1 = *nmax;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    --as;
    --aa;
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */

    nargs = 10;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;

    i__1 = *nidim;
    for (in = 1; in <= i__1; ++in) {
	n = idim[in];
/*        Set LDC to 1 more than minimum value if room. */
	ldc = n;
	if (ldc < *nmax) {
	    ++ldc;
	}
/*        Skip tests if not enough room. */
	if (ldc > *nmax) {
	    goto L100;
	}
	lcc = ldc * n;
	null = n <= 0;

	i__2 = *nidim;
	for (ik = 1; ik <= i__2; ++ik) {
	    k = idim[ik];

	    for (ict = 1; ict <= 3; ++ict) {
		*(unsigned char *)trans = *(unsigned char *)&icht[ict - 1];
		tran = *(unsigned char *)trans == 'T' || *(unsigned char *)
			trans == 'C';
		if (tran) {
		    ma = k;
		    na = n;
		} else {
		    ma = n;
		    na = k;
		}
/*              Set LDA to 1 more than minimum value if room. */
		lda = ma;
		if (lda < *nmax) {
		    ++lda;
		}
/*              Skip tests if not enough room. */
		if (lda > *nmax) {
		    goto L80;
		}
		laa = lda * na;

/*              Generate the matrix A. */

		dmake_("GE", " ", " ", &ma, &na, &a[a_offset], nmax, &aa[1], &
			lda, &reset, &c_b104)
			;

		for (icu = 1; icu <= 2; ++icu) {
		    *(unsigned char *)uplo = *(unsigned char *)&ichu[icu - 1];
		    upper = *(unsigned char *)uplo == 'U';

		    i__3 = *nalf;
		    for (ia = 1; ia <= i__3; ++ia) {
			alpha = alf[ia];

			i__4 = *nbet;
			for (ib = 1; ib <= i__4; ++ib) {
			    beta = bet[ib];

/*                       Generate the matrix C. */

			    dmake_("SY", uplo, " ", &n, &n, &c__[c_offset], 
				    nmax, &cc[1], &ldc, &reset, &c_b104);

			    ++nc;

/*                       Save every datum before calling the subroutine. */

			    *(unsigned char *)uplos = *(unsigned char *)uplo;
			    *(unsigned char *)transs = *(unsigned char *)
				    trans;
			    ns = n;
			    ks = k;
			    als = alpha;
			    i__5 = laa;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				as[i__] = aa[i__];
/* L10: */
			    }
			    ldas = lda;
			    bets = beta;
			    i__5 = lcc;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				cs[i__] = cc[i__];
/* L20: */
			    }
			    ldcs = ldc;

/*                       Call the subroutine. */

			    if (*trace) {
				dprcn4_(ntra, &nc, sname, iorder, uplo, trans,
					 &n, &k, &alpha, &lda, &beta, &ldc);
			    }
			    if (*rewi) {
				al__1.aerr = 0;
				al__1.aunit = *ntra;
				f_rew(&al__1);
			    }
			    cdsyrk_(iorder, uplo, trans, &n, &k, &alpha, &aa[
				    1], &lda, &beta, &cc[1], &ldc);

/*                       Check if error-exit was taken incorrectly. */

			    if (! infoc_1.ok) {
				io___288.ciunit = *nout;
				s_wsfe(&io___288);
				e_wsfe();
				*fatal = TRUE_;
				goto L120;
			    }

/*                       See what data changed inside subroutines. */

			    isame[0] = *(unsigned char *)uplos == *(unsigned 
				    char *)uplo;
			    isame[1] = *(unsigned char *)transs == *(unsigned 
				    char *)trans;
			    isame[2] = ns == n;
			    isame[3] = ks == k;
			    isame[4] = als == alpha;
			    isame[5] = lde_(&as[1], &aa[1], &laa);
			    isame[6] = ldas == lda;
			    isame[7] = bets == beta;
			    if (null) {
				isame[8] = lde_(&cs[1], &cc[1], &lcc);
			    } else {
				isame[8] = lderes_("SY", uplo, &n, &n, &cs[1],
					 &cc[1], &ldc);
			    }
			    isame[9] = ldcs == ldc;

/*                       If data was incorrectly changed, report and */
/*                       return. */

			    same = TRUE_;
			    i__5 = nargs;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				same = same && isame[i__ - 1];
				if (! isame[i__ - 1]) {
				    io___291.ciunit = *nout;
				    s_wsfe(&io___291);
				    do_fio(&c__1, (char *)&i__, (ftnlen)
					    sizeof(integer));
				    e_wsfe();
				}
/* L30: */
			    }
			    if (! same) {
				*fatal = TRUE_;
				goto L120;
			    }

			    if (! null) {

/*                          Check the result column by column. */

				jc = 1;
				i__5 = n;
				for (j = 1; j <= i__5; ++j) {
				    if (upper) {
					jj = 1;
					lj = j;
				    } else {
					jj = j;
					lj = n - j + 1;
				    }
				    if (tran) {
					dmmch_("T", "N", &lj, &c__1, &k, &
						alpha, &a[jj * a_dim1 + 1], 
						nmax, &a[j * a_dim1 + 1], 
						nmax, &beta, &c__[jj + j * 
						c_dim1], nmax, &ct[1], &g[1], 
						&cc[jc], &ldc, eps, &err, 
						fatal, nout, &c_true);
				    } else {
					dmmch_("N", "T", &lj, &c__1, &k, &
						alpha, &a[jj + a_dim1], nmax, 
						&a[j + a_dim1], nmax, &beta, &
						c__[jj + j * c_dim1], nmax, &
						ct[1], &g[1], &cc[jc], &ldc, 
						eps, &err, fatal, nout, &
						c_true);
				    }
				    if (upper) {
					jc += ldc;
				    } else {
					jc = jc + ldc + 1;
				    }
				    errmax = f2cmax(errmax,err);
/*                             If got really bad answer, report and */
/*                             return. */
				    if (*fatal) {
					goto L110;
				    }
/* L40: */
				}
			    }

/* L50: */
			}

/* L60: */
		    }

/* L70: */
		}

L80:
		;
	    }

/* L90: */
	}

L100:
	;
    }

/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___297.ciunit = *nout;
	    s_wsfe(&io___297);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___298.ciunit = *nout;
	    s_wsfe(&io___298);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___299.ciunit = *nout;
	    s_wsfe(&io___299);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___300.ciunit = *nout;
	    s_wsfe(&io___300);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L130;

L110:
    if (n > 1) {
	io___301.ciunit = *nout;
	s_wsfe(&io___301);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
    }

L120:
    io___302.ciunit = *nout;
    s_wsfe(&io___302);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    dprcn4_(nout, &nc, sname, iorder, uplo, trans, &n, &k, &alpha, &lda, &
	    beta, &ldc);

L130:
    return 0;

/* L9994: */

/*     End of DCHK4. */

} /* dchk4_ */


/* Subroutine */ int dprcn4_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *uplo, char *transa, integer *n, integer *k, doublereal 
	*alpha, integer *lda, doublereal *beta, integer *ldc)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,3(a14,\002,"
	    "\002))";
    static char fmt_9994[] = "(20x,2(i3,\002,\002),f4.1,\002, A,\002,i3"
	    ",\002,\002,f4.1,\002, C,\002,i3,\002).\002)";

    /* Local variables */
    char ca[14], cu[14], crc[14];

    /* Fortran I/O blocks */
    static cilist io___306 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___307 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)uplo == 'U') {
	s_copy(cu, "    CblasUpper", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cu, "    CblasLower", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)transa == 'N') {
	s_copy(ca, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transa == 'T') {
	s_copy(ca, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(ca, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___306.ciunit = *nout;
    s_wsfe(&io___306);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cu, (ftnlen)14);
    do_fio(&c__1, ca, (ftnlen)14);
    e_wsfe();
    io___307.ciunit = *nout;
    s_wsfe(&io___307);
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*beta), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*ldc), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn4_ */


/* Subroutine */ int dchk5_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nbet, doublereal *bet, integer *nmax, doublereal *ab, 
	doublereal *aa, doublereal *as, doublereal *bb, doublereal *bs, 
	doublereal *c__, doublereal *cc, doublereal *cs, doublereal *ct, 
	doublereal *g, doublereal *w, integer *iorder)
{
    /* Initialized data */

    static char icht[3] = "NTC";
    static char ichu[2] = "UL";

    /* Format strings */
    static char fmt_9993[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9995[] = "(\002      THESE ARE THE RESULTS FOR COLUMN"
	    " \002,i3)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8;
    alist al__1;

    /* Local variables */
    integer i__, j, k, n, ia, ib, jc, ma, na, nc, ik, in, jj, lj, ks, ns, laa,
	     lbb, lda, lcc, ldb, ldc;
    extern logical lde_(doublereal *, doublereal *, integer *);
    doublereal als;
    integer ict, icu;
    doublereal err;
    integer jjab;
    doublereal beta;
    integer ldas, ldbs, ldcs;
    logical same;
    doublereal bets;
    logical tran, null;
    char uplo[1];
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    extern /* Subroutine */ int dmmch_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    logical isame[13];
    integer nargs;
    logical reset;
    char trans[1];
    logical upper;
    char uplos[1];
    extern /* Subroutine */ int dprcn5_(integer *, integer *, char *, integer 
	    *, char *, char *, integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    doublereal errmax;
    char transs[1];
    extern /* Subroutine */ int cdsyr2k_(integer *, char *, char *, integer *,
	     integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___347 = { 0, 0, 0, fmt_9993, 0 };
    static cilist io___350 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___357 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___358 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___359 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___360 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___361 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___362 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DSYR2K. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --idim;
    --alf;
    --bet;
    --w;
    --g;
    --ct;
    --cs;
    --cc;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --bs;
    --bb;
    --as;
    --aa;
    --ab;

    /* Function Body */

    nargs = 12;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;

    i__1 = *nidim;
    for (in = 1; in <= i__1; ++in) {
	n = idim[in];
/*        Set LDC to 1 more than minimum value if room. */
	ldc = n;
	if (ldc < *nmax) {
	    ++ldc;
	}
/*        Skip tests if not enough room. */
	if (ldc > *nmax) {
	    goto L130;
	}
	lcc = ldc * n;
	null = n <= 0;

	i__2 = *nidim;
	for (ik = 1; ik <= i__2; ++ik) {
	    k = idim[ik];

	    for (ict = 1; ict <= 3; ++ict) {
		*(unsigned char *)trans = *(unsigned char *)&icht[ict - 1];
		tran = *(unsigned char *)trans == 'T' || *(unsigned char *)
			trans == 'C';
		if (tran) {
		    ma = k;
		    na = n;
		} else {
		    ma = n;
		    na = k;
		}
/*              Set LDA to 1 more than minimum value if room. */
		lda = ma;
		if (lda < *nmax) {
		    ++lda;
		}
/*              Skip tests if not enough room. */
		if (lda > *nmax) {
		    goto L110;
		}
		laa = lda * na;

/*              Generate the matrix A. */

		if (tran) {
		    i__3 = *nmax << 1;
		    dmake_("GE", " ", " ", &ma, &na, &ab[1], &i__3, &aa[1], &
			    lda, &reset, &c_b104);
		} else {
		    dmake_("GE", " ", " ", &ma, &na, &ab[1], nmax, &aa[1], &
			    lda, &reset, &c_b104);
		}

/*              Generate the matrix B. */

		ldb = lda;
		lbb = laa;
		if (tran) {
		    i__3 = *nmax << 1;
		    dmake_("GE", " ", " ", &ma, &na, &ab[k + 1], &i__3, &bb[1]
			    , &ldb, &reset, &c_b104);
		} else {
		    dmake_("GE", " ", " ", &ma, &na, &ab[k * *nmax + 1], nmax,
			     &bb[1], &ldb, &reset, &c_b104);
		}

		for (icu = 1; icu <= 2; ++icu) {
		    *(unsigned char *)uplo = *(unsigned char *)&ichu[icu - 1];
		    upper = *(unsigned char *)uplo == 'U';

		    i__3 = *nalf;
		    for (ia = 1; ia <= i__3; ++ia) {
			alpha = alf[ia];

			i__4 = *nbet;
			for (ib = 1; ib <= i__4; ++ib) {
			    beta = bet[ib];

/*                       Generate the matrix C. */

			    dmake_("SY", uplo, " ", &n, &n, &c__[c_offset], 
				    nmax, &cc[1], &ldc, &reset, &c_b104);

			    ++nc;

/*                       Save every datum before calling the subroutine. */

			    *(unsigned char *)uplos = *(unsigned char *)uplo;
			    *(unsigned char *)transs = *(unsigned char *)
				    trans;
			    ns = n;
			    ks = k;
			    als = alpha;
			    i__5 = laa;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				as[i__] = aa[i__];
/* L10: */
			    }
			    ldas = lda;
			    i__5 = lbb;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				bs[i__] = bb[i__];
/* L20: */
			    }
			    ldbs = ldb;
			    bets = beta;
			    i__5 = lcc;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				cs[i__] = cc[i__];
/* L30: */
			    }
			    ldcs = ldc;

/*                       Call the subroutine. */

			    if (*trace) {
				dprcn5_(ntra, &nc, sname, iorder, uplo, trans,
					 &n, &k, &alpha, &lda, &ldb, &beta, &
					ldc)
					;
			    }
			    if (*rewi) {
				al__1.aerr = 0;
				al__1.aunit = *ntra;
				f_rew(&al__1);
			    }
			    cdsyr2k_(iorder, uplo, trans, &n, &k, &alpha, &aa[
				    1], &lda, &bb[1], &ldb, &beta, &cc[1], &
				    ldc);

/*                       Check if error-exit was taken incorrectly. */

			    if (! infoc_1.ok) {
				io___347.ciunit = *nout;
				s_wsfe(&io___347);
				e_wsfe();
				*fatal = TRUE_;
				goto L150;
			    }

/*                       See what data changed inside subroutines. */

			    isame[0] = *(unsigned char *)uplos == *(unsigned 
				    char *)uplo;
			    isame[1] = *(unsigned char *)transs == *(unsigned 
				    char *)trans;
			    isame[2] = ns == n;
			    isame[3] = ks == k;
			    isame[4] = als == alpha;
			    isame[5] = lde_(&as[1], &aa[1], &laa);
			    isame[6] = ldas == lda;
			    isame[7] = lde_(&bs[1], &bb[1], &lbb);
			    isame[8] = ldbs == ldb;
			    isame[9] = bets == beta;
			    if (null) {
				isame[10] = lde_(&cs[1], &cc[1], &lcc);
			    } else {
				isame[10] = lderes_("SY", uplo, &n, &n, &cs[1]
					, &cc[1], &ldc);
			    }
			    isame[11] = ldcs == ldc;

/*                       If data was incorrectly changed, report and */
/*                       return. */

			    same = TRUE_;
			    i__5 = nargs;
			    for (i__ = 1; i__ <= i__5; ++i__) {
				same = same && isame[i__ - 1];
				if (! isame[i__ - 1]) {
				    io___350.ciunit = *nout;
				    s_wsfe(&io___350);
				    do_fio(&c__1, (char *)&i__, (ftnlen)
					    sizeof(integer));
				    e_wsfe();
				}
/* L40: */
			    }
			    if (! same) {
				*fatal = TRUE_;
				goto L150;
			    }

			    if (! null) {

/*                          Check the result column by column. */

				jjab = 1;
				jc = 1;
				i__5 = n;
				for (j = 1; j <= i__5; ++j) {
				    if (upper) {
					jj = 1;
					lj = j;
				    } else {
					jj = j;
					lj = n - j + 1;
				    }
				    if (tran) {
					i__6 = k;
					for (i__ = 1; i__ <= i__6; ++i__) {
					    w[i__] = ab[(j - 1 << 1) * *nmax 
						    + k + i__];
					    w[k + i__] = ab[(j - 1 << 1) * *
						    nmax + i__];
/* L50: */
					}
					i__6 = k << 1;
					i__7 = *nmax << 1;
					i__8 = *nmax << 1;
					dmmch_("T", "N", &lj, &c__1, &i__6, &
						alpha, &ab[jjab], &i__7, &w[1]
						, &i__8, &beta, &c__[jj + j * 
						c_dim1], nmax, &ct[1], &g[1], 
						&cc[jc], &ldc, eps, &err, 
						fatal, nout, &c_true);
				    } else {
					i__6 = k;
					for (i__ = 1; i__ <= i__6; ++i__) {
					    w[i__] = ab[(k + i__ - 1) * *nmax 
						    + j];
					    w[k + i__] = ab[(i__ - 1) * *nmax 
						    + j];
/* L60: */
					}
					i__6 = k << 1;
					i__7 = *nmax << 1;
					dmmch_("N", "N", &lj, &c__1, &i__6, &
						alpha, &ab[jj], nmax, &w[1], &
						i__7, &beta, &c__[jj + j * 
						c_dim1], nmax, &ct[1], &g[1], 
						&cc[jc], &ldc, eps, &err, 
						fatal, nout, &c_true);
				    }
				    if (upper) {
					jc += ldc;
				    } else {
					jc = jc + ldc + 1;
					if (tran) {
					    jjab += *nmax << 1;
					}
				    }
				    errmax = f2cmax(errmax,err);
/*                             If got really bad answer, report and */
/*                             return. */
				    if (*fatal) {
					goto L140;
				    }
/* L70: */
				}
			    }

/* L80: */
			}

/* L90: */
		    }

/* L100: */
		}

L110:
		;
	    }

/* L120: */
	}

L130:
	;
    }

/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___357.ciunit = *nout;
	    s_wsfe(&io___357);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___358.ciunit = *nout;
	    s_wsfe(&io___358);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___359.ciunit = *nout;
	    s_wsfe(&io___359);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___360.ciunit = *nout;
	    s_wsfe(&io___360);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L160;

L140:
    if (n > 1) {
	io___361.ciunit = *nout;
	s_wsfe(&io___361);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
    }

L150:
    io___362.ciunit = *nout;
    s_wsfe(&io___362);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    dprcn5_(nout, &nc, sname, iorder, uplo, trans, &n, &k, &alpha, &lda, &ldb,
	     &beta, &ldc);

L160:
    return 0;

/* L9994: */

/*     End of DCHK5. */

} /* dchk5_ */


/* Subroutine */ int dprcn5_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *uplo, char *transa, integer *n, integer *k, doublereal 
	*alpha, integer *lda, integer *ldb, doublereal *beta, integer *ldc)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,3(a14,\002,"
	    "\002))";
    static char fmt_9994[] = "(20x,2(i3,\002,\002),f4.1,\002, A,\002,i3,\002"
	    ", B\002,i3,\002,\002,f4.1,\002, C,\002,i3,\002).\002)";

    /* Local variables */
    char ca[14], cu[14], crc[14];

    /* Fortran I/O blocks */
    static cilist io___366 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___367 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)uplo == 'U') {
	s_copy(cu, "    CblasUpper", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cu, "    CblasLower", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)transa == 'N') {
	s_copy(ca, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transa == 'T') {
	s_copy(ca, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(ca, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___366.ciunit = *nout;
    s_wsfe(&io___366);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cu, (ftnlen)14);
    do_fio(&c__1, ca, (ftnlen)14);
    e_wsfe();
    io___367.ciunit = *nout;
    s_wsfe(&io___367);
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ldb), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*beta), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*ldc), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn5_ */


/* Subroutine */ int dmake_(char *type__, char *uplo, char *diag, integer *m, 
	integer *n, doublereal *a, integer *nmax, doublereal *aa, integer *
	lda, logical *reset, doublereal *transl)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    integer i__, j;
    logical gen, tri, sym;
    extern doublereal dbeg_(logical *);
    integer ibeg, iend;
    logical unit, lower, upper;


/*  Generates values for an M by N matrix A. */
/*  Stores the values in the array AA in the data structure required */
/*  by the routine, with unwanted elements set to rogue value. */

/*  TYPE is 'GE', 'SY' or 'TR'. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --aa;

    /* Function Body */
    gen = s_cmp(type__, "GE", (ftnlen)2, (ftnlen)2) == 0;
    sym = s_cmp(type__, "SY", (ftnlen)2, (ftnlen)2) == 0;
    tri = s_cmp(type__, "TR", (ftnlen)2, (ftnlen)2) == 0;
    upper = (sym || tri) && *(unsigned char *)uplo == 'U';
    lower = (sym || tri) && *(unsigned char *)uplo == 'L';
    unit = tri && *(unsigned char *)diag == 'U';

/*     Generate data in array A. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (gen || upper && i__ <= j || lower && i__ >= j) {
		a[i__ + j * a_dim1] = dbeg_(reset) + *transl;
		if (i__ != j) {
/*                 Set some elements to zero */
		    if (*n > 3 && j == *n / 2) {
			a[i__ + j * a_dim1] = 0.;
		    }
		    if (sym) {
			a[j + i__ * a_dim1] = a[i__ + j * a_dim1];
		    } else if (tri) {
			a[j + i__ * a_dim1] = 0.;
		    }
		}
	    }
/* L10: */
	}
	if (tri) {
	    a[j + j * a_dim1] += 1.;
	}
	if (unit) {
	    a[j + j * a_dim1] = 1.;
	}
/* L20: */
    }

/*     Store elements in array AS in data structure required by routine. */

    if (s_cmp(type__, "GE", (ftnlen)2, (ftnlen)2) == 0) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *m;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		aa[i__ + (j - 1) * *lda] = a[i__ + j * a_dim1];
/* L30: */
	    }
	    i__2 = *lda;
	    for (i__ = *m + 1; i__ <= i__2; ++i__) {
		aa[i__ + (j - 1) * *lda] = -1e10;
/* L40: */
	    }
/* L50: */
	}
    } else if (s_cmp(type__, "SY", (ftnlen)2, (ftnlen)2) == 0 || s_cmp(type__,
	     "TR", (ftnlen)2, (ftnlen)2) == 0) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    if (upper) {
		ibeg = 1;
		if (unit) {
		    iend = j - 1;
		} else {
		    iend = j;
		}
	    } else {
		if (unit) {
		    ibeg = j + 1;
		} else {
		    ibeg = j;
		}
		iend = *n;
	    }
	    i__2 = ibeg - 1;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		aa[i__ + (j - 1) * *lda] = -1e10;
/* L60: */
	    }
	    i__2 = iend;
	    for (i__ = ibeg; i__ <= i__2; ++i__) {
		aa[i__ + (j - 1) * *lda] = a[i__ + j * a_dim1];
/* L70: */
	    }
	    i__2 = *lda;
	    for (i__ = iend + 1; i__ <= i__2; ++i__) {
		aa[i__ + (j - 1) * *lda] = -1e10;
/* L80: */
	    }
/* L90: */
	}
    }
    return 0;

/*     End of DMAKE. */

} /* dmake_ */

/* Subroutine */ int dmmch_(char *transa, char *transb, integer *m, integer *
	n, integer *kk, doublereal *alpha, doublereal *a, integer *lda, 
	doublereal *b, integer *ldb, doublereal *beta, doublereal *c__, 
	integer *ldc, doublereal *ct, doublereal *g, doublereal *cc, integer *
	ldcc, doublereal *eps, doublereal *err, logical *fatal, integer *nout,
	 logical *mv)
{
    /* Format strings */
    static char fmt_9999[] = "(\002 ******* FATAL ERROR - COMPUTED RESULT IS"
	    " LESS THAN HAL\002,\002F ACCURATE *******\002,/\002           EX"
	    "PECTED RESULT   COMPU\002,\002TED RESULT\002)";
    static char fmt_9998[] = "(1x,i7,2g18.6)";
    static char fmt_9997[] = "(\002      THESE ARE THE RESULTS FOR COLUMN"
	    " \002,i3)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, cc_dim1, 
	    cc_offset, i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Local variables */
    integer i__, j, k;
    doublereal erri;
    logical trana, tranb;

    /* Fortran I/O blocks */
    static cilist io___384 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___385 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___386 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___387 = { 0, 0, 0, fmt_9997, 0 };



/*  Checks the results of the computational tests. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    c_dim1 = *ldc;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --ct;
    --g;
    cc_dim1 = *ldcc;
    cc_offset = 1 + cc_dim1;
    cc -= cc_offset;

    /* Function Body */
    trana = *(unsigned char *)transa == 'T' || *(unsigned char *)transa == 
	    'C';
    tranb = *(unsigned char *)transb == 'T' || *(unsigned char *)transb == 
	    'C';

/*     Compute expected result, one column at a time, in CT using data */
/*     in A, B and C. */
/*     Compute gauges in G. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {

	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ct[i__] = 0.;
	    g[i__] = 0.;
/* L10: */
	}
	if (! trana && ! tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = *m;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    ct[i__] += a[i__ + k * a_dim1] * b[k + j * b_dim1];
		    g[i__] += (d__1 = a[i__ + k * a_dim1], abs(d__1)) * (d__2 
			    = b[k + j * b_dim1], abs(d__2));
/* L20: */
		}
/* L30: */
	    }
	} else if (trana && ! tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = *m;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    ct[i__] += a[k + i__ * a_dim1] * b[k + j * b_dim1];
		    g[i__] += (d__1 = a[k + i__ * a_dim1], abs(d__1)) * (d__2 
			    = b[k + j * b_dim1], abs(d__2));
/* L40: */
		}
/* L50: */
	    }
	} else if (! trana && tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = *m;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    ct[i__] += a[i__ + k * a_dim1] * b[j + k * b_dim1];
		    g[i__] += (d__1 = a[i__ + k * a_dim1], abs(d__1)) * (d__2 
			    = b[j + k * b_dim1], abs(d__2));
/* L60: */
		}
/* L70: */
	    }
	} else if (trana && tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = *m;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    ct[i__] += a[k + i__ * a_dim1] * b[j + k * b_dim1];
		    g[i__] += (d__1 = a[k + i__ * a_dim1], abs(d__1)) * (d__2 
			    = b[j + k * b_dim1], abs(d__2));
/* L80: */
		}
/* L90: */
	    }
	}
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ct[i__] = *alpha * ct[i__] + *beta * c__[i__ + j * c_dim1];
	    g[i__] = abs(*alpha) * g[i__] + abs(*beta) * (d__1 = c__[i__ + j *
		     c_dim1], abs(d__1));
/* L100: */
	}

/*        Compute the error ratio for this result. */

	*err = 0.;
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    erri = (d__1 = ct[i__] - cc[i__ + j * cc_dim1], abs(d__1)) / *eps;
	    if (g[i__] != 0.) {
		erri /= g[i__];
	    }
	    *err = f2cmax(*err,erri);
	    if (*err * sqrt(*eps) >= 1.) {
		goto L130;
	    }
/* L110: */
	}

/* L120: */
    }

/*     If the loop completes, all results are at least half accurate. */
    goto L150;

/*     Report fatal error. */

L130:
    *fatal = TRUE_;
    io___384.ciunit = *nout;
    s_wsfe(&io___384);
    e_wsfe();
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*mv) {
	    io___385.ciunit = *nout;
	    s_wsfe(&io___385);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ct[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cc[i__ + j * cc_dim1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	} else {
	    io___386.ciunit = *nout;
	    s_wsfe(&io___386);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&cc[i__ + j * cc_dim1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&ct[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
/* L140: */
    }
    if (*n > 1) {
	io___387.ciunit = *nout;
	s_wsfe(&io___387);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
    }

L150:
    return 0;


/*     End of DMMCH. */

} /* dmmch_ */

logical lde_(doublereal *ri, doublereal *rj, integer *lr)
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    integer i__;


/*  Tests if two arrays are identical. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    --rj;
    --ri;

    /* Function Body */
    i__1 = *lr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ri[i__] != rj[i__]) {
	    goto L20;
	}
/* L10: */
    }
    ret_val = TRUE_;
    goto L30;
L20:
    ret_val = FALSE_;
L30:
    return ret_val;

/*     End of LDE. */

} /* lde_ */

logical lderes_(char *type__, char *uplo, integer *m, integer *n, doublereal *
	aa, doublereal *as, integer *lda)
{
    /* System generated locals */
    integer aa_dim1, aa_offset, as_dim1, as_offset, i__1, i__2;
    logical ret_val;

    /* Local variables */
    integer i__, j, ibeg, iend;
    logical upper;


/*  Tests if selected elements in two arrays are equal. */

/*  TYPE is 'GE' or 'SY'. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    /* Parameter adjustments */
    as_dim1 = *lda;
    as_offset = 1 + as_dim1;
    as -= as_offset;
    aa_dim1 = *lda;
    aa_offset = 1 + aa_dim1;
    aa -= aa_offset;

    /* Function Body */
    upper = *(unsigned char *)uplo == 'U';
    if (s_cmp(type__, "GE", (ftnlen)2, (ftnlen)2) == 0) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *lda;
	    for (i__ = *m + 1; i__ <= i__2; ++i__) {
		if (aa[i__ + j * aa_dim1] != as[i__ + j * as_dim1]) {
		    goto L70;
		}
/* L10: */
	    }
/* L20: */
	}
    } else if (s_cmp(type__, "SY", (ftnlen)2, (ftnlen)2) == 0) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    if (upper) {
		ibeg = 1;
		iend = j;
	    } else {
		ibeg = j;
		iend = *n;
	    }
	    i__2 = ibeg - 1;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		if (aa[i__ + j * aa_dim1] != as[i__ + j * as_dim1]) {
		    goto L70;
		}
/* L30: */
	    }
	    i__2 = *lda;
	    for (i__ = iend + 1; i__ <= i__2; ++i__) {
		if (aa[i__ + j * aa_dim1] != as[i__ + j * as_dim1]) {
		    goto L70;
		}
/* L40: */
	    }
/* L50: */
	}
    }

/* L60: */
    ret_val = TRUE_;
    goto L80;
L70:
    ret_val = FALSE_;
L80:
    return ret_val;

/*     End of LDERES. */

} /* lderes_ */

doublereal dbeg_(logical *reset)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static integer i__, ic, mi;


/*  Generates random numbers uniformly distributed between -0.5 and 0.5. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    if (*reset) {
/*        Initialize local variables. */
	mi = 891;
	i__ = 7;
	ic = 0;
	*reset = FALSE_;
    }

/*     The sequence of values of I is bounded between 1 and 999. */
/*     If initial I = 1,2,3,6,7 or 9, the period will be 50. */
/*     If initial I = 4 or 8, the period will be 25. */
/*     If initial I = 5, the period will be 10. */
/*     IC is used to break up the period by skipping 1 value of I in 6. */

    ++ic;
L10:
    i__ *= mi;
    i__ -= i__ / 1000 * 1000;
    if (ic >= 5) {
	ic = 0;
	goto L10;
    }
    ret_val = (i__ - 500) / 1001.;
    return ret_val;

/*     End of DBEG. */

} /* dbeg_ */

doublereal ddiff_(doublereal *x, doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;


/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 8-February-1989. */
/*     Jack Dongarra, Argonne National Laboratory. */
/*     Iain Duff, AERE Harwell. */
/*     Jeremy Du Croz, Numerical Algorithms Group Ltd. */
/*     Sven Hammarling, Numerical Algorithms Group Ltd. */

    ret_val = *x - *y;
    return ret_val;

/*     End of DDIFF. */

} /* ddiff_ */

/* Subroutine */ int dchk6_(char *sname, doublereal *eps, doublereal *thresh, 
	integer *nout, integer *ntra, logical *trace, logical *rewi, logical *
	fatal, integer *nidim, integer *idim, integer *nalf, doublereal *alf, 
	integer *nbet, doublereal *bet, integer *nmax, doublereal *a, 
	doublereal *aa, doublereal *as, doublereal *b, doublereal *bb, 
	doublereal *bs, doublereal *c__, doublereal *cc, doublereal *cs, 
	doublereal *ct, doublereal *g, integer *iorder)
{
    /* Initialized data */

    static char ich[3] = "NTC";
    static char ishape[2] = "UL";

    /* Format strings */
    static char fmt_9994[] = "(\002 ******* FATAL ERROR - ERROR-CALL MYEXIT "
	    "TAKEN ON VALID CALL *******\002)";
    static char fmt_9998[] = "(\002 ******* FATAL ERROR - PARAMETER NUMBER"
	    " \002,i2,\002 WAS CH\002,\002ANGED INCORRECTLY *******\002)";
    static char fmt_10000[] = "(\002 \002,a13,\002 PASSED THE COLUMN-MAJOR C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10001[] = "(\002 \002,a13,\002 PASSED THE ROW-MAJOR    C"
	    "OMPUTATIONAL TESTS\002,\002 (\002,i6,\002 CALL\002,\002S)\002)";
    static char fmt_10002[] = "(\002 \002,a13,\002 COMPLETED THE COLUMN-MAJO"
	    "R COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_10003[] = "(\002 \002,a13,\002 COMPLETED THE ROW-MAJOR  "
	    "  COMPUTATIONAL \002,\002TESTS (\002,i6,\002 CALLS)\002,/\002 **"
	    "***** BUT WITH MAXIMUM TEST \002,\002RATIO \002,f8.2,\002 - SUSP"
	    "ECT *******\002)";
    static char fmt_9996[] = "(\002 ******* \002,a13,\002 FAILED ON CALL NUM"
	    "BER:\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    alist al__1;

    /* Local variables */
    extern /* Subroutine */ int cdgemmtr_(integer *, char *, char *, char *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *, integer *);
    integer i__, k, n, ia, ib, ma, mb, na, nb, nc, ik, in, is, ks, ns, ica, 
	    icb, laa, lbb, lda, lcc, ldb, ldc;
    extern logical lde_(doublereal *, doublereal *, integer *);
    doublereal als, bls, err, beta;
    integer ldas, ldbs, ldcs;
    logical same, null;
    char uplo[1];
    extern /* Subroutine */ int dmake_(char *, char *, char *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, integer *, 
	    logical *, doublereal *);
    doublereal alpha;
    logical isame[13], trana, tranb;
    integer nargs;
    logical reset;
    char uplos[1];
    extern /* Subroutine */ int dprcn8_(integer *, integer *, char *, integer 
	    *, char *, char *, char *, integer *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *), dmmtch_(char *, char *, char *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     logical *, integer *, logical *);
    extern logical lderes_(char *, char *, integer *, integer *, doublereal *,
	     doublereal *, integer *);
    char tranas[1], tranbs[1], transa[1], transb[1];
    doublereal errmax;

    /* Fortran I/O blocks */
    static cilist io___441 = { 0, 0, 0, fmt_9994, 0 };
    static cilist io___444 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___446 = { 0, 0, 0, fmt_10000, 0 };
    static cilist io___447 = { 0, 0, 0, fmt_10001, 0 };
    static cilist io___448 = { 0, 0, 0, fmt_10002, 0 };
    static cilist io___449 = { 0, 0, 0, fmt_10003, 0 };
    static cilist io___450 = { 0, 0, 0, fmt_9996, 0 };



/*  Tests DGEMMTR. */

/*  Auxiliary routine for test program for Level 3 Blas. */

/*  -- Written on 19-July-2023. */
/*     Martin Koehler, MPI Magdeburg */

    /* Parameter adjustments */
    --idim;
    --alf;
    --bet;
    --g;
    --ct;
    --cs;
    --cc;
    c_dim1 = *nmax;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --bs;
    --bb;
    b_dim1 = *nmax;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    --as;
    --aa;
    a_dim1 = *nmax;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */

    nargs = 13;
    nc = 0;
    reset = TRUE_;
    errmax = 0.;

    i__1 = *nidim;
    for (in = 1; in <= i__1; ++in) {
	n = idim[in];
/*        Set LDC to 1 more than minimum value if room. */
	ldc = n;
	if (ldc < *nmax) {
	    ++ldc;
	}
/*        Skip tests if not enough room. */
	if (ldc > *nmax) {
	    goto L100;
	}
	lcc = ldc * n;
	null = n <= 0;

	i__2 = *nidim;
	for (ik = 1; ik <= i__2; ++ik) {
	    k = idim[ik];

	    for (ica = 1; ica <= 3; ++ica) {
		*(unsigned char *)transa = *(unsigned char *)&ich[ica - 1];
		trana = *(unsigned char *)transa == 'T' || *(unsigned char *)
			transa == 'C';

		if (trana) {
		    ma = k;
		    na = n;
		} else {
		    ma = n;
		    na = k;
		}
/*              Set LDA to 1 more than minimum value if room. */
		lda = ma;
		if (lda < *nmax) {
		    ++lda;
		}
/*              Skip tests if not enough room. */
		if (lda > *nmax) {
		    goto L80;
		}
		laa = lda * na;

/*              Generate the matrix A. */

		dmake_("GE", " ", " ", &ma, &na, &a[a_offset], nmax, &aa[1], &
			lda, &reset, &c_b104)
			;

		for (icb = 1; icb <= 3; ++icb) {
		    *(unsigned char *)transb = *(unsigned char *)&ich[icb - 1]
			    ;
		    tranb = *(unsigned char *)transb == 'T' || *(unsigned 
			    char *)transb == 'C';

		    if (tranb) {
			mb = n;
			nb = k;
		    } else {
			mb = k;
			nb = n;
		    }
/*                 Set LDB to 1 more than minimum value if room. */
		    ldb = mb;
		    if (ldb < *nmax) {
			++ldb;
		    }
/*                 Skip tests if not enough room. */
		    if (ldb > *nmax) {
			goto L70;
		    }
		    lbb = ldb * nb;

/*                 Generate the matrix B. */

		    dmake_("GE", " ", " ", &mb, &nb, &b[b_offset], nmax, &bb[
			    1], &ldb, &reset, &c_b104);

		    i__3 = *nalf;
		    for (ia = 1; ia <= i__3; ++ia) {
			alpha = alf[ia];

			i__4 = *nbet;
			for (ib = 1; ib <= i__4; ++ib) {
			    beta = bet[ib];
			    for (is = 1; is <= 2; ++is) {
				*(unsigned char *)uplo = *(unsigned char *)&
					ishape[is - 1];

/*                          Generate the matrix C. */

				dmake_("GE", uplo, " ", &n, &n, &c__[c_offset]
					, nmax, &cc[1], &ldc, &reset, &c_b104);

				++nc;

/*                          Save every datum before calling the */
/*                          subroutine. */

				*(unsigned char *)uplos = *(unsigned char *)
					uplo;
				*(unsigned char *)tranas = *(unsigned char *)
					transa;
				*(unsigned char *)tranbs = *(unsigned char *)
					transb;
				ns = n;
				ks = k;
				als = alpha;
				i__5 = laa;
				for (i__ = 1; i__ <= i__5; ++i__) {
				    as[i__] = aa[i__];
/* L10: */
				}
				ldas = lda;
				i__5 = lbb;
				for (i__ = 1; i__ <= i__5; ++i__) {
				    bs[i__] = bb[i__];
/* L20: */
				}
				ldbs = ldb;
				bls = beta;
				i__5 = lcc;
				for (i__ = 1; i__ <= i__5; ++i__) {
				    cs[i__] = cc[i__];
/* L30: */
				}
				ldcs = ldc;

/*                          Call the subroutine. */

				if (*trace) {
				    dprcn8_(ntra, &nc, sname, iorder, uplo, 
					    transa, transb, &n, &k, &alpha, &
					    lda, &ldb, &beta, &ldc);
				}
				if (*rewi) {
				    al__1.aerr = 0;
				    al__1.aunit = *ntra;
				    f_rew(&al__1);
				}
				cdgemmtr_(iorder, uplo, transa, transb, &n, &
					k, &alpha, &aa[1], &lda, &bb[1], &ldb,
					 &beta, &cc[1], &ldc);

/*                          Check if error-exit was taken incorrectly. */

				if (! infoc_2.ok) {
				    io___441.ciunit = *nout;
				    s_wsfe(&io___441);
				    e_wsfe();
				    *fatal = TRUE_;
				    goto L120;
				}

/*                          See what data changed inside subroutines. */

				isame[0] = *(unsigned char *)uplo == *(
					unsigned char *)uplos;
				isame[1] = *(unsigned char *)transa == *(
					unsigned char *)tranas;
				isame[2] = *(unsigned char *)transb == *(
					unsigned char *)tranbs;
				isame[3] = ns == n;
				isame[4] = ks == k;
				isame[5] = als == alpha;
				isame[6] = lde_(&as[1], &aa[1], &laa);
				isame[7] = ldas == lda;
				isame[8] = lde_(&bs[1], &bb[1], &lbb);
				isame[9] = ldbs == ldb;
				isame[10] = bls == beta;
				if (null) {
				    isame[11] = lde_(&cs[1], &cc[1], &lcc);
				} else {
				    isame[11] = lderes_("GE", " ", &n, &n, &
					    cs[1], &cc[1], &ldc);
				}
				isame[12] = ldcs == ldc;

/*                          If data was incorrectly changed, report */
/*                          and return. */

				same = TRUE_;
				i__5 = nargs;
				for (i__ = 1; i__ <= i__5; ++i__) {
				    same = same && isame[i__ - 1];
				    if (! isame[i__ - 1]) {
					io___444.ciunit = *nout;
					s_wsfe(&io___444);
					do_fio(&c__1, (char *)&i__, (ftnlen)
						sizeof(integer));
					e_wsfe();
				    }
/* L40: */
				}
				if (! same) {
				    *fatal = TRUE_;
				    goto L120;
				}

				if (! null) {

/*                             Check the result. */

				    dmmtch_(uplo, transa, transb, &n, &k, &
					    alpha, &a[a_offset], nmax, &b[
					    b_offset], nmax, &beta, &c__[
					    c_offset], nmax, &ct[1], &g[1], &
					    cc[1], &ldc, eps, &err, fatal, 
					    nout, &c_true);
				    errmax = f2cmax(errmax,err);
/*                             If got really bad answer, report and */
/*                             return. */
				    if (*fatal) {
					goto L120;
				    }
				}

/* L45: */
			    }

/* L50: */
			}

/* L60: */
		    }

L70:
		    ;
		}

L80:
		;
	    }

/* L90: */
	}

L100:
	;
    }


/*     Report result. */

    if (errmax < *thresh) {
	if (*iorder == 0) {
	    io___446.ciunit = *nout;
	    s_wsfe(&io___446);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___447.ciunit = *nout;
	    s_wsfe(&io___447);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {
	if (*iorder == 0) {
	    io___448.ciunit = *nout;
	    s_wsfe(&io___448);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*iorder == 1) {
	    io___449.ciunit = *nout;
	    s_wsfe(&io___449);
	    do_fio(&c__1, sname, (ftnlen)13);
	    do_fio(&c__1, (char *)&nc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&errmax, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L130;

L120:
    io___450.ciunit = *nout;
    s_wsfe(&io___450);
    do_fio(&c__1, sname, (ftnlen)13);
    e_wsfe();
    dprcn8_(nout, &nc, sname, iorder, uplo, transa, transb, &n, &k, &alpha, &
	    lda, &ldb, &beta, &ldc);

L130:
    return 0;

/* L9997: */
/* L9995: */

/*     End of DCHK6 */

} /* dchk6_ */

/* Subroutine */ int dprcn8_(integer *nout, integer *nc, char *sname, integer 
	*iorder, char *uplo, char *transa, char *transb, integer *n, integer *
	k, doublereal *alpha, integer *lda, integer *ldb, doublereal *beta, 
	integer *ldc)
{
    /* Format strings */
    static char fmt_9995[] = "(1x,i6,\002: \002,a13,\002(\002,a14,\002,\002,"
	    "a14,\002,\002,a14,\002,\002,a14,\002,\002)";
    static char fmt_9994[] = "(10x,2(i3,\002,\002),\002 \002,f4.1,\002 , A"
	    ",\002,i3,\002, B,\002,i3,\002, \002,f4.1,\002 , C,\002,i3,\002)"
	    ".\002)";

    /* Local variables */
    char crc[14], cta[14], ctb[14], cuplo[14];

    /* Fortran I/O blocks */
    static cilist io___455 = { 0, 0, 0, fmt_9995, 0 };
    static cilist io___456 = { 0, 0, 0, fmt_9994, 0 };


    if (*(unsigned char *)uplo == 'U') {
	s_copy(cuplo, "CblasUpper", (ftnlen)14, (ftnlen)10);
    } else {
	s_copy(cuplo, "CblasLower", (ftnlen)14, (ftnlen)10);
    }
    if (*(unsigned char *)transa == 'N') {
	s_copy(cta, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transa == 'T') {
	s_copy(cta, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(cta, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*(unsigned char *)transb == 'N') {
	s_copy(ctb, "  CblasNoTrans", (ftnlen)14, (ftnlen)14);
    } else if (*(unsigned char *)transb == 'T') {
	s_copy(ctb, "    CblasTrans", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(ctb, "CblasConjTrans", (ftnlen)14, (ftnlen)14);
    }
    if (*iorder == 1) {
	s_copy(crc, " CblasRowMajor", (ftnlen)14, (ftnlen)14);
    } else {
	s_copy(crc, " CblasColMajor", (ftnlen)14, (ftnlen)14);
    }
    io___455.ciunit = *nout;
    s_wsfe(&io___455);
    do_fio(&c__1, (char *)&(*nc), (ftnlen)sizeof(integer));
    do_fio(&c__1, sname, (ftnlen)13);
    do_fio(&c__1, crc, (ftnlen)14);
    do_fio(&c__1, cuplo, (ftnlen)14);
    do_fio(&c__1, cta, (ftnlen)14);
    do_fio(&c__1, ctb, (ftnlen)14);
    e_wsfe();
    io___456.ciunit = *nout;
    s_wsfe(&io___456);
    do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*k), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*lda), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ldb), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*beta), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*ldc), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* dprcn8_ */

/* Subroutine */ int dmmtch_(char *uplo, char *transa, char *transb, integer *
	n, integer *kk, doublereal *alpha, doublereal *a, integer *lda, 
	doublereal *b, integer *ldb, doublereal *beta, doublereal *c__, 
	integer *ldc, doublereal *ct, doublereal *g, doublereal *cc, integer *
	ldcc, doublereal *eps, doublereal *err, logical *fatal, integer *nout,
	 logical *mv)
{
    /* Format strings */
    static char fmt_9999[] = "(\002 ******* FATAL ERROR - COMPUTED RESULT IS"
	    " LESS THAN HAL\002,\002F ACCURATE *******\002,/\002           EX"
	    "PECTED RESULT   COMPU\002,\002TED RESULT\002)";
    static char fmt_9998[] = "(1x,i7,2g18.6)";
    static char fmt_9997[] = "(\002      THESE ARE THE RESULTS FOR COLUMN"
	    " \002,i3)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, cc_dim1, 
	    cc_offset, i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Local variables */
    integer i__, j, k;
    doublereal erri;
    logical trana, tranb, upper;
    integer istop, istart;

    /* Fortran I/O blocks */
    static cilist io___466 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___467 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___468 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___469 = { 0, 0, 0, fmt_9997, 0 };



/*  Checks the results of the computational tests. */

/*  Auxiliary routine for test program for Level 3 Blas. (DGEMMTR) */

/*  -- Written on 19-July-2023. */
/*     Martin Koehler, MPI Magdeburg */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    c_dim1 = *ldc;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --ct;
    --g;
    cc_dim1 = *ldcc;
    cc_offset = 1 + cc_dim1;
    cc -= cc_offset;

    /* Function Body */
    upper = *(unsigned char *)uplo == 'U';
    trana = *(unsigned char *)transa == 'T' || *(unsigned char *)transa == 
	    'C';
    tranb = *(unsigned char *)transb == 'T' || *(unsigned char *)transb == 
	    'C';

/*     Compute expected result, one column at a time, in CT using data */
/*     in A, B and C. */
/*     Compute gauges in G. */

    istart = 1;
    istop = *n;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {

	if (upper) {
	    istart = 1;
	    istop = j;
	} else {
	    istart = j;
	    istop = *n;
	}
	i__2 = istop;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    ct[i__] = 0.;
	    g[i__] = 0.;
/* L10: */
	}
	if (! trana && ! tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = istop;
		for (i__ = istart; i__ <= i__3; ++i__) {
		    ct[i__] += a[i__ + k * a_dim1] * b[k + j * b_dim1];
		    g[i__] += (d__1 = a[i__ + k * a_dim1], abs(d__1)) * (d__2 
			    = b[k + j * b_dim1], abs(d__2));
/* L20: */
		}
/* L30: */
	    }
	} else if (trana && ! tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = istop;
		for (i__ = istart; i__ <= i__3; ++i__) {
		    ct[i__] += a[k + i__ * a_dim1] * b[k + j * b_dim1];
		    g[i__] += (d__1 = a[k + i__ * a_dim1], abs(d__1)) * (d__2 
			    = b[k + j * b_dim1], abs(d__2));
/* L40: */
		}
/* L50: */
	    }
	} else if (! trana && tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = istop;
		for (i__ = istart; i__ <= i__3; ++i__) {
		    ct[i__] += a[i__ + k * a_dim1] * b[j + k * b_dim1];
		    g[i__] += (d__1 = a[i__ + k * a_dim1], abs(d__1)) * (d__2 
			    = b[j + k * b_dim1], abs(d__2));
/* L60: */
		}
/* L70: */
	    }
	} else if (trana && tranb) {
	    i__2 = *kk;
	    for (k = 1; k <= i__2; ++k) {
		i__3 = istop;
		for (i__ = istart; i__ <= i__3; ++i__) {
		    ct[i__] += a[k + i__ * a_dim1] * b[j + k * b_dim1];
		    g[i__] += (d__1 = a[k + i__ * a_dim1], abs(d__1)) * (d__2 
			    = b[j + k * b_dim1], abs(d__2));
/* L80: */
		}
/* L90: */
	    }
	}
	i__2 = istop;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    ct[i__] = *alpha * ct[i__] + *beta * c__[i__ + j * c_dim1];
	    g[i__] = abs(*alpha) * g[i__] + abs(*beta) * (d__1 = c__[i__ + j *
		     c_dim1], abs(d__1));
/* L100: */
	}

/*        Compute the error ratio for this result. */

	*err = 0.;
	i__2 = istop;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    erri = (d__1 = ct[i__] - cc[i__ + j * cc_dim1], abs(d__1)) / *eps;
	    if (g[i__] != 0.) {
		erri /= g[i__];
	    }
	    *err = f2cmax(*err,erri);
	    if (*err * sqrt(*eps) >= 1.) {
		goto L130;
	    }
/* L110: */
	}

/* L120: */
    }

/*     If the loop completes, all results are at least half accurate. */
    goto L150;

/*     Report fatal error. */

L130:
    *fatal = TRUE_;
    io___466.ciunit = *nout;
    s_wsfe(&io___466);
    e_wsfe();
    i__1 = istop;
    for (i__ = istart; i__ <= i__1; ++i__) {
	if (*mv) {
	    io___467.ciunit = *nout;
	    s_wsfe(&io___467);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ct[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cc[i__ + j * cc_dim1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	} else {
	    io___468.ciunit = *nout;
	    s_wsfe(&io___468);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&cc[i__ + j * cc_dim1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&ct[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
/* L140: */
    }
    if (*n > 1) {
	io___469.ciunit = *nout;
	s_wsfe(&io___469);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
    }

L150:
    return 0;


/*     End of DMMTCH */

} /* dmmtch_ */

/* Main program alias */ int dblat3_ () { MAIN__ (); return 0; }
