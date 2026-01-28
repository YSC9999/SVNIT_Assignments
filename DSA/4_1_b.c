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
int main(){
    int no,var,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&no);
    int a[no];
    for(int i=0;i<no;i++){
        scanf("%d",&a[i]);
    }
    n* temp_head = createnode(a[0]),*temp = temp_head;
    for(int i=1;i<no;i++){
        temp->next = createnode(a[i]);
        temp = temp->next;
    }
    printf("linked list created successfully\n Give the index where the new node to be inserted: ");
    scanf("%d",&pos);
    temp = temp_head;
    if(pos==0){
        n* head;
        head = temp->next;
        temp = head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    else if(pos==no-1){
        int i=0;
        while(i<pos){
            if(i==pos-1){
                temp->next = NULL;
                break;
            }
            temp = temp->next;
            i++;
        }
        temp = temp_head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    else{
        int i = 0;
        n* p,*ne;
        while(i<=pos){
            if(i==pos-1){
                p = temp;
            }
            else if(i==pos){
                ne = temp->next;
            }
            i++;
            temp = temp->next;
        }
        p->next = ne;
        temp = temp_head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}