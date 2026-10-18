#include "mystring.h"

int main(void) {

    /* ---------- mystrlen ---------- */
    
    char text[] = "Hello World";
    printf("mystrlen(\"%s\") = %zu\n", text, mystrlen(text));            // 11

    /* ---------- mystrcpy ---------- */
    // Zielbuffer muss beschreibbar und groß genug sein
    char kopie[50];
    mystrcpy(kopie, text);
    printf("mystrcpy: kopie = \"%s\"\n", kopie);                         // Hello World

    /* ---------- mystrcat ---------- */
    // Array mit genug Platz für beide Strings plus Nullbyte
    char satz[50] = "Hello";
    char *ergebnis = mystrcat(satz, " World");
    printf("mystrcat: satz = \"%s\"\n", satz);                           // Hello World

    /* ---------- mystrcmp ---------- */
    printf("mystrcmp(\"abc\", \"abd\")  = %d\n", mystrcmp("abc", "abd"));    // -1
    printf("mystrcmp(\"abc\", \"abc\")  = %d\n", mystrcmp("abc", "abc"));    //  0
    printf("mystrcmp(\"abd\", \"abc\")  = %d\n", mystrcmp("abd", "abc"));    //  1

    // gleicher Anfang: der kürzere String ist kleiner (wegen des Nullbytes)
    printf("mystrcmp(\"abc\", \"abcd\") = %d\n", mystrcmp("abc", "abcd"));   // -1

    /* ---------- mymemcpy ---------- */
    
    int quelle[3] = {1, 2, 3};
    int ziel[3];
    mymemcpy(ziel, quelle, sizeof quelle);
    printf("mymemcpy: ziel = %d %d %d\n", ziel[0], ziel[1], ziel[2]);    // 1 2 3

    /* ---------- mymemset ---------- */
    char buffer[6];
    mymemset(buffer, 120, 5);   // die ersten 5 Bytes mit x (ASCII) füllen
    buffer[5] = '\0';           // Nullbyte selbst setzen, damit es ein gültiger String ist
    printf("mymemset: buffer = \"%s\"\n", buffer);                       // xxxxx

    return 0;
}