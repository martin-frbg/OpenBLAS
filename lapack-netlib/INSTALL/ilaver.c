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

#if defined(_WIN64)
typedef long long BLASLONG;
typedef unsigned long long BLASULONG;
#else
typedef long BLASLONG;
typedef unsigned long BLASULONG;
#endif

#ifdef LAPACK_ILP64
typedef BLASLONG blasint;
#if defined(_WIN64)
#define blasabs(x) llabs(x)
#else
#define blasabs(x) labs(x)
#endif
#else
typedef int blasint;
#define blasabs(x) abs(x)
#endif

typedef blasint integer;

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* procedure parameter types for -A and -C++ */

#define F2C_proc_par_types 1



/* > \brief \b ILAVER returns the LAPACK version. */
/* * */
/*  =========== DOCUMENTATION =========== */

/* Online html documentation available at */
/*            http://www.netlib.org/lapack/explore-html/ */

/*  Definition: */
/*  =========== */

/*     SUBROUTINE ILAVER( VERS_MAJOR, VERS_MINOR, VERS_PATCH ) */

/*     INTEGER VERS_MAJOR, VERS_MINOR, VERS_PATCH */


/* > \par Purpose: */
/*  ============= */
/* > */
/* > \verbatim */
/* > */
/* >  This subroutine returns the LAPACK version. */
/* > \endverbatim */

/*  Arguments: */
/*  ========== */

/* >  \param[out] VERS_MAJOR */
/* >      VERS_MAJOR is INTEGER */
/* >      return the lapack major version */
/* > */
/* >  \param[out] VERS_MINOR */
/* >      VERS_MINOR is INTEGER */
/* >      return the lapack minor version from the major version */
/* > */
/* >  \param[out] VERS_PATCH */
/* >      VERS_PATCH is INTEGER */
/* >      return the lapack patch version from the minor version */

/*  Authors: */
/*  ======== */

/* > \author Univ. of Tennessee */
/* > \author Univ. of California Berkeley */
/* > \author Univ. of Colorado Denver */
/* > \author NAG Ltd. */


/* > \ingroup auxOTHERauxiliary */

/*  ===================================================================== */
/* Subroutine */ void ilaver_(integer *vers_major__, integer *vers_minor__, 
	integer *vers_patch__)
{

/*  -- LAPACK computational routine -- */
/*  -- LAPACK is a software package provided by Univ. of Tennessee,    -- */
/*  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..-- */

/*  ===================================================================== */

/*  ===================================================================== */
    *vers_major__ = 3;
    *vers_minor__ = 12;
    *vers_patch__ = 0;
/*  ===================================================================== */

    return;
} /* ilaver_ */

