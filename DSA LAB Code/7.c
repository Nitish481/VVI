//Implement queue using two stacks
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for stack
typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

// Structure for queue
typedef struct
{
    Stack stack1; // For enqueue operation
    Stack stack2; // For dequeue operation
} Queue;

// Function to initialize stack
void initStack(Stack *stack)
{
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int element)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        return;
    }

    stack->arr[++stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow.\n");
        return -1;
    }

    return stack->arr[stack->top--];
}

// Function to initialize queue
void initQueue(Queue *queue)
{
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int element)
{
    // Push the element onto stack1
    push(&queue->stack1, element);
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    // If both stacks are empty, the queue is empty
    if (queue->stack1.top == -1 && queue->stack2.top == -1)
    {
        printf("Queue underflow.\n");
        return -1;
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (queue->stack2.top == -1)
    {
        while (queue->stack1.top != -1)
        {
            int element = pop(&queue->stack1);
            push(&queue->stack2, element);
        }
    }

    // Pop the element from stack2
    return pop(&queue->stack2);
}

int main()
{
    Queue queue;
    int queueSize, element;

    // Initialize the queue
    initQueue(&queue);

    // Get the number of elements for the queue
    printf("Enter the number of elements for the queue: ");
    scanf("%d", &queueSize);

    printf("Enter the elements for the queue:\n");
    for (int i = 0; i < queueSize; i++)
    {
        scanf("%d", &element);
        enqueue(&queue, element);
    }

    // Dequeue and print the elements from the queue
    printf("Dequeued elements: ");
    while (1)
    {
        int dequeuedElement = dequeue(&queue);
        if (dequeuedElement == -1)
        {
            break;
        }
        printf("%d ", dequeuedElement);
    }
    printf("\n");

    return 0;
}
