#include<stdio.h>
#include<stdlib.h>

/*
				50
		20				60
			30				
*/


typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

//Create tree
void create_tree(NODE **p)
{
	*p=NULL;
	printf("Binary Search Tree is created\n");
	return;
}

//Create node
NODE* create(int n)
{
	NODE *t=(NODE *)malloc(sizeof(NODE));
	t->data=n;
	t->left=NULL;
	t->right=NULL;
	return(t);
}

//Insert iterative
void insertiterative(NODE **p,int n)
{
	NODE *c,*t=*p;
	c=create(n);
	if(*p==NULL)
	{
		*p=c;
		return;
	}
	while(t!=NULL)
	{
		if(t->data==n)
		{
			printf("No dublicate data please\n");
			return;
		}
		else if(t->data<n)
		{
			if(t->right!=NULL)
				t=t->right;
			else
			{
				t->right=c;
				return;
			}
		}
		else
		{
			if(t->left!=NULL)
				t=t->left;
			else
			{
				t->left=c;
				return;
			}
		}
	}
}

//pre order traversal
void preorder(NODE *p)
{
	if(p==NULL)
		return;
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
	return;
}

//In order traversal
void inorder(NODE *p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
	return;
}

//Post order traversal
void postorder(NODE *p)
{
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
	return;
}

//Search iterative
NODE* searchiterative(NODE *p,int n)
{
	NODE *t=p;
	if(p==NULL)
		return(NULL);
	while(t!=NULL)
	{
		if(t->data==n)
			return(t);
		if(t->data<n)
			t=t->right;
		else
			t=t->left;
	}
	return(NULL);
}

//Smallest element
NODE* small(NODE *p)
{
	NODE *c=p;
	while(c->left!=NULL)
		c=c->left;
	return(c);
}

//delete
NODE* deletenode(NODE *p,int n)
{
	NODE *t;
	if(p==NULL)
		return(p);
	if(p->data<n)
		p->right=deletenode(p->right,n);
	else if(p->data>n)
		p->left=deletenode(p->left,n);
	else
	{
		if(p->left==NULL)
		{
			t=p->right;
			free(p);
			return(t);	
		}
		if(p->right==NULL)
		{
			t=p->left;
			free(p);
			return(t);
		}
		t=small(p->right);
		p->data=t->data;
		p->right=deletenode(p->right,t->data);	
	}
	return(p);
}

int main()
{
	NODE *root;
	int choice,n;
	do
	{
		printf("\n\nEnter option :\n");
		printf("0 -> Exit\n1 -> Create Tree\n2 -> Insert iterative\n3 -> Pre order traversal\n4 -> Inorder traversal\n5 -> Post order traversal\n6 -> Search iterative\n7 -> Delete\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				break;
			case 1:
				create_tree(&root);
				break;
			case 2:
				printf("Enter the data to be inserted = ");
				scanf("%d",&n);
				insertiterative(&root,n);
				break;
			case 3:
				printf("\nPreorder traversal : ");
				preorder(root);
				break;
			case 4:
				printf("\nInorder traversal : ");
				inorder(root);
				break;
			case 5:
				printf("\nPostorder traversal : ");
				postorder(root);
				break;
			case 6:
				printf("Enter the data to be search = ");
				scanf("%d",&n);
				if(searchiterative(root,n))
					printf("Value found\n");
				else
					printf("Value not found");
				break;
			case 7:
				printf("Enter the data to be deleted = ");
				scanf("%d",&n);
				root=deletenode(root,n);
				break;
			default:
				printf("Enter a number between 0 to 12\n");
				break;
		}
	}while(choice!=0);
	return(0);
}
