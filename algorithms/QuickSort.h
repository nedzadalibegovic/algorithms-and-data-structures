#pragma once
#include <utility>

template <class T>
int pivot(T arr[], int begin, int end) {
    T pivot = arr[begin];
    int swapIndex = begin;

    for (int i = begin + 1; i <= end; i++) {
        if (pivot > arr[i]) {
            swapIndex++;
            std::swap(arr[i], arr[swapIndex]);
        }
    }

    std::swap(arr[begin], arr[swapIndex]);

    return swapIndex;
}

template <class T>
void partition(T arr[], int begin, int end) {
    if (begin < end) {
        int pivotIndex = pivot(arr, begin, end);

        partition(arr, begin, pivotIndex - 1);
        partition(arr, pivotIndex + 1, end);
    }
}

template <class T>
void QuickSort(T arr[], int size) {
    partition(arr, 0, size - 1);
}