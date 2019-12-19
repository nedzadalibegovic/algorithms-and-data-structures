#include <iostream>
#include <vector>

// Data Structures:
#include "ListPtr.h";
#include "ListSeq.h"
#include "StackSeq.h"
#include "StackPtr.h"
#include "QueueSeq.h"
#include "QueuePtr.h"
#include "PriorityQueueSeq.h"
#include "PriorityQueuePtr.h"
#include "PriorityQueueHeap.h"

// Algorithms:
#include "Random.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
#pragma region ListSeq
    cout << "ListSeq\n";
    ListSeq<int> list_seq;

    for (size_t i = 0; i < 300; i++) {
        list_seq.pushFront(i);
    }

    list_seq.popFront();

    cout << list_seq.popBack() << "\n";

    list_seq.print();

    cout << "/ListSeq\n";
#pragma endregion

#pragma region ListPtr
    cout << "ListPtr\n";
    ListPtr<int> list_ptr;

    for (size_t i = 0; i < 100; i++) {
        list_ptr.pushFront(i);
    }

    cout << list_ptr.popFront() << "<-\n";

    list_ptr.pushBack(100);

    cout << list_ptr.popBack() << "<-\n";

    list_ptr.pushBack(1337);

    list_ptr.print();

    cout << "/ListPtr\n";
#pragma endregion

#pragma region StackSeq
    cout << "StackSeq\n";
    StackSeq<int> stack_seq;

    for (size_t i = 0; i < 100; i++) {
        stack_seq.push(i);
    }

    stack_seq.pop();

    stack_seq.print();

    cout << "/StackSeq\n";
#pragma endregion

#pragma region StackPtr
    cout << "StackPtr\n";
    StackPtr<int> stack_ptr;

    for (size_t i = 0; i < 100; i++) {
        stack_ptr.push(i);
    }

    stack_ptr.pop();

    stack_ptr.print();

    cout << "/StackPtr\n";
#pragma endregion

#pragma region QueueSeq
    cout << "QueueSeq\n";
    QueueSeq<int> queue_seq;

    for (size_t i = 1; i < 10; i++) {
        queue_seq.enqueue(i);
    }

    queue_seq.dequeue();

    queue_seq.print();

    cout << "/QueueSeq\n";
#pragma endregion

#pragma region QueuePtr
    cout << "QueuePtr\n";
    QueuePtr<int> queue_ptr;

    for (size_t i = 1; i < 10; i++) {
        queue_ptr.enqueue(i);
    }

    queue_ptr.print();

    for (size_t i = 0; i < 9; i++) {
        cout << queue_ptr.dequeue() << "<-\n";
    }

    cout << "/QueuePtr\n";
#pragma endregion

#pragma region PriorityQueueSeq
    cout << "PriorityQueueSeq\n";
    PriorityQueueSeq<int> priority_queue_seq;

    for (size_t i = 0; i < 10; i++) {
        priority_queue_seq.enqueue(i);
    }

    priority_queue_seq.print();

    for (size_t i = 0; i < 9; i++) {
        cout << priority_queue_seq.dequeue() << "<-\n";
    }

    cout << "/PriorityQueueSeq\n";
#pragma endregion

#pragma region PriorityQueuePtr
    cout << "PriorityQueuePtr\n";
    PriorityQueuePtr<int> priority_queue_ptr;

    for (size_t i = 10; i > 0; i--) {
        priority_queue_ptr.enqueue(i);
    }

    priority_queue_ptr.print();

    for (size_t i = 0; i < 10; i++) {
        cout << priority_queue_ptr.dequeue() << "<-\n";
    }

    cout << "/PriorityQueuePtr\n";
#pragma endregion

#pragma region PriorityQueueHeap
    cout << "PriorityQueueHeap\n";
    PriorityQueueHeap<int> priority_queue_heap;

    for (size_t i = 1; i <= 10; i++) {
        priority_queue_heap.enqueue(i);
    }

    priority_queue_heap.print();

    for (size_t i = 0; i < 10; i++) {
        cout << priority_queue_heap.dequeue() << "<-\n";
    }

    cout << "/PriorityQueueHeap\n";
#pragma endregion

    Random random;

#pragma region BubbleSort
    vector<int> arr_bubble = random.integer_vector_uniform(100);

    BubbleSort(arr_bubble.data(), arr_bubble.size());

    cout << "\nBubble sort:\n";
    for (size_t i = 0; i < arr_bubble.size(); i++) {
        cout << arr_bubble[i] << " ";
    }

#pragma endregion

#pragma region InsertionSort
    vector<int> arr_insertion = random.integer_vector_uniform(100);

    InsertionSort(arr_insertion.data(), arr_insertion.size());

    cout << "\nInsertion sort:\n";
    for (size_t i = 0; i < arr_insertion.size(); i++) {
        cout << arr_insertion[i] << " ";
    }

#pragma endregion

#pragma region SelectionSort
    vector<int> arr_selection = random.integer_vector_uniform(100);

    SelectionSort(arr_selection.data(), arr_selection.size());

    cout << "\nSelection sort:\n";
    for (size_t i = 0; i < arr_selection.size(); i++) {
        cout << arr_selection[i] << " ";
    }

#pragma endregion

#pragma region MergeSort
    vector<int> arr_merge = random.integer_vector_uniform(100);

    MergeSort(arr_merge.data(), arr_merge.size());

    cout << "\nMerge sort:\n";
    for (size_t i = 0; i < arr_merge.size(); i++) {
        cout << arr_merge[i] << " ";
    }

#pragma endregion

#pragma region QuickSort
    vector<int> arr_quick = random.integer_vector_uniform(100);

    QuickSort(arr_quick.data(), arr_quick.size());

    cout << "\nQuick sort:\n";
    for (size_t i = 0; i < arr_quick.size(); i++) {
        cout << arr_quick[i] << " ";
    }

#pragma endregion

    return 0;
}