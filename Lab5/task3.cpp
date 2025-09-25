#include "task3.h"

int transpositionSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            if (i > 0) {

                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1; 
            }
            return i;  
        }
    }
    return -1; 
}