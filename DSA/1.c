#include<stdio.h>
#include<stdlib.h>
typedef struct citytemp
{
    char name[20];
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;
}c;
 int main()
 {
    printf("Enter the number of cities you want to register : ");
    int n,k=0;
    scanf("%d",&n);
    c c[n];
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the name of city %d : ",i+1);
        scanf(" %[^\n]s\n",c[i].name);
        c[i].t1 = rand()%(21)+20;
        c[i].t2 = rand()%(21)+20;
        c[i].t3 = rand()%(21)+20;
        c[i].t4 = rand()%(21)+20;
        c[i].t5 = rand()%(21)+20;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=(c[i].t1+c[i].t2+c[i].t3+c[i].t4+c[i].t5)/5;
    }
    for(int i=0;i<n;i++)
    {
        k+=a[i];
    }
    k=k/n;
    for(int i=0;i<n;i++)
    {
        printf("Average temperature of %s is %d celsius\n",c[i].name,a[i]);
    }
    printf("Average temperature all the ciies is %d celsius",k);
 }