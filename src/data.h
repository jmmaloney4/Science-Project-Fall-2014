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

#ifndef _data_h
#define _data_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <alloca.h>

#define assert(k) \
if (!( k )) { \
    printf("Assertion Failed on Line %i\n", __LINE__); \
    exit(1); \
}

struct _data {
    int size;
    int* data;
};

typedef struct _data* data;

typedef data (*sort_alg_t)(data);

data CreateData(int size, int data[]);
void DumpData(data d);

#define data1_size 39
int data1[data1_size];

#define data2_size 100000
int data2[data2_size];

data merge_sort(data d);
data bubble_sort(data d);
data insertion_sort(data d);

void* alloc(size_t s);
void resetab();
size_t getab();

struct testret {
    long time;
    size_t memalloc;
    data rv;
};

struct testret* test(sort_alg_t alg, data d);

#endif
