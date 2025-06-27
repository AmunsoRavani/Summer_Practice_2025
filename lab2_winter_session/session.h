#include <stdio.h>

struct Student {
    char group[10];
    char name[50];
    int math_analysis;
    int algebra;
    int programming;
};

// Функції
void createFile();
void openFile();
void closeFile();
void addStudent();
void displayFile();
void findUniqueGrades();
