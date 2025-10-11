#ifndef PROSES_H
#define PROSES_H

typedef struct {
    char IDProses;
    int BurstTime;
} Proses;

void MakeProses(Proses *P, char id, int bt);
void PrintProses(Proses P);

#endif
