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

#include <stdio.h>
#include "data.h"

int* bubble_sort(int arr[], int size, comparator c) {
    bool done = false;
    while (!done) {
        done = true;
        for (int a = 0; a < size - 1; a++) {
            // if arr[a] and arr[a + 1] are out of place, flip them
            if (!c(arr[a], arr[a + 1])) {
                printf("arr[%i](%i) and arr[%i](%i) are out of place\n", a, arr[a], a + 1, arr[a + 1]);
                done = false;
                // Flip
                int tmp = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = tmp;
            }
        }
    }
    return arr;
}

bool cmp(int a, int b) {
    return a < b;
}

int main() {

    int* a = bubble_sort(DATA_1, DATA_1_SIZE, cmp);

    printf("Hello\n");

    print_data(a, DATA_1_SIZE);
}
