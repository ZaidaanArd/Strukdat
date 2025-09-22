/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124140200 - Muhammad Zaidaan Ardiyansyah*/
/* Tanggal   : 6 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
    // Kamus
    Titik T1, T2, X;
    boolean Z, A, B, C;
    int k;

    // Algoritma
    printf("Halo, ini driver modul Titik\n");

    /* Konstruktor */
    makeTitik(&T1, -2, 3);
    makeTitik(&T2, 6, -5);
    printf("Koordinat awal T1: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    printf("Koordinat awal T2: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

    makeTitik(&X, 0, 2);
    makeTitik0(&T2);

    /* Selektor */
    printf("\nAbsis T2 = %d", getAbsis(T2));
    printf("\nOrdinat T2 = %d\n", getOrdinat(T2));

    /* Mutator */
    setAbsis(&T2, 4);
    setOrdinat(&T2, -7);
    printf("Absis T2 setelah diubah = %d\n", getAbsis(T2));
    printf("Ordinat T2 setelah diubah = %d\n", getOrdinat(T2));

    /* Predikat */
    Z = isOrigin(T2);
    A = isOnSumbuX(T2);
    B = isOnSumbuY(T2);
    C = isEqual(T1, X);
    printf("\nT2 di origin? %d", Z);
    printf("\nT2 di sumbu X? %d", A);
    printf("\nT2 di sumbu Y? %d", B);
    printf("\nT1 sama dengan X? %d\n", C);

    /* Subrutin */
    geser(&T1, 3, -1);
    printf("Koordinat T1 setelah digeser: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

    refleksiY(&T2);
    printf("Koordinat T2 setelah refleksi sumbu Y: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

    refleksiX(&T1);
    printf("Koordinat T1 setelah refleksi sumbu X: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

    dilatasi(&T2, 1.5);
    printf("Koordinat T2 setelah dilatasi: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));

    dilatasiX(&T1, X, 2.0);
    printf("Koordinat T1 setelah dilatasi terhadap X: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));

    k = kuadran(T1);
    printf("\nKuadran T1 = %d\n", k);

    return 0;
}