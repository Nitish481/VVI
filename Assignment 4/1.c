#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE * create()
{
	NODE *t;
	char ch;
	t=(NODE *)malloc(sizeof(NODE));
	printf("Enter the data of the node = ");
	scanf("%d",&t->data);
	printf("Do you want to add left child of %d  \nEnter Y/y for yes \nEnter N/n for no\n",t->data);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
		t->left=create();
	else
		t->left=NULL;
	printf("Do you want to add right child of %d  \nEnter Y/y for yes \nEnter N/n for no\n",t->data);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
		t->right=create();
	else
		t->right=NULL;
	return t;
}

void preorder(NODE *p)
{
	if(p==NULL)
		return;
	printf("%d  ",p->data);
	preorder(p->left);
	preorder(p->right);
	return;
}

void inorder(NODE *p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d  ",p->data);
	inorder(p->right);
	return;
}

void postorder(NODE *p)
{
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d  ",p->data);
	return;
}

int main()
{
	NODE *root=NULL;
	int choice,data;
	do
	{
		printf("\n\n----------------MENU---------------\nEnter your choice\nEnter 1 for create\nEnter 2 for preorder traversal\nEnter 3 for inorder traversal\nEnter 4 for postorder traversal\nEnter 0 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("Program terminates\n");
				break;
			case 1:
				root=create();
				printf("Binary tree created successfully\n");
				break;
			case 2:
				if(root==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Preorder traversal :    ");
					preorder(root);
					printf("\n");
				}
				break;
			case 3:
				if(root==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Inorder traversal :    ");
					inorder(root);
					printf("\n");
				}
				break;
			case 4:
				if(root==NULL)
					printf("No tree created. First create a tree\n");
				else
				{
					printf("Postorder traversal :    ");
					postorder(root);
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
