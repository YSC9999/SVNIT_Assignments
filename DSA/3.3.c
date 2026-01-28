#include<stdio.h>
#include<string.h>
int main(){
    int n,t=0;
    printf("No of names to be inserted: ");
    scanf("%d",&n);
    char p[n][100];
    for(int i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    printf("give the string: ");
    char str[100];
    scanf("%s",str);
    for(int i=0;i<n;i++){
        if(!strcmp(str,p[i])){
            t = 1;
        }
    }
    if(t==0){
        printf("string did not matched with names");
    }
    else{
        printf("string matched with names");
    }
}