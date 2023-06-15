//stack queue same or not
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
    int arr[MAX_SIZE];
    int front;
    int rear;
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
    queue->front = -1;
    queue->rear = -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int element)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow.\n");
        return;
    }

    if (queue->front == -1)
    {
        queue->front = 0;
    }

    queue->arr[++queue->rear] = element;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        printf("Queue underflow.\n");
        return -1;
    }

    return queue->arr[queue->front++];
}

// Function to reverse the elements of the stack and put them into the queue
void reverseStackAndEnqueue(Stack *stack, Queue *queue)
{
    Stack tempStack;
    initStack(&tempStack);

    // Reverse the elements of the stack
    while (stack->top != -1)
    {
        int element = pop(stack);
        push(&tempStack, element);
    }

    // Put the reversed elements into the queue
    while (tempStack.top != -1)
    {
        int element = pop(&tempStack);
        enqueue(queue, element);
    }
}

// Function to check if the stack and queue have the same elements
int areStackAndQueueEqual(Stack *stack, Queue *queue)
{
    int stackElement, queueElement;

    // Check if the sizes of the stack and the queue are equal
    if (stack->top != queue->rear)
    {
        return 0;
    }

    // Compare elements from stack and queue
    while (stack->top != -1)
    {
        stackElement = pop(stack);
        queueElement = dequeue(queue);

        if (stackElement != queueElement)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    Stack stack;
    Queue queue;
    int stackSize, element;

    // Initialize stack and queue
    initStack(&stack);
    initQueue(&queue);

    // Get the number of elements for the stack
    printf("Enter the number of elements for the stack: ");
    scanf("%d", &stackSize);

    printf("Enter the elements for the stack:\n");
    for (int i = 0; i < stackSize; i++)
    {
        scanf("%d", &element);
        push(&stack, element);
    }

    // Reverse the stack elements and put them into the queue
    reverseStackAndEnqueue(&stack, &queue);

    // Check if the reversed stack elements are equal to the elements in the queue
    if (areStackAndQueueEqual(&stack, &queue))
    {
        printf("The reversed elements of the stack are equal to the elements of the queue.\n");
    }
    else
    {
        printf("The reversed elements of the stack are not equal to the elements of the queue.\n");
    }

    return 0;
}
