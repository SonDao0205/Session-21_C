#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("bt01.txt", "w");
    char myText[100];
    printf("Nhap du lieu : ");
    fgets(myText,100,stdin);
    fprintf(fptr,"%s",myText);
    fclose(fptr);
    return 0;
}