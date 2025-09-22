/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124140200 - Muhammad Zaidaan Ardiyansyah*/
/* Tanggal   : 18 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriks.h"

void printHeaderUtama(char *title)
{
	printf("\n\n##################################################\n");
	printf("### %s\n", title);
	printf("##################################################\n");
}

void printSubHeader(char *operation)
{
	printf("\n--> Operasi: %s\n", operation);
}

int main()
{
	srand(time(NULL));

	/* KAMUS */
	Matriks M1, M2, M3, MHasil;
	int r, c;

	//----------------------------------------------------------------
	// 1. UJI KONSTRUKTOR, PENGISIAN, & PREDIKAT
	//----------------------------------------------------------------
	printHeaderUtama("1. UJI KONSTRUKTOR & PENGISIAN");
	
	printSubHeader("Inisialisasi Matriks M1");
	initMatriks(&M1);
	printf("    M1 dibuat. Apakah kosong? %s\n", isEmptyMatriks(M1) ? "Ya" : "Tidak");
	
	printSubHeader("Pengisian M1 3x3 secara acak");
	isiMatriksRandom(&M1, 3, 3);
	printMatriks(M1);

	printSubHeader("Pengisian M2 3x3 dengan matriks identitas");
	initMatriks(&M2);
	isiMatriksIdentitas(&M2, 3);
	printMatriks(M2);

	//----------------------------------------------------------------
	// 2. UJI OPERASI ARITMATIKA
	//----------------------------------------------------------------
	printHeaderUtama("2. UJI OPERASI ARITMATIKA");

	printSubHeader("Penjumlahan (M1 + M2)");
	MHasil = addMatriks(M1, M2);
	printMatriks(MHasil);

	printSubHeader("Pengurangan (M1 - M2)");
	MHasil = subMatriks(M1, M2);
	printMatriks(MHasil);

	printSubHeader("Perkalian Matriks (M1 * M3)");
	initMatriks(&M3);
	isiMatriksRandom(&M3, 3, 2); // Buat matriks 3x2
	printf("Matriks Pertama:\n");
	printMatriks(M1);
	printf("Matriks Kedua:\n");
	printMatriks(M3);
	MHasil = kaliMatriks(M1, M3);
	printf("Hasil Perkalian:\n");
	printMatriks(MHasil);

	printSubHeader("Perkalian Skalar (M1 * 5)");
	MHasil = kaliSkalarMatriks(M1, 5);
	printMatriks(MHasil);

	//----------------------------------------------------------------
	// 3. UJI OPERASI LAINNYA
	//----------------------------------------------------------------
	printHeaderUtama("3. UJI OPERASI LAINNYA");
	
	printSubHeader("Transpose Matriks M3");
	printf("Matriks sebelum transpose:\n");
	printMatriks(M3);
	MHasil = getTransposeMatriks(M3);
	printf("Matriks setelah transpose:\n");
	printMatriks(MHasil);

	printSubHeader("Padding Matriks M3");
	MHasil = addPadding(M3, 2);
	printMatriks(MHasil);

	//----------------------------------------------------------------
	// 4. UJI PENCARIAN & HAPUS
	//----------------------------------------------------------------
	printHeaderUtama("4. UJI PENCARIAN & HAPUS");
	initMatriks(&M1);
	addX(&M1, 5, 1, 1);
	addX(&M1, 9, 1, 2);
	addX(&M1, 3, 2, 1);
	addX(&M1, 7, 2, 2);
	printMatriks(M1);

	printSubHeader("Mencari angka 7");
	searchX(M1, 7, &r, &c);
	printf("    Hasil: baris=%d, kolom=%d\n", r, c);
	printf("    Jumlah angka 9 (countX): %d\n", countX(M1, 9));

	printSubHeader("Menghapus angka 7");
	delX(&M1, 7);
	printMatriks(M1);

	//----------------------------------------------------------------
	// 5. UJI POOLING & KONVOLUSI
	//----------------------------------------------------------------
	printHeaderUtama("5. UJI POOLING & KONVOLUSI");
	initMatriks(&M1);
	isiMatriksRandom(&M1, 4, 4); // Matriks 4x4 untuk pooling
	printf("Matriks Awal:\n");
	printMatriks(M1);

	printSubHeader("Max Pooling (size 2)");
	MHasil = maxPooling(M1, 2);
	printMatriks(MHasil);
	
	printSubHeader("Average Pooling (size 2)");
	MHasil = avgPooling(M1, 2);
	printMatriks(MHasil);

	printSubHeader("Konvolusi M1 dengan Kernel");
	Matriks kernel;
	initMatriks(&kernel);
	isiMatriksIdentitas(&kernel, 2);
	printf("Kernel:\n");
	printMatriks(kernel);
	MHasil = conv(M1, kernel);
	printf("Hasil Konvolusi:\n");
	printMatriks(MHasil);

	return 0;
}