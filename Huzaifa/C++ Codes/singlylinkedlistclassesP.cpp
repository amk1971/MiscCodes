#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void CreateNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteNode(int data) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != data) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Data not found.\n";
            return;
        }

        if (current == head) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        if (current == tail) {
            tail = previous;
        }

        delete current;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;

    for (int i = 1; i <= 10; i++) {
        list.CreateNode(i);
    }

    std::cout << "Initial list:\n";
    list.PrintList();

    for (int i = 1; i <= 10; i += 2) {
        list.DeleteNode(i);
    }
    std::cout << "List after deleting nodes:\n";
    list.PrintList();

    for (int i = 1; i <= 10; i++) {
        list.CreateNode(i + 100);
    }
    std::cout << "List after adding more nodes:\n";
    list.PrintList();

    return 0;
}
