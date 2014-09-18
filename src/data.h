//
//  data.h
//  
//
//  Created by Jack Maloney on 9/17/14.
//
//

#ifndef _data_h
#define _data_h

#include <stdbool.h>

static int DATA_1_SIZE = 16;
static int DATA_1[] = {1, 3, 2, 5, 9, 7, 2, 5, 10, 300, 53, 122, 62, 1234, 823, 1};

typedef bool (*comparator)(int a, int b);

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
