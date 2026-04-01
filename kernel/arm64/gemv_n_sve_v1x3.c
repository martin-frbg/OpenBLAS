/***************************************************************************
Copyright (c) 2025, The OpenBLAS Project
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
   3. Neither the name of the OpenBLAS project nor the names of
      its contributors may be used to endorse or promote products
      derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#include <arm_sve.h>

#include "common.h"

#ifdef DOUBLE
#define SV_COUNT svcntd
#define SV_TYPE svfloat64_t
#define SV_TRUE svptrue_b64
#define SV_WHILE svwhilelt_b64_s64
#define SV_DUP svdup_f64
#else
#define SV_COUNT svcntw
#define SV_TYPE svfloat32_t
#define SV_TRUE svptrue_b32
#define SV_WHILE svwhilelt_b32_s64
#define SV_DUP svdup_f32
#endif

int CNAME(BLASLONG m, BLASLONG n, BLASLONG dummy1, FLOAT alpha, FLOAT *a,
          BLASLONG lda, FLOAT *x, BLASLONG inc_x, FLOAT *y, BLASLONG inc_y,
          FLOAT *buffer)
{
  BLASLONG i;
  BLASLONG ix, iy;
  BLASLONG j;
  FLOAT *a_ptr;
  FLOAT temp;

  a_ptr = a;
  ix = 0;

  if (inc_y == 1) {
    BLASLONG sve_size = SV_COUNT();
    svbool_t pg_true = SV_TRUE();

    /* Process 3 consecutive columns at a time: (j, j+1, j+2) */
    for (j = 0; j + 2 < n; j += 3) {
      SV_TYPE temp0_vec = SV_DUP(alpha * x[ix]);
      SV_TYPE temp1_vec = SV_DUP(alpha * x[ix + inc_x]);
      SV_TYPE temp2_vec = SV_DUP(alpha * x[ix + inc_x * 2]);

      FLOAT *a0 = a_ptr;
      FLOAT *a1 = a_ptr + lda;
      FLOAT *a2 = a_ptr + lda * 2;

      i = 0;
      while ((i + sve_size - 1) < m) {
        SV_TYPE y0_vec = svld1(pg_true, y + i);

        SV_TYPE a00_vec = svld1(pg_true, a0 + i);
        SV_TYPE a01_vec = svld1(pg_true, a1 + i);
        SV_TYPE a02_vec = svld1(pg_true, a2 + i);

        y0_vec = svmla_m(pg_true, y0_vec, temp0_vec, a00_vec);
        y0_vec = svmla_m(pg_true, y0_vec, temp1_vec, a01_vec);
        y0_vec = svmla_m(pg_true, y0_vec, temp2_vec, a02_vec);

        svst1(pg_true, y + i, y0_vec);
        i += sve_size;
      }

      if (i < m) {
        svbool_t pg = SV_WHILE(i, m);

        SV_TYPE y0_vec = svld1(pg, y + i);

        SV_TYPE a00_vec = svld1(pg, a0 + i);
        SV_TYPE a01_vec = svld1(pg, a1 + i);
        SV_TYPE a02_vec = svld1(pg, a2 + i);

        y0_vec = svmla_m(pg, y0_vec, temp0_vec, a00_vec);
        y0_vec = svmla_m(pg, y0_vec, temp1_vec, a01_vec);
        y0_vec = svmla_m(pg, y0_vec, temp2_vec, a02_vec);

        svst1(pg, y + i, y0_vec);
      }

      a_ptr += lda * 3;
      ix += inc_x * 3;
    }

    /* Cleanup: remaining 1 or 2 columns */
    for (; j < n; j++) {
      SV_TYPE temp_vec = SV_DUP(alpha * x[ix]);

      i = 0;
      while ((i + sve_size - 1) < m) {
        SV_TYPE y_vec = svld1(pg_true, y + i);
        SV_TYPE a_vec = svld1(pg_true, a_ptr + i);
        y_vec = svmla_m(pg_true, y_vec, temp_vec, a_vec);
        svst1(pg_true, y + i, y_vec);
        i += sve_size;
      }

      if (i < m) {
        svbool_t pg = SV_WHILE(i, m);
        SV_TYPE y_vec = svld1(pg, y + i);
        SV_TYPE a_vec = svld1(pg, a_ptr + i);
        y_vec = svmla_m(pg, y_vec, temp_vec, a_vec);
        svst1(pg, y + i, y_vec);
      }

      a_ptr += lda;
      ix += inc_x;
    }

    return (0);
  }

  for (j = 0; j < n; j++) {
    temp = alpha * x[ix];
    iy = 0;
    for (i = 0; i < m; i++) {
      y[iy] += temp * a_ptr[i];
      iy += inc_y;
    }
    a_ptr += lda;
    ix += inc_x;
  }
  return (0);
}

