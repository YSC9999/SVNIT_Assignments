#include<stdio.h>
#include<string.h>
int main(){
    int n,index;
    printf("No of names to be inserted: ");
    scanf("%d",&n);
    char p[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    printf("give the index of the name: ");
    scanf("%d",&index);
    strcpy(p[index],"Deleted");
    for(int k=0;k<n;k++){
    printf("%s ",p[k]);
    }
}