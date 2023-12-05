#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    Node* CreateNode(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        }

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;

        return newNode;
    }

    void DeleteNode(int index) {
        Node* current = head;
        Node* previous = nullptr;
        int i = 0;

        while (current != nullptr && i != index) {
            previous = current;
            current = current->next;
            i++;
        }

        if (i != index || current == nullptr) {
            std::cout << "Index not found" << std::endl;
            return;
        }

        if (current == head) {
            head = current->next;
        } else if (current == tail) {
            tail = previous;
            tail->next = nullptr;
        } else {
            previous->next = current->next;
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

    void FreeList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    for (int i = 1; i <= 10; i++) {
        myList.CreateNode(i);
    }

    std::cout << "Initial list:" << std::endl;
    myList.PrintList();

    for (int i = 0; i < 10; i += 2) {
        myList.DeleteNode(i);
    }
    std::cout << "List after deleting nodes:" << std::endl;
    myList.PrintList();

    for (int i = 1; i <= 10; i++) {
        myList.CreateNode(i + 100);
    }
    std::cout << "List after adding more nodes:" << std::endl;
    myList.PrintList();

    myList.FreeList();
    
    return 0;
}
