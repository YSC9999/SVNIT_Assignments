#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} n;
n* create(int data) {
    n* new = malloc(sizeof(n));
    new->data = data;
    new->next = NULL;
    return new;
}
int main(){
    int max, h1, h2;
    printf("Give the degree of the polynomial: ");
    scanf("%d", &max);
    printf("Give the coefficient for X^%d of polynomial 1: ", max);
    scanf("%d", &h1);
    n* head1 = create(h1), *temp1 = head1;
    printf("Give the coefficient for X^%d of polynomial 2: ", max);
    scanf("%d", &h2);
    n* head2 = create(h2), *temp2 = head2;
    for (int i = 1; i <= max; i++) {
        printf("Give the coefficient for X^%d of polynomial 1: ", max - i);
        scanf("%d", &h1);
        temp1->next = create(h1);
        temp1 = temp1->next;
        printf("Give the coefficient for X^%d of polynomial 2: ", max - i);
        scanf("%d", &h2);
        temp2->next = create(h2);
        temp2 = temp2->next;
    }
    int t = max * 2 + 1;
    int a[t];
    for (int i = 0; i < t; i++) {
        a[i] = 0;
    }
    temp1 = head1;
    int i, j;
    for (i = 0; temp1 != NULL; i++) {
        temp2 = head2;
        for (j = 0; temp2 != NULL; j++) {
            a[i + j] += temp1->data * temp2->data;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    printf("The resulting polynomial coefficients are:\n");
    for (int i = 0; i < t; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}