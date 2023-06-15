#include <stdio.h>
#include <stdlib.h>
int **createArr(int n)
{
    int **arr = (int **)calloc(sizeof(int *), 2);
    for (int i = 0; i < 2; i++)
        arr[i] = (int *)calloc(sizeof(int), n);
    for (int i = 0; i < n; i++)
        arr[0][i] = i + 1;
    return arr;
}
int left(int **m, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[1][i] == 0)
            count++;
    }
    return count;
}
int ex(int **p, int n, int k, int st)
{
    int i = st, sk;
    while (left(p, n) > 1)
    {
        while (p[1][i] != 0)
            i = (i + 1) % n;
        sk = 0;
        while (sk <= k)
        {
            if (p[1][i] == 0)
                sk++;
            i = (i + 1) % n;
        }
        
        while (p[1][i] != 0)
            i = (i + 1) % n;
        p[1][i] = 1;
       
    }
    for (i = 0; i < n; i++)
    {
        if (p[1][i] == 0)
            return i;
    }
}

int main()
{
    
    int n, k, st;
    int **p;
        printf("\nEnter no of people: ");
        scanf("%d", &n);
        printf("\nEnter skips: ");
        scanf("%d", &k);
        printf("\nEnter starting point(0-%d): ", n - 1);
        scanf("%d", &st);
        p = createArr(n);
        printf("\nPerson alive: %d\n", ex(p, n, k, st));

    return 0;
}
