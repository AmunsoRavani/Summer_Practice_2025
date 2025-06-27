#include <stdio.h>
#include "session.h"

int main() {
    int choice;

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Створити файл\n");
        printf("2. Відкрити файл\n");
        printf("3. Закрити файл\n");
        printf("4. Додати студента\n");
        printf("5. Переглянути відомість\n");
        printf("6. Знайти студентів з 3 різними оцінками\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: openFile(); break;
            case 3: closeFile(); break;
            case 4: addStudent(); break;
            case 5: displayFile(); break;
            case 6: findUniqueGrades(); break;
            case 0: 
                closeFile();
                printf("Завершення програми.\n"); 
                break;
            default: printf("Невірний вибір.\n");
        }
    } while (choice != 0);

    return 0;
}
