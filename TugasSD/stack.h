#ifndef stack_H
#define stack_H

/* Program   : stack.h */
/* Deskripsi : file HEADER modul stack character */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 18-09-2025 */
/***********************************/

#include "boolean.h" //salin dari praktikum lalu
/* type Tstack = < wadah: array[1…10] of character,
                    top: integer > */
/* asumsi: indeks 0 tidak digunakan */
typedef struct
{
    // wadah menyimpan karakter pada indeks 1..MAX_STACK (indeks 0 tidak digunakan)
    char wadah[11]; 
    int top;
} Tstack;

/* KONSTRUKTOR */
/* procedure createStack(output S: Tstack)
    {I.S.: - }
    {F.S.: Stack S terdefinisi}
    {Proses mengisi elemen wadah kosong dengan '_', top 0} */
void createStack(Tstack *S);

/* SELEKTOR */
/* function infoTop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
int infoTop(Tstack S);

/* function top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int top(Tstack S);

/* PREDIKAT */
/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyStack(Tstack S);

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullStack(Tstack S);

/* MUTATOR */
/* procedure push(input/output S:Tstack, input e:character)
    {I.S.: S, e terdefinisi, S mungkin kosong}
    {F.S.: S tetap, atau infoTop(S) = e}
    {Proses: mengisi elemen e ke puncak S, bila belum penuh} */
void push(Tstack *S, char e);

/* procedure pop(input/output S:Tstack, output e:character)
    {I.S.: S terdefinisi, mungkin kosong}
    {F.S.: S tetap, atau e berisi infoTop(S) lama}
    {Proses: menghapus elemen e dari puncak S, bila belum kosong} */
void pop(Tstack *S, char *e);

/* procedure printStack(input S:Tstack)
    {I.S.: S terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen S ke layar} */
void printStack(Tstack S);

/* procedure viewStack (input S:Tstack)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen S yang terisi ke layar} */
void viewStack(Tstack S);

/* OPERASI LAINNYA */
// masukkan deskripsi dan spesifikasi fungsi pada soal di sini

/* procedure addCommand(input/output Undo:Tstack, input/output Redo:Tstack, input Cmd:character)
    {I.S.: Undo dan Redo terdefinisi; Cmd adalah perintah baru}
    {F.S.: Cmd ditambahkan ke puncak Undo; Redo menjadi kosong}
    {Proses: menaruh Cmd pada stack Undo (push) dan mengosongkan stack Redo} */
void addCommand(Tstack *Undo, Tstack *Redo, char Cmd);

/* procedure undoCommand(input/output Undo:Tstack, input/output Redo:Tstack, output Cmd:character)
    {I.S.: Undo dan Redo terdefinisi; Undo mungkin kosong}
    {F.S.: Jika Undo tidak kosong, Cmd berisi elemen puncak Undo lama dan elemen tersebut dipindahkan ke puncak Redo.
           Jika Undo kosong, Cmd diisi dengan nilai '\0' (atau indikator kosong) dan tidak ada perubahan pada Redo.}
    {Proses: menghapus (pop) perintah terakhir dari Undo -> simpan di Cmd -> push ke Redo} */
void undoCommand(Tstack *Undo, Tstack *Redo, char *Cmd);

/* procedure redoCommand(input/output Undo:Tstack, input/output Redo:Tstack, output Cmd:character)
    {I.S.: Undo dan Redo terdefinisi; Redo mungkin kosong}
    {F.S.: Jika Redo tidak kosong, Cmd berisi elemen puncak Redo lama dan elemen tersebut dipindahkan ke puncak Undo.
           Jika Redo kosong, Cmd diisi dengan nilai '\0' dan tidak ada perubahan pada Undo.}
    {Proses: menghapus (pop) perintah terakhir dari Redo -> simpan di Cmd -> push ke Undo} */
void redoCommand(Tstack *Undo, Tstack *Redo, char *Cmd);

#endif