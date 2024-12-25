#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc sinh viên
struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    int n; 
    FILE *file;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    for (int i = 0; i < n; i++) {
        printf("\nNhập thông tin cho sinh viên thứ %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Tên: ");
        getchar();
        fgets(students[i].name, 50, stdin);
        printf("Tuổi: ");
        scanf("%d", &students[i].age);
    }
    file = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %d\n", students[i].id, students[i].name, students[i].age);
    }
    fclose(file);
}
