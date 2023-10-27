#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
} Node;

Node *head;
Node *tail;

Node *InitList() {
    head = NULL;
    tail = NULL;
    return head;
}

Node *CreateNode(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    
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

    while (current != tail && i != index) {
        previous = current;
        current = current->next;
        i++;
    }
    if(i != index){
        printf("index not found");
        return;
    }
    if (current == head) {
        head = current->next;
    } else if (current == tail) {
        tail = previous;
    }else {
        previous->next = current->next;
    }
         current->data = 0; 
        current->next = NULL;
}

void PrintList() {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
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
    
    for (int i = 2; i <= 10; i += 2) {
        DeleteNode(i);
    }

    printf("List after deleting nodes:\n");
    PrintList();

    for (int i = 101; i <= 110; i++) {
        CreateNode(i);
    }

    printf("List after adding new nodes:\n");
    PrintList();

    // Free all allocated memory before exiting
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
