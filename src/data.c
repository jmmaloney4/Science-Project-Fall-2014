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
#include <time.h>

int data1[] = {1,4,-3,9,8,7,0,1,4,2,5,7,2,5,9,3,1,5,6,2,22,2,5,237572575,71,5,7245,72,145,257,245,74,74,5724,57,15,524,62,14212};

size_t alloced = 0;

void* alloc(size_t s) {
    alloced += s;
    return malloc(s);
}

void resetab() {
    alloced = 0;
}

size_t getab() {
    return alloced;
}

struct testret* test(sort_alg_t alg, data d) {
    resetab();
    struct testret* rv = malloc(sizeof(struct testret));
    time_t start = time(NULL);
    rv->rv = alg(d);
    time_t end = time(NULL);
    rv->time = end - start;
    rv->memalloc = getab();
    resetab();
    return rv;
}
