#include <stdio.h>
void sort(int a[], int n)
{
    int x;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
}
int main()
{
    int o, p;
    printf("Enter the number elements in the array : ");
    scanf("%d", &o);
    printf("Enter the number elements in the array : ");
    scanf("%d", &p);
    int a[o], b[p], c[o + p];
    printf("\nEnter the elements of first array : \n");
    for (int i = 0; i < o; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements of second array : \n");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < o+p; i++)
    {
        if (i < o)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i - o];
        }
    }
    sort(c, o+p);
    for (int i = 0; i < o+p; i++)
    {
        printf("%d  ", c[i]);
    }
}