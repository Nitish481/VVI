#include <stdio.h>
#include <stdlib.h>
int n;
int *create(int *arr)
{   
    printf("\nEnter The Size of the array: ");
    scanf("%d",&n);
    arr=(int *)malloc(n * sizeof(int));
    printf("\nEnter The Elements in sorted order: \n");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter %dth element: ",i);
        scanf("%d",&arr[i]);
    }
    return arr;
}
void display(int *arr)
{   
    printf("\nThe array is: ");
    printf("[ ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
       
    }
    printf("]");
    printf("\n");
}
void Linear(int *arr,int ele)
{
    int flag=0,i,pos;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
       {
           flag = 1;
           pos = i;
           break;
       }
      
    }
    if(flag==1)
    printf("\nElement %d Found at Position: %d\n", ele,pos);
    else
    printf("\nElement not present in the array!!\n");
}
int Binary(int *arr,int first,int last,int mid,int ele)
{
while (first <= last)
 {
    if (arr[mid] < ele)
    first = mid + 1;
    else if (arr[mid] == ele)
    {
    printf("\nElement %d Found at Position: %d\n", ele, mid);
    break;
    }
    else
    last = mid - 1;

    mid = (first + last) / 2;
 }
    if (first > last)
    printf("\nElement not present in the array!!\n");
}
int main()
{
    int *arr=NULL,ch,x,ele;
    while(1)
    {
    printf("\n-------------MENU--------------\n\nEnter 1 for Create an array\n\nEnter 2 for display the array\n\nEnter 3 for Linear Search\n\nEnter 4 for Binary Search\n\nEnter Your Choice: ");
    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        arr = create(arr);
        break;
    case 2:
        display(arr);
        break;
    case 3:
        printf("\nEnter an element to be searched: ");
        scanf("%d", &ele);
        Linear(arr,ele);
        break;
    case 4:
        printf("\nEnter an element to be searched: ");
        scanf("%d", &ele);
        int first = 0;
        int last = n - 1;
        int  mid = (first + last) / 2;
        Binary(arr,first,last,mid,ele);
        break; 
    case 0:
       printf("Program terminates\n");
       break;
        }

    }
    
}