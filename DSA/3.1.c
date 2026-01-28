#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,index;
    printf("Give the no. of names: ");
    scanf("%d",&n);
    char p[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    printf("Names without inseting new name\n");
    for(int k=0;k<n;k++){
    printf("%s ",p[k]);
    }
    printf("\nGive the index value which is to be replaced: ");
     scanf("%d",&index);
    printf("Give a  new name: ");
    scanf("%s",p[index]);
    printf("Names after inseting new name\n");
    for(int k=0;k<n;k++){
    printf("%s ",p[k]);
    }
}