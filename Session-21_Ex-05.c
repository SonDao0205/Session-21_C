#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("bt05.txt", "w");
    int lines;
    printf("So dong ban muon nhap: ");
    scanf("%d", &lines);
    getchar();

    for (int i = 0; i < lines; i++) {
        char myText[100];
        printf("Nhap du lieu: ");
        fgets(myText, sizeof(myText), stdin);
        fprintf(fptr, "%s", myText);
    }
    fclose(fptr);
    fptr = fopen("bt05.txt", "r");
    char string[100];
    printf("Du lieu trong file : \n");
    for (int i = 0; i < lines; i++)
    {
        fgets(string,100,fptr);
        printf("%s",string);
    }
    
    fclose(fptr);
    return 0;
}
