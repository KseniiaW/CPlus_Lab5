#include "task2.h"

int* max_vect(int kc, int a[], int b[]) {
    int* result = new int[kc];

    for (int i = 0; i < kc; i++) {
        result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }

    return result; 
}