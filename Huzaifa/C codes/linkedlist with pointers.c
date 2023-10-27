#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE* next;
} Node;

Node MyNodes[100];
Node *head;
Node *tail;

Node *InitList() {
    head = NULL;
    tail = NULL;
    for (int i = 0; i < 100; i++) {
        MyNodes[i].data = 0;
        MyNodes[i].next = NULL;
    }

    return head;
}

Node *CreateNode(int data) {
    Node *newnode = NULL;

    for (int i = 0; i < 100; i++) {
        if (MyNodes[i].next == NULL && &MyNodes[i] != tail) {
            newnode = &MyNodes[i];
            newnode->data = data;
            newnode->next = NULL;
            break;
        }
    }

    // Update tail and node
    if (head == NULL) {
        head = newnode;
    }

    if (newnode != NULL) {
        if (tail != NULL) {
            tail->next = newnode;
        }
        tail = newnode;
    }
    return newnode;
}

void deletenode(int index) {
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

    printf("Initial list: \n ");
    PrintList();
    
    for(int i=0;i<10;i+=2){
        deletenode(i);
    }
    printf("List after deleting nodes:\n");
    PrintList();

    for (int i = 1; i <= 10; i++) {
        CreateNode(i+100);
    }
    printf("List after deleting nodes:\n");
    PrintList();

    return 0;
}