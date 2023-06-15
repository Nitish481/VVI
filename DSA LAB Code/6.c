/*Loop detection and removal in linked list.*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
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

// Function to detect and remove a loop in a linked list
void detectAndRemoveLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        // No loop present
        return;
    }

    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *prevPtr = NULL;

    // Move slowPtr by one node and fastPtr by two nodes until they meet
    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
        {
            // Loop detected
            break;
        }
    }

    if (slowPtr != fastPtr)
    {
        // No loop present
        return;
    }

    // Move slowPtr to the head of the list
    slowPtr = head;

    // Move slowPtr and fastPtr by one node until they meet
    while (slowPtr->next != fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    // Set the next pointer of the last node in the loop to NULL, effectively removing the loop
    fastPtr->next = NULL;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    // Create a linked list with a loop
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    //head->next->next->next->next->next = head->next; // Create a loop by connecting the last node to the second node

    printf("Linked list before loop removal: ");
    printLinkedList(head);

    // Detect and remove the loop in the linked list
    detectAndRemoveLoop(head);

    printf("Linked list after loop removal: ");
    printLinkedList(head);

    return 0;
}
