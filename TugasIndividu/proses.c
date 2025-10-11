#include <stdio.h>
#include "proses.h"

void MakeProses(Proses *P, char id, int bt) {
    P->IDProses = id;
    P->BurstTime = bt;
}

void PrintProses(Proses P) {
    printf("Proses %c (BT=%d)\n", P.IDProses, P.BurstTime);
}
