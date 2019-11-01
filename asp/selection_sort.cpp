#include <iostream>
#include <vector>

using namespace std;

template <class T>
void selection_sort(vector<T>& arr) {
    size_t min_index = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
        min_index = i + 1;
    }
}

int main() {
    vector<int> arr = { 84, 72, 28, 5, 64, 61, 13, 79, 81, 68, 14, 31, 85, 6, 71, 47, 35, 78, 44, 50, 69, 29, 9, 18, 22, 3, 7, 19, 92, 63, 99, 17, 37, 86, 57, 30, 87, 34, 33, 39, 55, 96, 16, 11, 25, 93, 41, 74, 8, 60, 98, 76, 94, 38, 100, 66, 89, 97, 46, 70, 52, 36, 2, 26, 20, 77, 51, 90, 32, 1, 10, 59, 54, 24, 73, 91, 65, 95, 58, 15, 88, 4, 49, 21, 40, 23, 56, 27, 42, 48, 80, 82, 62, 67, 75, 53, 43, 83, 12, 45 };

    cout << "Before sort:\n";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    selection_sort(arr);

    cout << "\nAfter sort:\n";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}