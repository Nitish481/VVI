#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure for the circular linked list
typedef struct CircularLinkedList
{
    Node *rear;
} CircularLinkedList;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the rear of the circular linked list
void insertAtRear(CircularLinkedList *list, int data)
{
    Node *newNode = createNode(data);

    if (list->rear == NULL)
    {
        list->rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = list->rear->next;
        list->rear->next = newNode;
        list->rear = newNode;
    }
}

// Function to delete a node from the circular linked list at the specified index
void deleteAtIndex(CircularLinkedList *list, int index)
{
    if (list->rear == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = list->rear->next;
    Node *prev = list->rear;

    int i = 0;
    while (i < index && current != list->rear)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if (i != index)
    {
        printf("Index out of bounds.\n");
        return;
    }

    if (current == list->rear)
    {
        list->rear = prev;
    }

    prev->next = current->next;
    free(current);
}

// Function to print the elements of the circular linked list
void printList(CircularLinkedList *list)
{
    if (list->rear == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = list->rear->next;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->rear->next);
    printf("\n");
}

int main()
{
    int A[] = {1, 4, 2, 5, 3, 6};
    int n = sizeof(A) / sizeof(int);

    CircularLinkedList queue;
    queue.rear = NULL;

    int B[] = {9, 14, 0, 5, 2, 16};
    int i;

    // Enqueue elements into the circular linked list
    for (i = 0; i < n; i++)
    {
        insertAtRear(&queue, B[i]);
    }

    printf("Input B: ");
    printList(&queue);

    // Dequeue elements from the circular linked list in the order specified by A
    for (i = 0; i < n; i++)
    {
        int index = A[i] - 1;
        deleteAtIndex(&queue, index);

        printf("Output B: ");
        printList(&queue);
    }

    return 0;
}
