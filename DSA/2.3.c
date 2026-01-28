#include<stdio.h>
int main()
{
    int n,k,t=0,j=0;
    printf("Enter the number of elements you need : ");
    scanf("%d",&n);
    int A[n],B[n];
    while(n>0)
    {
        printf("Enter number : ");
        scanf("%d",&k);
        if(k%2==0)
        {
            A[t]=k;
            t++;
        }
        else
        {
            B[j]=k;
            j++;
        }
        n--;
    }
    printf("Array A =\t");
    for(int i=0;i<t;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\nArray B =\t");
    for(int i=0;i<j;i++)
    {
        printf("%d\t",B[i]);
    }
}