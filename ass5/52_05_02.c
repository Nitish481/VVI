#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *a, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void insertSort(int *a, int n)
{
     int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }
}
void selectionSort(int *a,int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void displayArray(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int ch,*a,n;
    printf("\nEnter no of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter the %d elements:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("\n0->Quit\n1->Bubble Sort\n2-> Insertion Sort\n3-> Selection Sort\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            bubbleSort(a,n);
            printf("\nSorted:\n");
            displayArray(a,n);
            break;
        case 2:
            insertSort(a,n);
            printf("\nSorted:\n");
            displayArray(a,n);
            break;
        case 3:
            selectionSort(a,n);
            printf("\nSorted:\n");
            displayArray(a,n);
            break;
        default:
            printf("\nInvalid input!");
            break;
        }
    } while (ch!=0);
    
    return 0;
}