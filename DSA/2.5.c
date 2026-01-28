#include <stdio.h>
int main()
{
    int n,x;
    printf("Enter the number of elements to be entered : ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element A[%d] : ", i+1);
        scanf("%d", &A[i]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] < A[j])
            {
                x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }
    printf("Rearranged array A :\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",A[i]);
    }
}