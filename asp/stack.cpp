#include <iostream>

using namespace std;

template <class T>
struct Node {
    T data;
    Node* previous;

    Node(const T& data) : data(data) {
        previous = nullptr;
    }
};

template <class T>
class Stack {
    Node<T>* head;
    size_t size;

    void init(const T& data) {
        head = new Node<T>(data);
        size = 1;
    }
public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    void push(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node<T>* ptr = new Node<T>(data);

            ptr->previous = head;
            head = ptr;
            size += 1;
        }
    }

    void pop() {
        if (size == 0) {
            return;
        }

        if (size == 1) {
            delete head;
            head = nullptr;
            size = 0;
            return;
        }

        Node<T>* ptr = head->previous;

        delete head;
        head = ptr;
        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const Stack& obj) {
        Node<T>* ptr = obj.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->previous;
        }

        return out;
    }

    ~Stack() {
        Node<T>* curr = head;
        Node<T>* next = head->previous;

        while (next != nullptr) {
            delete curr;
            curr = next;
            next = curr->previous;
        }

        delete curr;
    }
};

int main() {
    Stack<int> foo;

    /*for (size_t i = 0; i < 10000000; i++) {
        foo.push(i);
    }*/

    for (size_t i = 0; i < 10; i++) {
        foo.push(i);
    }

    foo.pop();

    cout << foo << endl;

    return 0;
}