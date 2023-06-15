#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the elements of the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to sort the linked list using bubble sort
void sortLinkedList(Node *head)
{
    if (head == NULL)
        return;

    int swapped;
    Node *current;
    Node *last = NULL;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                // Swap the data of the current and next nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

int main()
{
    Node *head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtHead(&head, data);
    }

    printf("Original List: ");
    printList(head);

    sortLinkedList(head);

    printf("Sorted List: ");
    printList(head);

    // Free memory
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
