#include <stdio.h>
int main()
{
    int n, m, k = 0, r = 0, t = 0, sum = 0;
    printf("Enter the number of elements for array A : ");
    scanf("%d", &n);
    printf("Enter the number of elements for array B : ");
    scanf("%d", &m);
    int A[n], B[m];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element A[%d] : ", i + 1);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("Enter element B[%d] : ", i + 1);
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j])
            {
                k++;
            }
        }
    }
    int a[k], b[k], s1[k + 1], s2[k + 1];
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j])
            {
                a[k] = i;
                b[k] = j;
                k++;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (i == a[t] || i == n)
        {
            s1[r] = sum;
            sum = 0;
            r++;
            t++;
        }
        else
        {
            sum += A[i];
        }
    }
    t = 0;
    r = 0;
    for (int i = 0; i < m + 1; i++)
    {
        if (i == b[t] || i == m)
        {
            s2[r] = sum;
            sum = 0;
            r++;
            t++;
        }
        else
        {
            sum += B[i];
        }
    }
    sum = 0;
    for (int i = 0; i < k + 1; i++)
    {
        if (s1[i] < s2[i])
        {
            sum += s2[i];
        }
        else
        {
            sum += s1[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        sum += A[a[i]];
    }
    printf("Maximum sum from the arrays is %d", sum);
}