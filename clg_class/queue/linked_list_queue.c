#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *end;
};

bool is_empty(struct queue *queue);
void display(struct queue *queue);
void enqueue(struct queue *queue,int data);
int dequeue(struct queue *queue);
int peek(struct queue *queue);
void clear_queue(struct queue *queue);
void queue_init(struct queue *queue);


int main()
{
    struct queue myQueue;
    
    printf("--- INITIALIZATION ---\n");
    queue_init(&myQueue);
    printf("Queue initialized safely.\n\n");

    // EDGE CASE 1: Operating on a completely empty queue
    printf("--- EDGE CASE 1: Empty Operations ---\n");
    display(&myQueue);
    peek(&myQueue);
    dequeue(&myQueue);
    clear_queue(&myQueue);
    printf("\n");

    // NORMAL OPERATION: Fill it up
    printf("--- NORMAL OPERATION: Enqueueing Data ---\n");
    printf("Pushing ADC values: 1024, 2048, 4096\n");
    enqueue(&myQueue, 1024);
    enqueue(&myQueue, 2048);
    enqueue(&myQueue, 4096);
    
    printf("Current Queue: ");
    display(&myQueue);
    
    printf("Front of queue (Peek): %d\n\n", peek(&myQueue));

    // EDGE CASE 2: Dequeueing down to zero
    // This tests if your `end` pointer correctly resets to NULL when `front` hits NULL.
    printf("--- EDGE CASE 2: Complete Drain ---\n");
    printf("Popped: %d\n", dequeue(&myQueue));
    printf("Popped: %d\n", dequeue(&myQueue));
    printf("Popped: %d\n", dequeue(&myQueue));
    
    printf("Current Queue after drain: ");
    display(&myQueue);
    printf("\n");

    // EDGE CASE 3: Re-enqueueing after a complete drain
    // If the `end` pointer didn't reset, this will cause a Segmentation Fault.
    printf("--- EDGE CASE 3: Recovery Insertion ---\n");
    printf("Pushing new ADC value: 500\n");
    enqueue(&myQueue, 500);
    enqueue(&myQueue, 600);
    printf("Current Queue: ");
    display(&myQueue);
    printf("\n");

    // EDGE CASE 4: Total Memory Wipe
    // Testing your heap cleanup before the system shuts down.
    printf("--- EDGE CASE 4: System Shutdown Cleanup ---\n");
    clear_queue(&myQueue);
    
    // Final check to prove the pointers are null
    display(&myQueue);

    return 0;

}

bool is_empty(struct queue *queue)
{
    return (queue->front == NULL);
}

void enqueue(struct queue *queue,int data)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if((queue)->front == NULL)
    {
        (queue)->front = (queue)->end = newnode;
    }
    else
    {
        (queue)->end->next = newnode;
        (queue)->end = newnode;
    }
    return;


}

int dequeue(struct queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS EMPTY!\n");
        return -1;
    }
    struct node *temp = queue->front;
    int data = queue->front->data;
    queue->front = queue->front->next;
    if(queue->front == NULL)
    {
        queue->end = NULL;
    }
    free(temp);
    return data;

}

int peek(struct queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS EMPTY!\n");
        return -1;
    }
    return (queue->front->data);
}

void display(struct queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    struct node *temp = queue->front;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    return;

}

void clear_queue(struct queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS ALREADY EMPTY!\n");
        return;
    }
    
    while(queue->front)
    {
        struct node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->end = NULL;
    printf("QUEUE CLEARED!\n");
    return;
}

void queue_init(struct queue *queue)
{
    queue->front = NULL;
    queue->end = NULL;
    return;
}