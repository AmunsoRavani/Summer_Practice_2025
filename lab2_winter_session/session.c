#include <stdio.h>
#include <string.h>
#include "session.h"

FILE *file = NULL;
char filename[100];

void createFile() {
    printf("Введіть ім’я нового файлу: ");
    scanf("%s", filename);

    file = fopen(filename, "wb");
    if (file != NULL) {
        printf("Файл '%s' створено успішно.\n", filename);
        fclose(file);
        file = NULL;
    } else {
        printf("Помилка створення файлу.\n");
    }
}

void openFile() {
    printf("Введіть ім’я існуючого файлу: ");
    scanf("%s", filename);

    file = fopen(filename, "rb+");
    if (file != NULL) {
        printf("Файл '%s' відкрито успішно.\n", filename);
    } else {
        printf("Не вдалося відкрити файл. Можливо, він не існує.\n");
    }
}

void closeFile() {
    if (file != NULL) {
        fclose(file);
        file = NULL;
        printf("Файл закрито.\n");
    } else {
        printf("Файл не відкрито.\n");
    }
}

void addStudent() {
    if (file == NULL) {
        printf("Спочатку відкрийте файл.\n");
        return;
    }

    struct Student s;
    fseek(file, 0, SEEK_END);

    printf("Номер групи: "); scanf("%s", s.group);
    printf("Прізвище та ініціали: "); scanf(" %[^\n]", s.name);
    printf("Оцінка з матаналізу: "); scanf("%d", &s.math_analysis);
    printf("Оцінка з алгебри: "); scanf("%d", &s.algebra);
    printf("Оцінка з програмування: "); scanf("%d", &s.programming);

    fwrite(&s, sizeof(struct Student), 1, file);
    printf("Студента додано успішно.\n");
}

void displayFile() {
    if (file == NULL) {
        printf("Спочатку відкрийте файл.\n");
        return;
    }

    fseek(file, 0, SEEK_SET);
    struct Student s;
    int count = 0;

    printf("\n📄 Вміст файлу:\n");
    while (fread(&s, sizeof(struct Student), 1, file)) {
        printf("Група: %s | %s | Матаналіз: %d | Алгебра: %d | Програмування: %d\n",
               s.group, s.name, s.math_analysis, s.algebra, s.programming);
        count++;
    }

    if (count == 0) {
        printf("⚠️ Файл не містить записів.\n");
    }
}

void findUniqueGrades() {
    if (file == NULL) {
        printf("Спочатку відкрийте файл.\n");
        return;
    }

    fseek(file, 0, SEEK_SET);
    struct Student s;
    int found = 0;

    printf("\n🎯 Студенти з трьома різними оцінками:\n");
    while (fread(&s, sizeof(struct Student), 1, file)) {
        if (s.math_analysis != s.algebra &&
            s.math_analysis != s.programming &&
            s.algebra != s.programming) {
            printf("Група: %s | %s | Матаналіз: %d | Алгебра: %d | Програмування: %d\n",
                   s.group, s.name, s.math_analysis, s.algebra, s.programming);
            found = 1;
        }
    }

    if (!found) {
        printf("Жодного такого студента не знайдено.\n");
    }
}
