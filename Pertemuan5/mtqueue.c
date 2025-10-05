/* Program   : tqueue.h */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124140200 - Muhammad Zaidaan Ardiyansyah*/
/* Tanggal   : 02-10-2025*/
/***********************************/

#include <stdio.h>
#include "tqueue.h"

int main() {
    
    tqueue Q, Q1, Q2;
    char e = '_';

    createQueue(&Q);
    printQueue(Q);
    printf("=== Enqueue ===\n");
    enqueue(&Q, 'A');
    printf("tail = %d\n", tail(Q));
    enqueue(&Q, 'B');
    printf("tail = %d\n", tail(Q));
    enqueue(&Q, 'C');
    printf("tail = %d\n", tail(Q));
    enqueue(&Q, 'D');
    printf("tail = %d\n", tail(Q));
    printQueue(Q);
    
    printf("=== Dequeue ===\n");
    dequeue(&Q, &e);
    printf("tail = %d\n", tail(Q));
    printf("Dequeue = %c\n", e);
    printQueue(Q);
    dequeue(&Q, &e);
    printf("tail = %d\n", tail(Q));
    printf("Dequeue = %c\n", e);
    printQueue(Q);
    dequeue(&Q, &e);
    printf("tail = %d\n", tail(Q));
    printf("Dequeue = %c\n", e);
    printQueue(Q);
    
    printf("=== Enqueue2 ===\n");  
    createQueue(&Q1);
    createQueue(&Q2);
    enqueue2(&Q1, &Q2, 'X');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'Y');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'Z');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    enqueue2(&Q1, &Q2, 'W');
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    
    printf("=== Dequeue2 ===\n");
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);
    dequeue2(&Q1, &Q2, &e);
    printf("dequeue2 -> %c\n", e);
    printf("Q1: ");
    printQueue(Q1);
    printf("Q2: ");
    printQueue(Q2);

    return 0;

};