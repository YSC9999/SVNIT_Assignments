#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}n;
n* create(int data){
    n* new = malloc(sizeof(n));
    new->data = data;
    new->next = NULL;
}
n* pop(n* add){
    n* temp = add;
    add = add->next;
    free(temp);
    return add;
}
n* push(n* add,int data){
    n* new = malloc(sizeof(n));
    new->data = data;
    new->next = add;
    return new;
}
void display(n*top){
    n* temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main(){
    int x,c,data,cs=1;
    printf("Give the first element: ");
    scanf("%d",&x);
    n* top = create(x);
    top->next = NULL;
    while(1){
        printf("\n1.push\n2.pop\n3.peek\n4.exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Give the data: ");
            scanf("%d",&data);
            top = push(top,data);
            display(top);
            cs++;
            break;
        case 2:
           if(cs==0){
               printf("UNDERFLOW");
               break;
            }
            else if(cs==1){
                printf("EMPTY");
            }
           top = pop(top);
           display(top);
           cs--;
           break;
        case 3:
        if(cs==0){
            printf("UNDERFLOW");
            break;
        }
           printf("peek: %d",top->data);
           break;
        case 4:
           return 0;
           break;
        default:
            printf("INVALID CHOICE");
            break;
        }
    }
}