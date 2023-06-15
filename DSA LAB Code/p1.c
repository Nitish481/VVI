#include<stdio.h>
void display(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
/*int sortedInsertion(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity)
    return -1;
    else
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index] =element;
}*/
int deletion(int arr[],int size,int index)
{
    if(index > size)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    
}
int main()
{
    int arr[100] = {1,2,6,78};
    int size =4;
    int element = 45;
   int index =5;

    display(arr,size);
    //sortedInsertion(arr,size,element,100,index);
    deletion(arr,size,index);
    size-=1;
    display(arr,size);

}