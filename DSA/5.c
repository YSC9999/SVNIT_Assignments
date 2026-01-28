#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
n* createnode(int data){
    n *p = malloc(sizeof(n)*1);
    p->data = data;
    p->next = NULL;
    return p;
}
int main()
{
    int no;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&no);
    int a[no];
    for(int i=0;i<no;i++){
        scanf("%d",&a[i]);
    }
    if(no>0){
        n* head = createnode(a[0]),*temp = head;
        for(int i=1;i<no;i++){
            temp->next = createnode(a[i]);
            temp = temp->next;
        }
        printf("linked list created successfully\n");
        temp->next = head;
        temp = head;
        int i = 0;
        while(i!=7){
            printf("%d ",temp->data);
            temp = temp->next;
            i++;
        }
    }
    else{
        printf("INVALID LINKED LIST");
    }  
}