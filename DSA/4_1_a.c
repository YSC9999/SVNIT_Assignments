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
        printf("Give the data of node to be inserted at %d: ",pos);
        scanf("%d",&var);
        n* head = createnode(var);
        head->next = temp_head;
        temp = head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    else if(pos==no){
        printf("Give the data of node to be inserted at %d: ",pos);
        scanf("%d",&var);
        while((temp->next)!=NULL){
            temp = temp->next;
        }
        temp->next = createnode(var);
        temp = temp->next;
        temp = temp_head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    else{
        printf("Give the data of node to be inserted at %d: ",pos);
        scanf("%d",&var);
        int i = 0;
        n *s,*e;
        while(temp!=NULL){
            if(i>pos){
                break;
            }
            else if(i==pos-1){
                s = temp;
            }
            else if(i==pos){
                e = temp;
            }
            temp = temp->next;
            i++;
        }
        n* new = createnode(var);
        s->next = new;
        new->next = e;
        temp = temp_head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}