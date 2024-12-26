#include <stdio.h>
#include <stdlib.h>
struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    struct Student students[100];
    int count;
    FILE *file;
    file = fopen("students.txt", "r");
    fscanf(file, "%d", &count);
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d %s %d", &students[i].id, students[i].name, &students[i].age);
    }
    fclose(file);
    printf("Danh sach sinh vien tu file:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }
    return 0;
}
