#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"

/* Deskripsi : */
/* NIM/Nama : 24060124140200 - Muhammad Zaidaan Ardiyansyah */
/* Tanggal : 11 September 2025*/
/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T) {
    T->size = 0;
    for (int i = 0; i < 10 ; i++) {
        T->wadah[i] = ' '; 
    }
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T) {
	return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T) {
    return T.size == 0;
};

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T) {
    return T.size == 10;
};

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */

void searchX(Tabel T, char x, int *pos) {
    int i = 0;
    *pos = -999;
    while (i < T.size && *pos == -999) {
        if (T.wadah[i] == x) {
            *pos = i + 1; 
        }
        i++;
    }
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */

int countX(Tabel T, char x) {
    int count = 0;
    int i;
    for (i = 0; i < T.size; i++) {
        if (T.wadah[i] == x) {
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */

int countVocal(Tabel T) {
    int count = 0;
    int i;
    for (i = 0; i < T.size; i++) {
        char c = T.wadah[i];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            count++;
        }
    }
    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/

void addXTable(Tabel *T, char x) {
    if (!isFullTable(*T)) {
        T->wadah[T->size] = x;
        T->size++;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/

void addUniqueXTable(Tabel *T, char x) {
    int pos;
    searchX(*T, x, &pos);
    if (!isFullTable(*T) && pos == -999) {
        T->wadah[T->size] = x;
        T->size++;
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x) {
    int pos;
    searchX(*T, x, &pos);
    if (pos != -999) {
        delTable(T, pos);
    }
};

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx) {
    if (!isEmptyTable(*T) && idx >= 1 && idx <= T->size) {
        int i;
        for (i = idx - 1; i < T->size - 1; i++) {
            T->wadah[i] = T->wadah[i + 1];
        }
        T->size--;
        T->wadah[T->size] = ' '; 
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x) {
    int i = 0;
    int j = 0;
    while (i < T->size) {
        if (T->wadah[i] != x) {
            if (i != j) {
                T->wadah[j] = T->wadah[i];
            }
            j++;
        }
        i++;
    }
    // Mengosongkan sisa elemen di akhir
    for(i = j; i < T->size; i++) {
        T->wadah[i] = ' ';
    }
    T->size = j;
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T) {
    printf("[");
    int i;
    for (i = 0; i < 10; i++) { 
        printf("'%c'", T.wadah[i]);
        if (i < 9) {
            printf(", ");
        }
    }
    printf("]\n");
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */

void viewTable(Tabel T) {
    printf("[");
    if (!isEmptyTable(T)) {
        int i;
        for (i = 0; i < T.size; i++) {
            printf("'%c'", T.wadah[i]);
            if (i < T.size - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/

void populateTable(Tabel *T, int N) {
    if (N >= 1 && N <= 10) {
        createTable(T);
        int i;
        char input;
        for (i = 0; i < N; i++) {
            printf("Masukkan elemen ke-%d: ", i + 1);
            scanf(" %c", &input);
            addXTable(T, input);
        }
    }
};

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T) {
    if (isEmptyTable(T)) {
        return ' ';
    }

    char modusChar = T.wadah[0];
    int maxCount = 0;
    int i;

    for (i = 0; i < T.size; i++) {
        int currentCount = countX(T, T.wadah[i]);
        if (currentCount > maxCount) {
            maxCount = currentCount;
            modusChar = T.wadah[i];
        }
    }
    return modusChar;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2) {
    if (T1.size != T2.size) {
        return FALSE;
    }
    int i = 0;
    while (i < T1.size) {
        if (T1.wadah[i] != T2.wadah[i]) {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T) {
    int i;
    Tabel newTabel;

    createTable(&newTabel);
    for (i = getSize(T); i > 0; i--)
    {
        addXTable(&newTabel, T.wadah[i]);
    }

    return newTabel;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T) {
    *T = getInverseTable(*T);
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T) {
    int i, pass, sizeTabel;
    char temp;

    sizeTabel = getSize(*T);
    for (pass = 1; pass <= sizeTabel - 1; pass++)
    {
        for (i = sizeTabel; i >= pass + 1; i--)
        {
            if ((int)(*T).wadah[i] < (int)(*T).wadah[i - 1])
            {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[i - 1];
                (*T).wadah[i - 1] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T) {
    int i, pass, sizeTabel;
    char temp;

    sizeTabel = getSize(*T);
    for (pass = 1; pass <= sizeTabel - 1; pass++)
    {
        for (i = sizeTabel; i >= pass + 1; i--)
        {
            if ((int)(*T).wadah[i] > (int)(*T).wadah[i - 1])
            {
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[i - 1];
                (*T).wadah[i - 1] = temp;
            }
        }
    }
}

#endif
