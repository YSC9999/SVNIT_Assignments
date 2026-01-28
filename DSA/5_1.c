#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(Node **head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        newNode->next = *head;
    }
    else{
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}
void insertAtEnd(Node **head, int data){
    Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        newNode->next = *head;
    }
    else{
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}
void insertAtIndex(Node **head, int data, int index) {
    Node* newNode = createNode(data);
    if (*head == NULL || index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < index - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next != *head) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void deleteAtBeginning(Node **head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (*head == temp->next){
        free(temp);
        *head = NULL;
    }
    else{
        Node* last = *head;
        while (last->next != *head) last = last->next;
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}
void deleteAtEnd(Node **head){
    if (*head == NULL) return;
    Node* temp = *head;
    if (*head == temp->next) {
        free(temp);
        *head = NULL;
    }
    else{
        while (temp->next->next != *head) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = *head;
        free(toDelete);
    }
}
void deleteAtIndex(Node **head, int index) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (index == 0) {
        deleteAtBeginning(head);
        return;
    }
    for (int i = 0; i < index - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next != *head) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}
void printList(Node* head) {
    if (head == NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
int main() {
    Node* head = NULL;
    int choice, data, index;
    while(1){
        printf("\n1) Insert at user-specific index\n");
        printf("2) Insert at the beginning\n");
        printf("3) Insert at the last index\n");
        printf("4) Delete from user-specific index\n");
        printf("5) Delete from the beginning\n");
        printf("6) Delete from the last index\n");
        printf("7) Undo\n");
        printf("8) Redo\n");
        printf("9) Print list\n");
        printf("10) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the index to insert: ");
                scanf("%d", &index);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                pushUndo(head); 
                insertAtIndex(&head, data, index);
                break;
            case 2:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                pushUndo(head);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                pushUndo(head);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                pushUndo(head);
                deleteAtIndex(&head, index);
                break;
            case 5:
                pushUndo(head);
                deleteAtBeginning(&head);
                break;
            case 6:
                pushUndo(head);
                deleteAtEnd(&head);
                break;
            case 7:
                undo(&head);
                break;
            case 8:
                redo(&head);
                break;
            case 9:
                printList(head);
                break;
            case 10:
                exit(0);
        }
    }
}