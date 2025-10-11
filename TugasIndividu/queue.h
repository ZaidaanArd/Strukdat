#ifndef QUEUE_H
#define QUEUE_H
#include "proses.h"

#define MAX 10

typedef struct {
    Proses data[MAX];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue *Q);
int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
void Enqueue(Queue *Q, Proses P);
Proses Dequeue(Queue *Q);
void PrintQueue(Queue Q);

#endif
