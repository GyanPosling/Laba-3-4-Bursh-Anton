#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void getValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода.");
        }
        else {
            break;
        }
    }
    
}

void manualInputMatrix(int rows, int cols, int matrix[100][100]) {
    printf("Введите элементы матрицы (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            getValidInput(&matrix[i][j]);
        }
    }
}

void randomInputMatrix(int rows, int cols, int matrix[100][100]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 201 - 100; 
        }
    }
    printf("Матрица сгенерирована случайным образом.\n");
}

bool checkRowsForZero(int rows, int cols, int matrix[100][100]) {
    for (int i = 0; i < rows; i++) {
        bool hasZero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            return false;  
        }
    }
    return true;
}

void replaceNegativesWithZero(int rows, int cols, int matrix[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[100][100]) {
    printf("Матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int matrix[100][100];
    int rows, cols;

    printf("Введите число строк и столбцов: ");
    getValidInput(&rows);
    getValidInput(&cols);

    int choice;
    printf("Выберите метод заполнения матрицы:\n1. Ввод вручную\n2. Случайная генерация\n");
    getValidInput(&choice);

    if (choice == 1) {
        manualInputMatrix(rows, cols, matrix);
    }
    else if (choice == 2) {
        randomInputMatrix(rows, cols, matrix);
    }
    else {
        printf("Ошибка выбора метода заполнения.\n");
        return 1;
    }

    printMatrix(rows, cols, matrix);

    if (!checkRowsForZero(rows, cols, matrix)) {
        replaceNegativesWithZero(rows, cols, matrix);
        printf("После замены отрицательных элементов:\n");
        printMatrix(rows, cols, matrix);
    }
    else {
        printf("Каждая строка содержит хотя бы один нулевой элемент. Изменения не требуются.\n");
    }

    return 0;
}
