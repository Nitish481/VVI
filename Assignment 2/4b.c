#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list *next;
};

typedef struct list *node;

node createNode(int i)
{
    node temp;
    temp = (node)malloc(sizeof(struct list));
    temp->data = i;
    temp->next = NULL;
    return temp;
}
void createList(int n, node *head)
{
    node rear, temp;
    int i;
    *head = NULL;
    for (i = 0; i < n; i++)
    {
        
        temp = createNode(i);
        if (*head == NULL)
        {
            *head = temp;
            rear = *head;
            rear->next = *head;
        }
        else
        {

            rear->next = temp;
            rear = rear->next;
            rear->next = *head;
        }
    }
}
void display(node head)
{
    node t;
    t = head;
    while (t->next != head)
    {
        printf("%d ->", t->data);
        t = t->next;
    }
    printf("%d", t->data);
}

int ex(int n, int k, int st, node *head)
{
    int i;
    node r, prev;
    r = *head;

    for (i = 0; i < st; i++)
        r = r->next;
    while ((*head)->next != *head)
    {
        for (i = 0; i <= k; i++)
            r = r->next;
        if (r == *head)
        {
            prev = *head;
            while (prev->next != *head)
                prev = prev->next;
            *head = (*head)->next;
            prev->next = *head;
            r->next = NULL;
            free(r);
            r = *head;
        }
        else if (r->next == *head)
        {
            prev = *head;
            while (prev->next != r)
                prev = prev->next;
            prev->next = *head;
            r->next = NULL;
            free(r);
            r = *head;
        }
        else
        {
            prev = *head;
            while (prev->next != r)
                prev = prev->next;
            prev->next = r->next;
            r->next = NULL;
            free(r);
            r = prev->next;
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
