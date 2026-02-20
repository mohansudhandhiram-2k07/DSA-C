#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

struct circular_queue
{
    int array[MAX];
    int count;
    int front;
    int end;
};

bool is_empty(struct circular_queue *queue);
bool is_full(struct circular_queue *queue);
void enqueue(struct circular_queue *queue,int data);
int dequeue(struct circular_queue *queue);
int peek(struct circular_queue *queue);
void display(struct circular_queue *queue);
void queue_init(struct circular_queue *queue);

int main()
{
    struct circular_queue q;
    queue_init(&q);

    printf("--- Testing Enqueue ---\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    printf("\n--- Testing Overflow ---\n");
    enqueue(&q, 60); // Should print QUEUE IS FULL

    printf("\n--- Testing Dequeue ---\n");
    printf("Popped: %d\n", dequeue(&q));
    printf("Popped: %d\n", dequeue(&q));
    display(&q);

    printf("\n--- Testing Wrap-Around ---\n");
    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q); // Should show 30, 40, 50, 60, 70

    return 0;

}

bool is_empty(struct circular_queue *queue)
{
    return (queue->count == 0);
}

bool is_full(struct circular_queue *queue)
{
    return (queue->count == MAX);
}

void enqueue(struct circular_queue *queue,int data)
{
    if(is_full(queue))
    {
        printf("QUEUE IS FULL \n");
        return;
    }
    queue->array[queue->end] = data;
    queue->end = (queue->end+1) % MAX;
    queue->count++;
    

}

int dequeue(struct circular_queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    int data = queue->array[queue->front];
    queue->front = (queue->front+1) % MAX;
    queue->count--;
    return data;
}

int peek(struct circular_queue *queue)
{
    if(is_empty(queue))
    {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    return (queue->array[queue->front]);

}

void display(struct circular_queue *queue)
{
    int index = queue->front;
    for(int i=0;i<queue->count;i++)
    {
        printf("%d",queue->array[index]);
        index = (index+1) % MAX;
    }
}

void queue_init(struct circular_queue *queue)
{
    queue->front = queue->end = queue->count = 0;
}