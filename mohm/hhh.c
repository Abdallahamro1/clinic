#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node
Node* deleteNode(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Element not found in the list.\n");
        return head;
    }
    if(prev != NULL) {
        prev->next = temp->next;
    }
    if(temp == head) {
        head = temp->next;
    }
    free(temp);
    return head;
}

// Function to find a node
Node* findNode(Node* head, int data) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
