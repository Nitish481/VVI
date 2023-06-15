/*Create two stacks using a circular linked list and check whether they are equal or not*/
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

// Function to push an element onto the stack
void push(Node **top, int data)
{
    Node *newNode = createNode(data);
    if (*top == NULL)
    {
        *top = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = (*top)->next;
        (*top)->next = newNode;
        *top = newNode;
    }
}

// Function to pop an element from the stack
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int data;
    Node *temp = (*top)->next;

    if ((*top)->next == *top)
    {
        data = (*top)->data;
        free(*top);
        *top = NULL;
        return data;
    }

    while (temp->next != *top)
    {
        temp = temp->next;
    }

    data = temp->next->data;
    Node *delNode = temp->next;
    temp->next = (*top)->next;
    free(delNode);
    return data;
}

// Function to check if two stacks are equal
int areStacksEqual(Node *stack1, Node *stack2)
{
    Node *temp1 = stack1;
    Node *temp2 = stack2;

    if (temp1 == NULL && temp2 == NULL)
    {
        // Both stacks are empty, hence equal
        return 1;
    }

    if (temp1 == NULL || temp2 == NULL)
    {
        // One stack is empty and the other is not, hence not equal
        return 0;
    }

    do
    {
        if (temp1->data != temp2->data)
        {
            // Data mismatch, stacks are not equal
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    } while (temp1 != stack1 && temp2 != stack2);

    if (temp1 != stack1 || temp2 != stack2)
    {
        // Stacks have different lengths, hence not equal
        return 0;
    }

    // All elements are equal and in the same order, stacks are equal
    return 1;
}

int main()
{
    Node *stack1 = NULL;
    Node *stack2 = NULL;
    int size1, size2, element;

    printf("Enter the number of elements for stack 1: ");
    scanf("%d", &size1);

    printf("Enter the elements for stack 1:\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &element);
        push(&stack1, element);
    }

    printf("Enter the number of elements for stack 2: ");
    scanf("%d", &size2);

    printf("Enter the elements for stack 2:\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &element);
        push(&stack2, element);
    }

    // Check if stacks are equal
    if (areStacksEqual(stack1, stack2))
    {
        printf("Stack 1 and Stack 2 are equal.\n");
    }
    else
    {
        printf("Stack 1 and Stack 2 are not equal.\n");
    }

    return 0;
}
