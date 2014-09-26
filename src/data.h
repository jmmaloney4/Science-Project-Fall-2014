/* ----------------------------------------------------------------------------
 
 Copyright (c) 2014, Jack Maloney
 
 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.
 
 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

 ---------------------------------------------------------------------------- */

#ifndef _data_h
#define _data_h

#include <stdbool.h>

static int DATA_1_SIZE = 16;
static int DATA_1[] = {1, 3, 2, 5, 9, 7, 2, 5, 10, 300, 53, 122, 62, 1234, 823, 1};

enum cmp_ret {
    CMP_RET_EQUAL,
    CMP_RET_A_GREATER_B,
    CMP_RET_B_GREATER_A
}

typedef enum cmp_ret (*comparator)(int a, int b);

void print_data(int* data, int size) {
    printf("[");
    for (int a = 0; a < size; a++) {
        printf("%i", data[a]);
        if ((a + 1) < size) {
            printf(", ");
        }
    }
    printf("]");
}

#endif
