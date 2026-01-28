#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
n* cn(int data){
    n *p = malloc(sizeof(n)*1);
    p->data = data;
    p->next = NULL;
    return p;
}
int *array(n* link,int size){
    int i=0,*a = calloc(size,sizeof(int));
    n* temp = link;
    while(temp!=NULL){
        a[i] = temp->data;
        temp = temp->next;
        i++;
    }
    return a;
}
int main(){
    int no,i=1;
    printf("Give number of elements to be added in linked list: ");
    scanf("%d",&no);
    int var,size=0;
    printf("Give the first element's data: ");
    scanf("%d",&var);
    n* head = cn(var),*temp = head;
    while(i<no){
        printf("Give the data: ");
        scanf("%d",&var);
        temp->next = cn(var);
        temp = temp->next;
        i++;
    }
    int *p = array(head,no);
    i=0;
    while(no>i){
        printf("%d ",p[i]);
        i++;
    }
    free(p);
}



