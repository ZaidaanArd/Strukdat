#include <stdio.h>
#include "queue.h"
/* Program   : tqueue3.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124140200 - Muhammad Zaidaan Ardiyansyah*/
/* Tanggal   : 11 Oktober 2025 */

void computeBTfromNIM(const char *nim, int bt[5]) {
    int len = 0; while (nim[len] != '\0') len++;
    int orig[5];
    for (int i = 0; i < 5; i++) orig[i] = nim[len - 5 + i] - '0';  

    for (int i = 0; i < 5; i++) {
        if (orig[i] == 0) {
            int prev = (i == 0) ? 0 : orig[i-1];  
            bt[i] = prev + 3;
        } else {
            bt[i] = orig[i];
        }
    }
}


int main(void) {
    const char *NIM = "24060124140200"; 
    int BT[5];
    computeBTfromNIM(NIM, BT); 

    Queue Q;
    CreateQueue(&Q);

    Proses P1, P2, P3, P4, P5;
    MakeProses(&P1, 'A', BT[0]);
    MakeProses(&P2, 'B', BT[1]);
    MakeProses(&P3, 'C', BT[2]);
    MakeProses(&P4, 'D', BT[3]);
    MakeProses(&P5, 'E', BT[4]);

    Enqueue(&Q, P1);
    Enqueue(&Q, P2);
    Enqueue(&Q, P3);
    Enqueue(&Q, P4);
    Enqueue(&Q, P5);

    printf("NIM : %s\n", NIM);
    printf("Antrian proses awal:\n");
    PrintQueue(Q);

    printf("\nUrutan eksekusi (SJF):\n");
    for (int i = Q.head; i < Q.tail; i++) {
        for (int j = i + 1; j <= Q.tail; j++) {
            if (Q.data[i].BurstTime > Q.data[j].BurstTime) {
                Proses tmp = Q.data[i];
                Q.data[i] = Q.data[j];
                Q.data[j] = tmp;
            }
        }
    }

    int waktu = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        printf("Mulai Proses %c pada t=%d, selesai t=%d\n",
               Q.data[i].IDProses, waktu, waktu + Q.data[i].BurstTime);
        waktu += Q.data[i].BurstTime;
    }
    return 0;
}