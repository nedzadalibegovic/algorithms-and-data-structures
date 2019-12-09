#pragma once

template <class T>
void merge(T arr[], int begin, int middle, int end) {
    T* temp = new T[begin + end + 1];
    int iTemp = 0, iLeft = begin, iRight = middle + 1;

    while (iLeft <= middle && iRight <= end) {
        if (arr[iLeft] < arr[iRight]) {
            temp[iTemp] = arr[iLeft];
            iTemp++, iLeft++;
        } else {
            temp[iTemp] = arr[iRight];
            iTemp++, iRight++;
        }
    }

    while (iLeft <= middle) {
        temp[iTemp] = arr[iLeft];
        iTemp++, iLeft++;
    }

    while (iRight <= end) {
        temp[iTemp] = arr[iRight];
        iTemp++, iRight++;
    }

    for (size_t i = begin; i <= end; i++) {
        arr[i] = temp[i - begin];
    }
}

template <class T>
void divide(T arr[], int begin, int end) {
    if (begin < end) {
        int middle = (begin + end) / 2;

        divide(arr, begin, middle);
        divide(arr, middle + 1, end);
        merge(arr, begin, middle, end);
    }
}

template <class T>
void MergeSort(T arr[], int size) {
    divide(arr, 0, size - 1);
}