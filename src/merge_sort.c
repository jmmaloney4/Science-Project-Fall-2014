/* ----------------------------------------------------------------------------

 Copyright (c) 2014 Jack Maloney
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ---------------------------------------------------------------------------- */

#include "data.h"

data merge_sort(data d) {
    if (d->size == 1) {
        return d;
    }

    int lhsz = d->size / 2;
    int rhsz = d->size / 2;

    // if odd, add one to the right hand side array
    if ((d->size % 2) == 1) {
        rhsz += 1;
    }

    assert(lhsz + rhsz == d->size);

    data lhd = CreateData(lhsz, alloca(sizeof(int) * lhsz));
    for (int a = 0; a < lhsz; a++) {
        lhd->data[a] = d->data[a];
    }

    data rhd = CreateData(rhsz, alloca(sizeof(int) * rhsz));
    for (int a = 0; a < rhsz; a++) {
        rhd->data[a] = d->data[a + lhsz];
    }

    data lhr = merge_sort(lhd);
    data rhr = merge_sort(rhd);

    data rv = CreateData(d->size, malloc(sizeof(int) * d->size));

    int lhc = 0;
    int rhc = 0;
    for (int a = 0; a < rv->size; a++) {
        if ((lhc < lhsz) && (rhc < rhsz)) {
            if (lhr->data[lhc] < rhr->data[rhc]) {
                rv->data[a] = lhr->data[lhc];
                lhc++;
            } else {
                rv->data[a] = rhr->data[rhc];
                rhc++;
            }
        }
        else if (lhc < lhsz) {
            rv->data[a] = lhr->data[lhc];
            lhc++;
        }
        else if (rhc < rhsz) {
            rv->data[a] = rhr->data[rhc];
            rhc++;
        }
        else {
            // Error
            assert(0 == 1);
            abort();
        }
    }
    
    free(lhr);
    free(rhr);

    return rv;
}
