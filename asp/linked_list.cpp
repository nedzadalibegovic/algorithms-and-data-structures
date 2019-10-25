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
class LinkedList {
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    void init(const T& data) {
        head = new Node<T>(data);
        tail = head;
        size = 1;
    }
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void pushFront(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            Node<T>* ptr = new Node<T>(data);

            ptr->next = head;
            head = ptr;
            size += 1;
        }
    }

    void pushBack(const T& data) {
        if (size == 0) {
            init(data);
        } else {
            tail->next = new Node<T>(data);
            tail = tail->next;
            size += 1;
        }
    }

    void popBack() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node<T>* itr = head;
        Node<T>* ptr = itr;

        while (itr != tail) {
            ptr = itr;
            itr = itr->next;
        }

        delete tail;
        tail = ptr;
        ptr->next = nullptr;
        size -= 1;
    }

    void popFront() {
        if (size <= 0) {
            return;
        }

        if (size == 1) {
            delete head;
            size = 0;
            return;
        }

        Node<T>* ptr = head->next;

        delete head;
        head = ptr;
        size -= 1;
    }

    void insert(const T& data, size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            pushFront(data);
            return;
        }

        if (index == size - 1) {
            pushBack(data);
            return;
        }

        Node<T>* before = head;
        Node<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next;

        before->next = new Node<T>(data);
        before->next->next = after;

        size += 1;
    }

    void erase(size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        if (index == 0) {
            popFront();
            return;
        }

        if (index == size - 1) {
            popBack();
            return;
        }

        Node<T>* before = head;
        Node<T>* after = nullptr;

        for (size_t i = 0; i < index - 1; i++) {
            before = before->next;
        }

        after = before->next->next;

        delete before->next;
        before->next = after;

        size -= 1;
    }

    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        Node<T>* ptr = list.head;

        while (ptr != nullptr) {
            out << ptr->data << "\n";
            ptr = ptr->next;
        }

        return out;
    }

    size_t getSize() { return size; }

    T& operator[](size_t index) {
        if (index >= size || index < 0) {
            throw exception("Invalid index!");
        }

        Node<T>* ptr = head;

        for (size_t i = 0; i < index; i++) {
            ptr = ptr->next;
        }

        return ptr->data;
    }

    ~LinkedList() {
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
    LinkedList<int> list;

    for (size_t i = 0; i < 10; i++) {
        list.pushFront(i);
        list.pushBack(i);
    }

    list.popFront();
    list.popBack();

    cout << list[2] << endl;

    list.insert(1337, 2);
    list.erase(2);

    cout << list << endl;

    cout << list.getSize() << endl;

    return 0;
}