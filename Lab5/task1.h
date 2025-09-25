#pragma once
#ifndef TASK1_H
#define TASK1_H

int arraySum(const int arr[], int size);
double arrayAverage(const int arr[], int size);
int sumNegative(const int arr[], int size);
int sumPositive(const int arr[], int size);
int sumEvenIndex(const int arr[], int size);
int sumOddIndex(const int arr[], int size);
void findMinMax(const int arr[], int size, int& minVal, int& maxVal, int& minIndex, int& maxIndex);
long long productBetweenMinMax(const int arr[], int size);
void selectionSort(int arr[], int size);

#endif