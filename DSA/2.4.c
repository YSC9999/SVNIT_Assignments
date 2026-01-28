#include<stdio.h>
int main()
{
    int A[3][3],B[3][3],t;
    printf("Enter the elements of matrix A\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter the value of A[%d][%d] : ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the elements of matrix B\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter the value of B[%d][%d] : ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(A[i][j]==B[i][j])
            {
                t=1;
            }
            else
            {
                t=0;
                break;
            }
        }
    }
    if(t)
    {
        printf("Both matrices are equal.");
    }
    else
    {
        printf("Both matrices are unequal.");
    }
}