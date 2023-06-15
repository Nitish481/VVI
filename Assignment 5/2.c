#include <stdio.h>
#include <stdlib.h>
int n;
int *create(int *arr)
{
    printf("\nEnter The Size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter The Elements in sorted order: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter %dth element: ", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}
void bubbleSort(int *arr)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
void insertSort(int *arr)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
void selectionSort(int *arr)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void display(int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int ch, *arr;
    do
    {
        printf("\n-------------MENU--------------\n\nEnter 1 for Create an array\nEnter 2 for display the array\nEnter 3 for Bubble Sort\nEnter 4 for Insertion Sort\nEnter 5 for  Selection Sort\nEnter 0 for Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            arr = create(arr);
            break;
        case 2:
            display(arr);
            break;
        case 3:
            bubbleSort(arr);
            printf("\nSorted array: ");
            display(arr);
            break;
        case 4:
            insertSort(arr);
            printf("\nSorted array: ");
            display(arr);
            break;
        case 5:
            selectionSort(arr);
            printf("\nSorted array: ");
            display(arr);
            break;
        default:
            printf("\nInvalid input!");
            break;
        }
    } while (ch != 0);

    return 0;
}