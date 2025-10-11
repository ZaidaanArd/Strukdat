#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *Q) {
    Q->head = Q->tail = -1;
}

int IsEmptyQueue(Queue Q) {
    return Q.head == -1;
}

int IsFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void Enqueue(Queue *Q, Proses P) {
    if (IsFullQueue(*Q)) {
        printf("Queue penuh!\n");
        return;
    }
    if (IsEmptyQueue(*Q)) {
        Q->head = Q->tail = 0;
    } else {
        Q->tail++;
    }
    Q->data[Q->tail] = P;
}

Proses Dequeue(Queue *Q) {
    Proses P = Q->data[Q->head];
    if (Q->head == Q->tail) {
        Q->head = Q->tail = -1;
    } else {
        Q->head++;
    }
    return P;
}

void PrintQueue(Queue Q) {
    if (IsEmptyQueue(Q)) {
        printf("Queue kosong.\n");
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        printf("[%c|BT=%d] ", Q.data[i].IDProses, Q.data[i].BurstTime);
    }
    printf("\n");
}
