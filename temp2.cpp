#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // клонування списку
    DoublyLinkedList<T> clone() const {
        DoublyLinkedList<T> clonedList;
        Node* current = head;
        while (current) {
            clonedList.append(current->data);
            current = current->next;
        }
        return clonedList;
    }

    // перевантаження оператора +
    DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& other) const {
        DoublyLinkedList<T> mergedList = this->clone();
        Node* current = other.head;
        while (current) {
            mergedList.append(current->data);
            current = current->next;
        }
        return mergedList;
    }

    // перевантаження оператора *
    DoublyLinkedList<T> operator*(const DoublyLinkedList<T>& other) const {
        DoublyLinkedList<T> commonElementsList;
        Node* current1 = head;
        while (current1) {
            Node* current2 = other.head;
            while (current2) {
                if (current1->data == current2->data) {
                    commonElementsList.append(current1->data);
                    break;
                }
                current2 = current2->next;
            }
            current1 = current1->next;
        }
        return commonElementsList;
    }

    void printList() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
