#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
    if (pq->front == NULL)
        return TRUE;
    return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue is empty!!!!!\n");
        exit(-1);
    }

    Node *rmNode = (Node *)malloc(sizeof(Node));
    rmNode = pq->front;
    Data rmData = rmNode->data;

    pq->front = rmNode->next;
    free(rmNode);
    return rmData;   

}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue is empty!!!!!\n");
        exit(-1);
    }
    return pq->front->data;
}