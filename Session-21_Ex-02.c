#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("bt01.txt", "r");
    char firtsChar = fgetc(fptr);
    printf("%c",firtsChar);
    fclose(fptr);
    return 0;
}