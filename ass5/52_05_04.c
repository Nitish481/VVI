#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node *createNode(int data)
{
    node * n = (node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    return n;
}
void insert(node** head, int data) {
    node* n = createNode(data);
    if (*head == NULL) {
        *head = n;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
    }
}

void display(node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
node* swap(node *l,node* r)
{
    node *tmp = r->next;
    r->next=l;
    l->next=tmp;
    return r;
}
int len(node *head)
{
    int count=0;
    node *t=head;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
void bubbleSort(node **head)
{
    if(*head==NULL)
        return;
    int swapped,count=len(*head);
    node * p1,*p2;
    /* do
    {
        swapped=0;
        current=*head;
        while (current->next !=prev)
        {
            if(current->data>current->next->data)
            {
                swap(current,current->next);
            }
            prev=current;
            current=current->next;
        }
        
    } while (swap);
     */
    for(int i=0;i<count;i++)
    {
        node **h =head;
        swapped=0;
        for(int j=0;j<count-i-1;j++)
        {
            p1=*h;
            p2= p1->next;
            if(p1->data>p2->data)
            {
                *h= swap(p1,p2);
                swapped=1;
            }
            h = &(*h)->next;
        }
        if(swapped==0)
            break;
    }
}

void sortedInsert(node* newnode,node ** sorted)
{
    if (*sorted == NULL || (*sorted)->data >= newnode->data) 
    {
        newnode->next = *sorted;
        *sorted = newnode;
    }
    else 
    {
        struct node* current = *sorted;
        
        while (current->next != NULL && current->next->data < newnode->data) 
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }    
}
void insertionSort(node **head)
{
    node *current=*head;
    node *sorted=NULL;
    while (current != NULL)
    {
        node *next = current->next;
        sortedInsert(current,&sorted);
        current=next;
    }
    *head=sorted;
}

void selectionSort(node **head)
{
    if(*head==NULL)
        return;
    node *min=NULL;
    node *current=(*head)->next;
    node *prev=NULL;
    
}

int main()
{
    node * head=NULL;
    int data,ch;
    while(1)
    {
        printf("\nEnter data: ");
        scanf("%d",&data);
        insert(&head,data);
        printf("\n0->Stop\t1->Add More:\n");
        scanf("%d",&ch);
        if(!ch)
            break;
    }
    printf("\nOriginal List:\n");
    display(head);
    printf("\n1->BubbleSort\n2->Insertion Sort\n3->Selection Sort");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        bubbleSort(&head);
        printf("\nSorted List:\n");
        display(head);
        break;
    case 2:
        insertionSort(&head);
        printf("\nSorted List:\n");
        display(head);
        break;
    case 3:
        //selectionSort(&head);
        printf("\nSorted List:\n");
        display(head);
        break;
    default:
        printf("\nInvalid Input");
        break;
    }    
    return 0;
}