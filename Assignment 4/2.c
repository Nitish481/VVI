#include<stdio.h>
#include<stdlib.h>
#define NON -100

/*
				10
		20				30
			40					70
		50		60			80
*/

void create(int *a,int n,int i)
{
	int d;
	char ch;
	if(i<n)
	{
		printf("Enter data = ");
		scanf("%d",&d);
		a[i]=d;
		printf("Do you want to add left child of %d  \nEnter Y/y for yes \nEnter N/n for no\n",a[i]);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
			create(a,n,2*i+1);
		printf("Do you want to add right child of %d  \nEnter Y/y for yes \nEnter N/n for no\n",a[i]);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
			create(a,n,2*i+2);
	}
	else
		printf("Array full\n");
	return;
}

void preorder(int *a,int n,int i)
{
	if(i>=n||a[i]==NON)
		return;
	printf("%d  ",a[i]);
	preorder(a,n,2*i+1);
	preorder(a,n,2*i+2);
	return;
}

void inorder(int *a,int n,int i)
{
	if(i>=n||a[i]==NON)
		return;
	inorder(a,n,2*i+1);
	printf("%d  ",a[i]);
	inorder(a,n,2*i+2);
	return;
}

void postorder(int *a,int n,int i)
{
	if(i>=n||a[i]==NON)
		return;
	postorder(a,n,2*i+1);
	postorder(a,n,2*i+2);
	printf("%d  ",a[i]);
	return;
}

int main()
{
	int *arr=NULL;
	int choice,data,n,i;
	do
	{
		printf("\n\n***************MENU***************\nEnter your choice\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for preorder traversal\nEnter 3 for inorder traversal\nEnter 4 for postorder traversal\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("Program terminates\n");
				break;
			case 1:
				printf("Enter size of array = ");
				scanf("%d",&n);
				arr=(int *)malloc(sizeof(int)*n);
				for(i=0;i<n;i++)
				{
					arr[i]=NON;
				}
				create(arr,n,0);
				printf("Binary tree created successfully\n");
				break;
			case 2:
				if(arr==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Preorder traversal :    ");
					preorder(arr,n,0);
					printf("\n");
				}
				break;
			case 3:
				if(arr==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Inorder traversal :    ");
					inorder(arr,n,0);
					printf("\n");
				}
				break;
			case 4:
				if(arr==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Postorder traversal :    ");
					postorder(arr,n,0);
					printf("\n");
				}
				break;
			default:
				printf("Enter valid option between 0 to 4\n");
				break;
		}
	}while(choice!=0);
	return 0;
}
