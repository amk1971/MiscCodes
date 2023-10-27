#include <stdio.h>

typedef struct NODE{
    int data;
    int nextIndex; // Index of the next node in MyNodes array
} Node;

Node MyNodes[100];
int head = -1; // Index of the head node
int tail = -1; // Index of the tail node
int freeList = 0; // Index of the first free node

void InitList() {
    for (int i = 0; i < 100; i++) {
        MyNodes[i].data = 0;
        MyNodes[i].nextIndex = i + 1;
    }
    MyNodes[100 - 1].nextIndex = -1; // End of the free list
}

int CreateNode(int data) {
    if (freeList == -1) {
        printf("List is full. Cannot create more nodes.\n");
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
        printf("Invalid index.\n");
        return;
    }

    int current = head;
    int previous = -1;

    int i = 0;

    while (current != -1 && i != index) {
        previous = current;
        current = MyNodes[current].nextIndex;
        i++;
    }

    if (i != index) {
        printf("Index not found.\n");
        return;
    }

    if (current == head) {
        head = MyNodes[current].nextIndex;
    } else {
        MyNodes[previous].nextIndex = MyNodes[current].nextIndex;
    }

    if (current == tail) {
        tail = previous;
    }

    MyNodes[current].data = 0;
    MyNodes[current].nextIndex = freeList;
    freeList = current;
}

void PrintList() {
    int current = head;
    while (current != -1) {
        printf("%d -> ", MyNodes[current].data);
        current = MyNodes[current].nextIndex;
    }
    printf("NULL\n");
}

int main() {
    InitList();

    for (int i = 1; i <= 10; i++) {
        CreateNode(i);
    }

    printf("Initial list: ");
    PrintList();

    for (int i = 0; i < 10; i += 2) {
        DeleteNode(i);
    }
    printf("List after deleting nodes:\n");
    PrintList();

    for (int i = 1; i <= 10; i++) {
        CreateNode(i + 100);
    }
    printf("List after adding more nodes:\n");
    PrintList();

    return 0;
}
