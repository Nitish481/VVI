#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void bubbleSort(Node* head) {
    if (head == NULL) {
        return;
    }

    int swapped;
    Node* current;
    Node* temp = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != temp) {
            if (current->data > current->next->data) {
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
            current = current->next;
        }
        temp = current;
    } while (swapped);
}
int len(Node *head)
{
    int count=0;
    Node *t=head;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
Node * insertionSort(Node *head)
{
    if(head==NULL)
        return head;
    int l = len(head);
    while(l!=0)
    {
        Node *current = head;
    while(current!=NULL)
    {
        Node *next = current->next;
        while(next!=NULL && next->data > current->data)
        {
            next=next->next;
        }
        if(next!=NULL)
        {
            int temp=current->data;
            current->data=next->data;
            next->data=temp;
        }
        current=next;
    }
    l--;
    }
    return head;
}

void selectionSort(Node **head)
{
    if(*head==NULL)
        return;
    Node *current=*head;
    Node *iterator;
    int temp;
    while(current!=NULL)
    {
        iterator=current->next;
        while(iterator!=NULL)
        {
            if(iterator->data < current->data)
            {
                temp= iterator->data;
                iterator->data=current->data;
                current->data=temp;
            }
            iterator = iterator->next;
        }
        current = current->next;
    }
}

int main()
{
    Node * head=NULL;
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
        bubbleSort(head);
        printf("\nSorted List:\n");
        display(head);
        break;
    case 2:
        head=insertionSort(head);
        printf("\nSorted List:\n");
        display(head);
        break;
    case 3:
        selectionSort(&head);
        printf("\nSorted List:\n");
        display(head);
        break;
    default:
        printf("\nInvalid Input");
        break;
    }
    
    return 0;
}