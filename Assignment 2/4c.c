#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *left;
    struct list *right;
};
typedef struct list *node;
node createNode(int i)
{
    node temp;
    temp = (node)malloc(sizeof(struct list));
    temp->data = i;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void createList(int n, node *head)
{
    node temp, rear;
    *head = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = createNode(i);
        if (*head == NULL)
        {
            *head = temp;
            rear = *head;
            rear->right = *head;
            rear->left = *head;
        }
        else
        {
            rear->right = temp;
            temp->left = rear;
            rear = rear->right;
            rear->right = *head;
            (*head)->left = rear;
        }
    }
}
int ex(int n, int k, int st, node *head)
{
    int i;
    node r, prev;
    r = *head;
    for (i = 0; i < st; i++)
        r = r->right;
    while ((*head)->right != *head)
    {
        for (i = 0; i <= k; i++)
            r = r->right;
        if (r == *head)
        {
            prev = (*head)->left;
            (*head) = (*head)->right;
            prev->right = (*head);
            (*head)->left = prev;
            r->left = NULL;
            r->right = NULL;
            free(r);
            r = *head;
        }
        else if (r->right == *head)
        {
            prev = r->left;
            prev->right = *head;
            (*head)->left = prev;
            r->right = NULL;
            r->left = NULL;
            free(r);
            r = *head;
        }
        else
        {
            prev = r->left;
            prev->right = r->right;
            r->right->left = prev;
            r->left = NULL;
            r->right = NULL;
            free(r);
            r = prev->right;
        }
    }
    return (*head)->data;
}

int main()
{
    
    node head;
    int n, k, st;
    printf("\nEnter no of people: ");
    scanf("%d", &n);
    printf("\nEnter skips: ");
    scanf("%d", &k);
    printf("\nEnter starting point(0-%d): ", n - 1);
    scanf("%d", &st);
    createList(n, &head);
    printf("\nPerson alive: %d\n", ex(n, k, st, &head));
      
   
    return 0;
}