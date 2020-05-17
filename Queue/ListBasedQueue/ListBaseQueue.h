#ifndef __L_BASE_QUEUE_H__
#define __L_BASE_QUEUE_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct __node
{
    Data data;
    struct __node *next;
} Node;

typedef struct __lqueue
{
    Node *front;
    Node *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif