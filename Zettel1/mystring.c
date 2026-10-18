#include "mystring.h"


// mystrlen: gibt die Länge des Strings zurück (ohne das Nullbyte)
size_t mystrlen(char *str){

    size_t counter = 0;
    // solange weiterzählen, bis das Nullbyte erreicht ist
    while (str[counter] != '\0') {
        counter++;
        }

    return counter;
}

// mystrcpy: kopiert src (inklusive Nullbyte) nach dest, gibt dest zurück
char *mystrcpy(char *dest, const char *src){

    // Länge von src bestimmen (ohne Nullbyte)
    size_t length = mystrlen(src);

    // "<=" damit auch das Nullbyte am Ende mitkopiert wird
    for (size_t i = 0; i <= length; i++){
        dest[i] = src[i];
        }

    
    return dest;

}

// mystrcat: hängt src an das Ende von dest an, gibt dest zurück
char *mystrcat(char *dest, const char *src) {

    // dest + mystrlen(dest) zeigt auf das Nullbyte von dest;
    // ab dort wird src hineinkopiert und überschreibt dieses Nullbyte
    mystrcpy(dest + mystrlen(dest), src);
    
    return dest;
}

// mystrcmp: vergleicht zwei Strings, gibt -1 (s1 < s2), 0 (gleich) oder 1 (s1 > s2) zurück
int mystrcmp(const char *s1, const char *s2){

    // Längen beider Strings bestimmen
    size_t s1_length = mystrlen(s1);
    size_t s2_length = mystrlen(s2);

    // es muss nur bis zur Länge des kürzeren Strings verglichen werden
    size_t compare_length;

    if (s1_length > s2_length) {
    compare_length = s2_length;
    }else{
    compare_length = s1_length;
    }

    // "<=" bezieht das Nullbyte des kürzeren Strings mit ein; da '\0' kleiner ist
    // als jedes andere Zeichen, ist bei gleichem Anfang der kürzere String kleiner
    for (size_t i=0; i<=compare_length; i++){
        // erstes abweichendes Zeichen entscheidet über das Ergebnis
        if (s1[i] < s2[i]){
        return -1;
                }
        if (s1[i] > s2[i]){
        return 1;
                }
    }
    // bis einschließlich Nullbyte kein Unterschied: Strings sind gleich
    return 0;
}

// mymemcpy: kopiert genau n Bytes von src nach dest, gibt dest zurück
void *mymemcpy(void *dest, const void *src, size_t n) {
    // void* hat keine Größe, daher Zeiger auf unsigned char (1 Byte) für byteweisen Zugriff
    unsigned char *dest_byte = dest;
    const unsigned char *src_byte = src;

    // genau n Bytes kopieren, unabhängig vom Inhalt
    for (size_t i = 0; i < n; i++) {
        dest_byte[i] = src_byte[i];
        }

    return dest;
}

// mymemset: füllt die ersten n Bytes von buf mit dem Wert ch, gibt buf zurück
void *mymemset(void *buf, int ch, size_t n) {
    // byteweiser Zugriff auf den Speicher
    unsigned char *buf_ptr = buf;

    // jedes der n Bytes mit ch beschreiben (Cast schneidet den int auf ein Byte zu)
    for (size_t i = 0; i < n; i++) {
        buf_ptr[i] = (unsigned char)ch;
    }
    
    return buf;
}

