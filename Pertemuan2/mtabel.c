#include <stdio.h>
#include "tabel.h"
/* Deskripsi : driver ADT tabel integer */
/* NIM/Nama : 24060124140200 - Muhammad Zaidaan Ardiyansyah */
/* Tanggal : 11 September 2025*/

void printHeader(char *title)
{
    printf("\n============================================\n");
    printf("  %s\n", title);
    printf("============================================\n");
}

/* Prosedur untuk menampilkan isi (menggunakan viewTable) dan ukuran tabel */
void printTableInfo(Tabel T, char *tableName)
{
    printf("Isi %s: ", tableName);
    viewTable(T);
    printf("   (Size: %d)\n", getSize(T));
}

/* Prosedur untuk mencetak hasil tes boolean dengan format Ya/Tidak */
void printTestResult(char *testName, boolean result)
{
    printf("%s: %s\n", testName, result ? "Ya" : "Tidak");
}


/************************* MAIN DRIVER *************************/
int main()
{
    /* Kamus Data */
    Tabel T1, T2, T3, T4;
    int pos;
    char modus;

    /* ================================================================== */
    printHeader("1. UJI KONSTRUKTOR & PREDIKAT DASAR");
    createTable(&T1);
    printf("Tabel T1 berhasil dibuat dengan createTable.\n");
    printTestResult("Apakah T1 kosong (isEmptyTable)?", isEmptyTable(T1));
    printTestResult("Apakah T1 penuh (isFullTable)?", isFullTable(T1));
    printTableInfo(T1, "T1");

    /* ================================================================== */
    printHeader("2. UJI PENGISIAN (addXTable & addUniqueXTable)");
    printf("Menambahkan 'S', 'T', 'R', 'U', 'K', 'T', 'U', 'R' ke T1...\n");
    addXTable(&T1, 'S');
    addXTable(&T1, 'T');
    addXTable(&T1, 'R');
    addXTable(&T1, 'U');
    addXTable(&T1, 'K');
    addXTable(&T1, 'T');
    addXTable(&T1, 'U');
    addXTable(&T1, 'R');
    printTableInfo(T1, "T1");
    printTestResult("Apakah T1 kosong sekarang?", isEmptyTable(T1));
    printTestResult("Apakah T1 penuh sekarang?", isFullTable(T1));

    printf("\nMenambahkan 'S' lagi (addUniqueXTable) - seharusnya gagal...\n");
    addUniqueXTable(&T1, 'S');
    printTableInfo(T1, "T1 (tidak berubah)");

    printf("Menambahkan 'D' (addUniqueXTable) - seharusnya berhasil...\n");
    addUniqueXTable(&T1, 'D');
    printTableInfo(T1, "T1 (setelah tambah 'D')");

    /* ================================================================== */
    printHeader("3. UJI PENCARIAN & STATISTIK");
    printTableInfo(T1, "T1 saat ini");
    searchX(T1, 'K', &pos);
    printf("Posisi 'K' (searchX): %d\n", pos);
    searchX(T1, 'Z', &pos);
    printf("Posisi 'Z' (searchX): %d\n", pos);
    printf("Jumlah 'T' (countX): %d\n", countX(T1, 'T'));
    printf("Jumlah huruf vokal (countVocal): %d\n", countVocal(T1));
    modus = Modus(T1);
    printf("Modus tabel (Modus): %c\n", modus);


    /* ================================================================== */
    printHeader("4. UJI PENGHAPUSAN (delTable, delXTable, delAllXTable)");
    printTableInfo(T1, "T1 (awal)");
    printf("Menghapus elemen di indeks ke-5 ('K')...\n");
    delTable(&T1, 5);
    printTableInfo(T1, "T1 (setelah delTable)");

    printf("Menghapus elemen 'R' pertama...\n");
    delXTable(&T1, 'R');
    printTableInfo(T1, "T1 (setelah delXTable)");

    printf("Menghapus SEMUA elemen 'U'...\n");
    delAllXTable(&T1, 'U');
    printTableInfo(T1, "T1 (setelah delAllXTable)");


    /* ================================================================== */
    printHeader("5. UJI RELASIONAL & INVERSE");
    // Setup T2 dan T3
    createTable(&T2); addXTable(&T2, 'D'); addXTable(&T2, 'A'); addXTable(&T2, 'T'); addXTable(&T2, 'A');
    createTable(&T3); addXTable(&T3, 'D'); addXTable(&T3, 'A'); addXTable(&T3, 'T'); addXTable(&T3, 'A');
    createTable(&T4); addXTable(&T4, 'A'); addXTable(&T4, 'D'); addXTable(&T4, 'A'); addXTable(&T4, 'T');
    printTableInfo(T2, "T2");
    printTableInfo(T3, "T3");
    printTableInfo(T4, "T4");
    printTestResult("Apakah T2 sama dengan T3 (isEqualTable)?", isEqualTable(T2, T3));
    printTestResult("Apakah T2 sama dengan T4 (isEqualTable)?", isEqualTable(T2, T4));

    printf("\nMembalik T2 dengan inverseTable...\n");
    inverseTable(&T2);
    printTableInfo(T2, "T2 (setelah dibalik)");

    printf("Membuat T4 dari T3 yang dibalik (getInverseTable)...\n");
    T4 = getInverseTable(T3);
    printTableInfo(T3, "T3 (asli)");
    printTableInfo(T4, "T4 (hasil inverse T3)");


    /* ================================================================== */
    printHeader("6. UJI PENGURUTAN (sortAsc & sortDesc)");
    printTableInfo(T1, "T1 (awal, sebelum diurutkan)");
    printf("Mengurutkan T1 secara ascending...\n");
    sortAsc(&T1);
    printTableInfo(T1, "T1 (setelah sortAsc)");
    printf("Mengurutkan T1 secara descending...\n");
    sortDesc(&T1);
    printTableInfo(T1, "T1 (setelah sortDesc)");


    /* ================================================================== */
    printHeader("7. UJI BACA/TULIS LAINNYA (printTable & populateTable)");
    printTableInfo(T2, "T2 saat ini");
    printf("Mencetak seluruh wadah T2 (termasuk spasi) dengan printTable:\n");
    printTable(T2);

    printf("\nMengisi T3 dengan 3 elemen dari input keyboard (populateTable)...\n");
    populateTable(&T3, 3);
    printTableInfo(T3, "T3 (setelah diisi user)");


    /* ================================================================== */
    printf("\n--- PENGUJIAN SELESAI ---\n");
    return 0;
}