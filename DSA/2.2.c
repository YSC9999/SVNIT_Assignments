#include <stdio.h>
int check(int a[], int i)
{
    int k;
    if (i == 0)
    {
        return 1;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                k = 0;
                break;
            }
            else
            {
                k = 1;
            }
        }
        return k;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter the elements of the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (check(a, i))
        {
            printf("%d  ", a[i]);
        }
    }
}