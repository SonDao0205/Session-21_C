#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("bt01.txt", "r");
    char myText[100];
    fgets(myText,100,fptr);
    fclose(fptr);
    FILE *fptr2;
    fptr2 = fopen("bt06.txt", "w");
    fprintf(fptr2,"%s",myText);
    fclose(fptr2);
    return 0;
}