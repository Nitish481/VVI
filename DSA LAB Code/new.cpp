#include <stdio.h>
#include <stdlib.h>

void updateArray(int *arr, int indx, int value, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (i >= indx)
        {
            if (arr[i] == value)
            {
                arr[i] = 0;
            }
            else if (arr[i] > value)
            {
                arr[i] -= 1;
            }
        }
    }
}

void solver(int *q, int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int index_of_item_to_delete = arr[i];

        int *temp = (int *)malloc(n * sizeof(int));
        int temp_size = 0;

        for (int j = 1; j < index_of_item_to_delete; j++)
        {
            temp[temp_size++] = q[0];
            for (int k = 0; k < n - 1; k++)
            {
                q[k] = q[k + 1];
            }
        }
        printf("%d\n", q[0]);
        for (int j = 0; j < temp_size; j++)
        {
            q[j] = temp[j];
        }

        updateArray(arr, i, index_of_item_to_delete, n);
        free(temp);
    }
}

int main()
{
    int n;
    printf("Enter the No. of element of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        printf("Enter The elements : ");
        scanf("%d", &arr[i]);
    }

    int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        q[i] = x;
    }

    solver(q, arr, n);

    free(arr);
    free(q);

    return 0;
}
