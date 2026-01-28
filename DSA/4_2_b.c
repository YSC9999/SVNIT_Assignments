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
    printf("Before deletion\n");
    temp = temp_head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\nin which position a node to be deleted: ");
    scanf("%d",&pos);
    if(pos==0){
        temp_head = temp_head->next;
        temp_head->previ = NULL;
        temp = temp_head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        return 0;
    }
    else if(pos==no-1){
        temp = temp_head;
        while(temp->next!=NULL){
        temp = temp->next;
    }
       temp->previ->next = NULL;
    }
    else{
        temp = temp_head;
        n *p,*n;
        int i=0;
        while(temp!=NULL){
            if(i==pos){
                p = temp->previ;
            }
            else if(i==pos+1){
                n = temp;
                p->next = n;
                n->previ = p;
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