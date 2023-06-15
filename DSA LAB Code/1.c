/*Create two stacks using a circular linked list and check whether they are reversed to each other or not*/

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
    newNode->next = *top;
    *top = newNode;
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
    Node *temp = *top;
    *top = (*top)->next;
    data = temp->data;
    free(temp);
    return data;
}

// Function to check if the reverse of one stack is similar to another stack
int isReverseStackSimilar(Node *stack1, Node *stack2)
{
    Node *temp1 = stack1;
    Node *temp2 = stack2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // If either stack is not fully traversed
    if (temp1 != NULL || temp2 != NULL)
    {
        return 0;
    }

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

    // Create a temporary stack to store the reverse of stack1
    Node *reverseStack = NULL;
    Node *temp = stack1;
    while (temp != NULL)
    {
        push(&reverseStack, temp->data);
        temp = temp->next;
    }

    // Check if the reverse of stack1 is similar to stack2
    if (isReverseStackSimilar(reverseStack, stack2))
    {
        printf("The reverse of stack1 is similar to stack2.\n");
    }
    else
    {
        printf("The reverse of stack1 is not similar to stack2.\n");
    }

    return 0;
}
