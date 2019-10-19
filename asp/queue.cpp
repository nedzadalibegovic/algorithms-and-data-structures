#include <iostream>

using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;

    Node(const T& data) : data(data) {
        next = nullptr;
    }
};

template <class T>
class Queue {
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node<T>(data);
        tail = head;
        size = 1;
    }

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void enqueue(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node<T>(data);
            tail = tail->next;
            size += 1;
        }
    }

    void dequeue() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }

        Node<T>* ptr = head->next;

        delete head;
        head = ptr;
        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const Queue& obj) {
        Node<T>* ptr = obj.head;

        while (ptr != nullptr) {
            out << ptr->data << " ";
            ptr = ptr->next;
        }

        return out;
    }

    ~Queue() {
        Node<T>* curr = head;
        Node<T>* next = head->next;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->next;
        }

        delete curr;
    }
};

int main() {
    Queue<int> q;

    /*for (size_t i = 0; i < 10000000; i++) {
        q.enqueue(i);
    }*/

    for (size_t i = 0; i < 10; i++) {
        q.enqueue(i);
    }

    q.dequeue();

    cout << q << endl;

    return 0;
}