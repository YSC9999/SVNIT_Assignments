#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
n* create(int data){
    n* new = malloc(sizeof(n));
    new->data = data;
    new->next = NULL;
    return new;
}
int main(){
    int max,h1,h2;
    printf("Give the degree of the polyonomial by comparing both: ");
    scanf("%d",&max);
    printf("Give the coefficent for X^%d of polynoimal 1: ",max);
    scanf("%d",&h1);
    printf("Give the coefficent for X^%d of polynoimal 2: ",max);
    scanf("%d",&h2);
    n* head1 = create(h1),*temp1 = head1;
    n* head2 = create(h2),*temp2 = head2;
    for(int i=1;i<=max;i++){
        printf("Give the coefficent for X^%d of polynoimal 1: ",max-i);
        scanf("%d",&h1);
        temp1->next = create(h1);
        temp1 = temp1->next;
        printf("Give the coefficent for X^%d of polynoimal 2: ",max-i);
        scanf("%d",&h2);
        temp2->next = create(h2);
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    int i = max;
    while(temp1!=NULL){
        if(i!=0){
            printf("%dX^%d",temp1->data+temp2->data,i);
        }
        else{
            printf("%d",temp1->data+temp2->data);
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(i!=0){
            printf("+");
        }
        i--;
    }
}