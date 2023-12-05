#include <iostream>

class Node {
public:
    int data;
    int nextIndex;
};

class LinkedList {
private:
    Node MyNodes[100];
    int head;
    int tail;
    int freeList;

public:
    LinkedList() : head(-1), tail(-1), freeList(0) {
        for (int i = 0; i < 99; i++) {
            MyNodes[i].nextIndex = i + 1;
        }
        MyNodes[99].nextIndex = -1; // Mark the last node as the end of the list.
    }

    int CreateNode(int data) {
        if (freeList == -1) {
            std::cout << "List is full. Cannot create more nodes." << std::endl;
            return -1;
        }

        int newNodeIndex = freeList;
        freeList = MyNodes[freeList].nextIndex;

        MyNodes[newNodeIndex].data = data;
        MyNodes[newNodeIndex].nextIndex = -1;

        if (head == -1) {
            head = newNodeIndex;
        }

        if (tail != -1) {
            MyNodes[tail].nextIndex = newNodeIndex;
        }
        tail = newNodeIndex;

        return newNodeIndex;
    }

    void DeleteNode(int index) {
        if (index < 0 || index >= 100) {
            std::cout << "Invalid index." << std::endl;
            return;
        }

        if (index == head) {
            head = MyNodes[index].nextIndex;
            MyNodes[index].nextIndex = freeList;
            freeList = index;
            MyNodes[index].data = 0;
            return;
        }

        int current = head;
        int previous = -1;

        while (current != -1 && index > 0) {
            previous = current;
            current = MyNodes[current].nextIndex;
            index--;
        }

        if (current == -1) {
            std::cout << "Index not found." << std::endl;
            return;
        }

        if (current == tail) {
            tail = previous;
        }

        MyNodes[previous].nextIndex = MyNodes[current].nextIndex;
        MyNodes[current].nextIndex = freeList;
        freeList = current;
        MyNodes[current].data = 0;
    }

    void PrintList() {
        int current = head;
        while (current != -1) {
            std::cout << MyNodes[current].data << " -> ";
            current = MyNodes[current].nextIndex;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList myList;

    for (int i = 1; i <= 10; i++) {
        myList.CreateNode(i);
    }

    std::cout << "Initial list: ";
    myList.PrintList();

    for (int i = 1; i <= 10; i += 2) {
        myList.DeleteNode(i);
    }
    std::cout << "List after deleting nodes:" << std::endl;
    myList.PrintList();

    for (int i = 1; i <= 10; i++) {
        myList.CreateNode(i + 100);
    }
    std::cout << "List after adding more nodes:" << std::endl;
    myList.PrintList();

    return 0;
}
