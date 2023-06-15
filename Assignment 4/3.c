#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/*
				10
		20				30
			40					70
		50		60			80
*/

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	bool l;
	bool r;
}NODE;

NODE * create(NODE *p,int i)
{
	NODE *t,*c;
	char ch;
	if(p==NULL)
	{
		p=(NODE *)malloc(sizeof(NODE));
		p->data=-999;
		p->l=false;
		p->r=false;
		p->right=p;
		p->left=p;
		p->left=create(p,0);
		return p;
	}
	else
	{
		t=(NODE *)malloc(sizeof(NODE));
		printf("Enter data = ");
		scanf("%d",&t->data);
		t->l=true;
		t->r=true;
		if(i==0)
		{
			t->left=p->left;
			t->right=p;
		}
		else
		{
			t->left=p;
			t->right=p->right;
		}
		printf("Do you want to add a left child of %d ?\n",t->data);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			t->left=create(t,0);
			t->l=false;
		}
		printf("Do you want to add a right child of %d ?\n",t->data);
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			t->right=create(t,1);
			t->r=false;
		}
	}
	return t;
}

void preorder(NODE *p)
{
	NODE *t=p->left;
	while(t!=p)
	{
		while(t->l==false)
		{
			printf("%d  ",t->data);
			t=t->left;
		}
		printf("%d  ",t->data);
		while(t->r==true)
		{
			t=t->right;
			if(t==p)
				break;
		}
		t=t->right;
	}
	return;
}

void inorder(NODE *p)
{
	NODE *t=p->left;
	while(t!=p)
	{
		while(t->l==false)
			t=t->left;
		printf("%d  ",t->data);
		while(t->r==true)
		{
			t=t->right;
			if(t==p)
				break;
			printf("%d  ",t->data);
		}
		t=t->right;
	}
	return;
}

int main()
{
	NODE *root;
	int choice,data;
	do
	{
		printf("\n\n***************MENU***************\nEnter your choice\nEnter 0 for exit\nEnter 1 for create\nEnter 2 for preorder traversal\nEnter 3 for inorder traversal\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("Program terminates\n");
				break;
			case 1:
				root=NULL;
				root=create(root,0);
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
			default:
				printf("Enter valid option between 0 to 3\n");
				break;
		}
	}while(choice!=0);
	return 0;
}
