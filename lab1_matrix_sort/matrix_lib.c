#include <stdio.h>

void inputMatrix(int a[][100], int n, int m) {
    printf("Введіть елементи матриці %dx%d:\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void outputMatrix(int a[][100], int n, int m) {
    printf("Матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void sortRowsAscending(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            for (int k = 0; k < m - j - 1; k++)
                if (a[i][k] > a[i][k + 1]) {
                    int temp = a[i][k];
                    a[i][k] = a[i][k + 1];
                    a[i][k + 1] = temp;
                }
}

void sortRowsDescending(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            for (int k = 0; k < m - j - 1; k++)
                if (a[i][k] < a[i][k + 1]) {
                    int temp = a[i][k];
                    a[i][k] = a[i][k + 1];
                    a[i][k + 1] = temp;
                }
}

void sortColsAscending(int a[][100], int n, int m) {
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            for (int k = 0; k < n - i - 1; k++)
                if (a[k][j] > a[k + 1][j]) {
                    int temp = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = temp;
                }
}

void sortColsDescending(int a[][100], int n, int m) {
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            for (int k = 0; k < n - i - 1; k++)
                if (a[k][j] < a[k + 1][j]) {
                    int temp = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = temp;
                }
}
