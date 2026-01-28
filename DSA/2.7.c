#include <stdio.h>
int main()
{
    int n, m, x, t, o, p, r;
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
    printf("Enter the number : ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r = x - (A[i] + A[j]);
            if (r >= 0)
            {
                if (r < t)
                {
                    t = r;
                    o = i;
                    p = j;
                }
            }
            else
            {
                r = -r;
                if (r < t)
                {
                    t = r;
                    o = i;
                    p = j;
                }
            }
        }
    }
    printf("A[%d] + B[%d] = %d + %d is the closest to %d.", o + 1, p + 1, A[o], B[p], x);
}