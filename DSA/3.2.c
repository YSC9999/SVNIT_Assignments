#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,new;
    printf("Give the no. of names");
    scanf("%d",&n);
    char **p;
    p = (char *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        p[i] = (char *)malloc(sizeof(char)*100);
    }
    for(int i=0;i<n;i++){
            scanf("%s",p[i]);
    }
    printf("Names without appending new name\n");
    for(int k=0;k<n;k++){
    printf("%s ",p[k]);
    }
    printf("\nHow many name do you wnat to insert");
    scanf("%d",&new);
    p = (char *)realloc(p,sizeof(int)*(n+new));
    for(int i=n;i<n+new;i++){
        p[i] = (char *)malloc(sizeof(char)*100);
    }
    for(int i=n;i<n+new;i++){
        scanf("%s",p[i]);
    }
    for(int i=0;i<n+new;i++){
        printf("%s ",p[i]);
    }
    free(p);
}