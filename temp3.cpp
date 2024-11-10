#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t size;

public:
    Array() : head(nullptr), tail(nullptr), size(0) {}

    void addElement(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    size_t getSize() const {
        return size;
    }

    void printArray() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
