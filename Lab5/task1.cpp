#include "task1.h"

int arraySum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
double arrayAverage(const int arr[], int size) {
    if (size == 0) return 0.0;
    return static_cast<double>(arraySum(arr, size)) / size;
}

int sumNegative(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int sumPositive(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int sumEvenIndex(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int sumOddIndex(const int arr[], int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

void findMinMax(const int arr[], int size, int& minVal, int& maxVal, int& minIndex, int& maxIndex) {
    if (size == 0) return;

    minVal = maxVal = arr[0];
    minIndex = maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
}

long long productBetweenMinMax(const int arr[], int size) {
    if (size < 3) return 0;

    int minVal, maxVal, minIndex, maxIndex;
    findMinMax(arr, size, minVal, maxVal, minIndex, maxIndex);

    int start = (minIndex < maxIndex) ? minIndex : maxIndex;
    int end = (minIndex > maxIndex) ? minIndex : maxIndex;

    if (end - start <= 1) return 0;

    long long product = 1;
    for (int i = start + 1; i < end; i++) {
        product *= arr[i];
    }
    return product;
}
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}