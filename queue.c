#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6
typedef int ElemType;

typedef struct
{
    ElemType* data;
    int       rear;
    int       front;
} Queue;

// 1 initialise queue
Queue* initQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data  = (ElemType*)malloc(sizeof(Queue) * MAXSIZE);
    queue->rear  = 0;
    queue->front = 0;
    return queue;
}

// 2 is Empty
bool isEmpty(Queue* q)
{
    if (q->rear == q->front) {
        printf("queue is empty\n");
        return false;
    }
    return true;
}

// 3 dequeue
bool dequeue(Queue* q, ElemType* element)
{
    if (q->rear == q->front) {
        printf("queue is empty\n");
        return false;
    }
    *element = q->data[q->front];
    q->front++;

    return true;
}

// 4 queue full
bool queueFull(Queue* q)
{
    if (q->front != 0) {
        int step = q->front;
        for (int i = q->front; i < q->rear; i++) {
            q->data[i - step] = q->data[step];
        }
        q->front -= step;
        q->rear -= step;
        return false;
    }
    printf("The queue is really full\n");
    return true;
}

// 5 enqueue
bool enqueue(Queue* q, ElemType element)
{
    if (q->rear == MAXSIZE) {
        if (queueFull(q)) return false;
    }
    q->data[q->rear] = element;
    q->rear++;
    return true;
}

// 6 get head of queue
ElemType getHead(Queue* q)
{
    if (q->rear == q->front) {
        printf("queue is empty\n");
    }
    return q->data[q->front];
}

int main()
{
    Queue* queue = initQueue();
    isEmpty(queue);

    enqueue(queue, 1);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 2);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 3);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 4);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 5);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 6);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 7);

    ElemType element;
    dequeue(queue, &element);
    printf("element: %d\n", element);
    dequeue(queue, &element);
    printf("element: %d\n", element);
    dequeue(queue, &element);
    printf("element: %d\n", element);

    printf("front: %d\t rear: %d\n", queue->front, queue->rear);
    enqueue(queue, 7);
    printf("front: %d\t rear: %d\n", queue->front, queue->rear);

	printf("the head of queue is %d\n", getHead(queue));


    return 0;
}
