/*Implement one stack and one queue to check if they are equal or not*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure for a stack
typedef struct Stack
{
    Node *top;
} Stack;

// Structure for a queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a stack
void initStack(Stack *stack)
{
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    data = temp->data;
    free(temp);
    return data;
}

// Function to initialize a queue
void initQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data)
{
    Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int data;
    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    data = temp->data;
    free(temp);
    return data;
}

// Function to check if the elements of a stack are equal to the elements of a queue
int areStackAndQueueEqual(Stack *stack, Queue *queue)
{
    Node *stackNode = stack->top;
    Node *queueNode = queue->front;

    while (stackNode != NULL && queueNode != NULL)
    {
        if (stackNode->data != queueNode->data)
        {
            // Data mismatch, stack and queue are not equal
            return 0;
        }
        stackNode = stackNode->next;
        queueNode = queueNode->next;
    }

    if (stackNode != NULL || queueNode != NULL)
    {
        // Stack and queue have different lengths, hence not equal
        return 0;
    }

    // All elements are equal and in the same order, stack and queue are equal
    return 1;
}

int main()
{
    Stack stack;
    Queue queue;
    int size, element;

    initStack(&stack);
    initQueue(&queue);

    printf("Enter the number of elements for stack and queue: ");
    scanf("%d", &size);

    printf("Enter the elements for stack:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element);
        push(&stack, element);
    }

    printf("Enter the elements for queue:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element);
        enqueue(&queue, element);
    }

    // Check if the elements of stack are equal to the elements of queue
    if (areStackAndQueueEqual(&stack, &queue))
    {
        printf("Stack and Queue are equal.\n");
    }
    else
    {
        printf("Stack and Queue are not equal.\n");
    }

    return 0;
}
