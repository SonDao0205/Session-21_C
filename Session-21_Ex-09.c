#include <stdio.h>
#include <string.h>
struct Books
{
    char id[100];
    char title[100];
    char author[100];
    float price;
    char category[100];
};
void createBook(struct Books book[100], int *size);
void importFile(struct Books book[100], int size, FILE *file);
void exportFile(struct Books book[100], int *size, FILE *file);
void displayBooks(struct Books book[100], int size);

int main()
{
    int choice, size = 0;
    FILE *file;
    struct Books book[100];
    do
    {
        printf("______________________________________\n");
        printf("            Menu\n");
        printf("1, Nhap so luong va thong tin sach\n");
        printf("2, Luu thong tin sach vao file\n");
        printf("3, Lay thong tin sach tu file\n");
        printf("4, Hien thi thong tin sach\n");
        printf("5, Thoat\n");
        printf("Nhap lua chon cua ban : ");
        scanf("%d", &choice);
        printf("______________________________________\n");
        switch (choice)
        {
        case 1:
            printf("Nhap so luong sach: ");
            scanf("%d", &size);
            createBook(book, &size);
            break;
        case 2:
            importFile(book, size, file);
            break;
        case 3:
            exportFile(book, &size, file);
            break;
        case 4:
            displayBooks(book, size);
            break;
        case 5:
            printf("Tam biet!\n");
            break;
        default:
            printf("Khong hop le! Nhap lai!\n");
            break;
        }
    } while (choice != 5);
}

void createBook(struct Books book[100], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        getchar();
        fgets(book[i].id, sizeof(book[i].id), stdin);
        book[i].id[strcspn(book[i].id, "\n")] = '\0';
        printf("Ten sach: ");
        fgets(book[i].title, sizeof(book[i].title), stdin);
        book[i].title[strcspn(book[i].title, "\n")] = '\0';
        printf("Tac gia: ");
        fgets(book[i].author, sizeof(book[i].author), stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Gia sach: ");
        scanf("%f", &book[i].price);
        printf("Chu de: ");
        getchar();
        fgets(book[i].category, sizeof(book[i].category), stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}

void importFile(struct Books book[100], int size, FILE *file)
{
    file = fopen("book.bin", "wb");
    if (file == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }
    fwrite(&size, sizeof(int), 1, file);
    for (int i = 0; i < size; i++)
    {
        fwrite(&book[i], sizeof(struct Books), 1, file);
    }
    fclose(file);
    printf("Luu thong tin thanh cong!\n");
}

void exportFile(struct Books book[100], int *size, FILE *file)
{
    file = fopen("book.bin", "rb");
    if (file == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }
    fread(size, sizeof(int), 1, file);
    for (int i = 0; i < *size; i++)
    {
        fread(&book[i], sizeof(struct Books), 1, file);
    }
    fclose(file);
    printf("Lay thong tin thanh cong!\n");
}

void displayBooks(struct Books book[100], int size)
{
    if (size == 0)
    {
        printf("Chua co thong tin sach de hien thi!\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("Thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", book[i].id);
        printf("Ten sach: %s\n", book[i].title);
        printf("Tac gia: %s\n", book[i].author);
        printf("Gia sach: %.2f\n", book[i].price);
        printf("Chu de: %s\n", book[i].category);
        printf("--------------------------\n");
    }
}
