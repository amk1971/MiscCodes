#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
} Node;

Node *head;
Node *tail;

Node* InitList() {
    head = NULL;
    tail = NULL;
}

Node* CreateNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }

    if (tail != NULL) {
        tail->next = newnode;
    }
    tail = newnode;

    return newnode;
}

void DeleteNode(int index) {
    Node* current = head;
    Node* previous = NULL;
    int i = 0;

    while (current != NULL && i != index) {
        previous = current;
        current = current->next;
        i++;
    }

    if (i != index || current == NULL) {
        printf("Index not found\n");
        return;
    }

    if (current == head) {
        head = current->next;
    } else if (current == tail) {
        tail = previous;
        tail->next = NULL;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void PrintList() {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void FreeList() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    InitList();

    for (int i = 1; i <= 10; i++) {
        CreateNode(i);
    }

    printf("Initial list:\n");
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

    FreeList();
}
