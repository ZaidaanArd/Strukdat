#include <stdio.h>
#include "stack.h"

/* Program   : mstack.c */
/* Deskripsi : driver ADT stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 21-09-2025 */
/***********************************/


int main() {
    Tstack undo, redo;
    char cmd;

    createStack(&undo);
    createStack(&redo);

    /* menambahkan perintah 'a' dan 'b' */
    addCommand(&undo, &redo, 'a');   /* kirim char langsung */
    addCommand(&undo, &redo, 'b');
    printStack(undo);
    printStack(redo);

    // /* undo: ambil ke cmd */
    undoCommand(&undo, &redo, &cmd);
    printf("undo: %c\n", cmd); /* harusnya 'b' */

    // /* redo: ambil ke cmd */
    redoCommand(&undo, &redo, &cmd);
    printf("redo: %c\n", cmd); /* harusnya 'b' lagi */

    return 0;
}