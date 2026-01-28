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
void insertBottom(Node **head, int data) {
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
void insertTop(Node **head, int data){
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
void deleteBottom(Node **head) {
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
void deleteTop(Node **head){
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
void printList(Node* head) {
    if (head == NULL){
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("(Bottom) -> ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Top)\n");
}
int main() {
    Node* head = NULL;
    int choice, data, index;
    while(1){
        printf("1) Insert at the Bottom\n");
        printf("2) Insert at the Top\n");
        printf("3) Delete from the Bottom\n");
        printf("4) Delete from the Top\n");
        printf("5) Peek\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertBottom(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertTop(&head, data);
                break;
            case 3:
                deleteBottom(&head);
                break;
            case 4:
                deleteTop(&head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                exit(0);
        }
    }
}