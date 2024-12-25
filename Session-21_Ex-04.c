#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("bt01.txt", "r");
    char string[100];
    fgets(string,100,fptr);
    printf("%s",string);
    fclose(fptr);
    return 0;
}