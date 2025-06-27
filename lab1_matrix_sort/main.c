#include <stdio.h>
#include "matrix_lib.h"

int main() {
    int a[100][100], n, m, choice;

    printf("Введіть кількість рядків і стовпців: ");
    scanf("%d %d", &n, &m);

    inputMatrix(a, n, m);

    do {
        printf("\nМеню:\n");
        printf("1. Сортувати рядки за зростанням\n");
        printf("2. Сортувати рядки за спаданням\n");
        printf("3. Сортувати стовпці за зростанням\n");
        printf("4. Сортувати стовпці за спаданням\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: sortRowsAscending(a, n, m); outputMatrix(a, n, m); break;
            case 2: sortRowsDescending(a, n, m); outputMatrix(a, n, m); break;
            case 3: sortColsAscending(a, n, m); outputMatrix(a, n, m); break;
            case 4: sortColsDescending(a, n, m); outputMatrix(a, n, m); break;
            case 0: break;
            default: printf("Невірний вибір.\n");
        }

    } while(choice != 0);

    return 0;
}
