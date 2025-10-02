/* Program   : tqueue.h */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124140200 - Muhammad Zaidaan Ardiyansyah*/
/* Tanggal   : 2 September 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

int main()
{
    tqueue2 Q, Q1, Q2;
    char e = '-';

    createQueue2(&Q);
    printQueue2(Q);
    printf("=== Test enqueue 2 ===\n");
    enqueue2(&Q, 'A');
    printf("tail = %d\n", tail2(Q));
    enqueue2(&Q, 'B');
    printf("tail = %d\n", tail2(Q));
    enqueue2(&Q, 'C');
    printf("tail = %d\n", tail2(Q));
    printQueue2(Q);
    viewQueue2(Q);

};