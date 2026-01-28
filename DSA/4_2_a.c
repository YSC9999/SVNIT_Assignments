#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*previ,*next;
}n;
n* create(int data){
    n* new = malloc(sizeof(n));
    new->data = data;
    new->next = NULL;
    new->previ = NULL;
    return new;
}
int main(){
    int no,var,pos;
    printf("number of elements in the linked list: ");
    scanf("%d",&no);
    printf("Give the data: ");
    scanf("%d",&var);
    n* temp_head = create(var),*temp = temp_head;
    for(int i=1;i<no;i++){
        printf("Give the data: ");
        scanf("%d",&var);
        n* prev = create(var);
        temp->next = prev;
        prev->previ = temp;
        temp = temp->next;
    }
    printf("Before insertion\n");
    temp = temp_head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\nin which position a node to be inserted and data: ");
    scanf("%d %d",&pos,&var);
    if(pos==0){
        temp = temp_head;
        n* head = create(var);
        head->next = temp_head;
        temp_head->previ = head;
        temp = head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        return 0;
    }
    else if(pos==no){
        temp = temp_head;
        while(temp->next!=NULL){
        temp = temp->next;
    }
        n* end = create(var);
        temp->next = end;
        end->previ = temp;
    }
    else{
        temp = temp_head;
        n* ins = create(var),*p,*n;
        int i=0;
        while(temp!=NULL){
            if(i==pos-1){
                p = temp;
            }
            else if(i==pos){
                n = temp;
                p->next = ins;
                ins->next = n;
                ins->previ = p;
                n->previ = ins;
            }
            i++;
            temp = temp->next;
        }
    }
    temp = temp_head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}