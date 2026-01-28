#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return root;
    
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    
    int choice = -1;
    printf("1. Insert\n2. Delete\n3. find min\n4. Inorder traves\n5. Exit\n");
    while (choice != 5) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int value;
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice == 2) {
            int value;
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
        } else if (choice == 3) {
            Node* minNode = findMin(root);
            if (minNode != NULL) {
                printf("Minimum value in the tree: %d\n", minNode->data);
            } else {
                printf("Tree is empty.\n");
            }
        } else if (choice == 4) {
            inorder(root);
            printf("\n");
        } else if (choice != 5) {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}