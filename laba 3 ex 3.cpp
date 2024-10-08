#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>


int GetValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1 || *value <= 0) {
            while (getchar() != '\n'); 
            printf("Ошибка ввода. Пожалуйста, введите положительное целое число: ");
        }
        else {
            return 1; 
        }
    }
}

void BubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Random(int array[], int* size) {
    printf("Введите количество элементов в массиве: ");
    GetValidInput(size); 
    int min, max;
    printf("Введите минимальное значение: ");
    GetValidInput(&min); 
    printf("Введите максимальное значение: ");
    GetValidInput(&max); 

    srand(time(NULL));
    for (int i = 0; i < *size; i++) {
        array[i] = rand() % (max - min + 1) + min; 
    }
}

void ScanfArray(int array[], int* n) {
    printf("Введите количество элементов в массиве: ");
    GetValidInput(n); 
    for (int i = 0; i < *n; i++) {
        printf("Введите %d-ый элемент массива: ", i + 1);
        while (1) {
            if (scanf_s("%d", &array[i]) != 1 || array[i] > INT_MAX || array[i] < INT_MIN) {
                while (getchar() != '\n'); 
                printf("Ошибка ввода. Введите %d-ый элемент массива еще раз (допустимый диапазон %d до %d): ", i + 1, INT_MIN, INT_MAX);
            }
            else {
                break; 
            }
        }
    }
}

void PrintArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

int IsInArray(int element, int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == element) {
            return 1;
        }
    }
    return 0; 
}

int IsMaxElementInSecondArray(int array1[], int n, int array2[], int k) {
    int max = INT_MIN;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (!IsInArray(array1[i], array2, k)) {
            if (array1[i] > max) {
                max = array1[i];
                found = 1; 
            }
        }
    }
    return found ? max : INT_MIN; 
}

int main() {
    setlocale(LC_ALL, "rus");
    int arrayN[100];
    int arrayK[100];
    int n, k;

    
    printf("Выберите метод для n-ого массива:\n1. Ввод вручную\n2. Генерация случайных чисел\nВведите 1 или 2: ");
    int choiceN;
    GetValidInput(&choiceN); 

    if (choiceN == 1) {
        ScanfArray(arrayN, &n);
    }
    else if (choiceN == 2) {
        Random(arrayN, &n);
    }
    else {
        printf("Неверный выбор. Завершение программы.\n");
        return 1;
    }

    BubbleSort(arrayN, n);
    printf("Ваш отсортированный n-ый массив: ");
    PrintArray(arrayN, n);

    
    printf("\nВыберите метод для k-ого массива:\n1. Ввод вручную\n2. Генерация случайных чисел\nВведите 1 или 2: ");
    int choiceK;
    GetValidInput(&choiceK); 

    if (choiceK == 1) {
        ScanfArray(arrayK, &k);
    }
    else if (choiceK == 2) {
        Random(arrayK, &k);
    }
    else {
        printf("Неверный выбор. Завершение программы.\n");
        return 1;
    }

    BubbleSort(arrayK, k);
    printf("Ваш отсортированный k-ый массив: ");
    PrintArray(arrayK, k);

    int result = IsMaxElementInSecondArray(arrayN, n, arrayK, k);
    if (result == INT_MIN) {
        printf("\nНе нашлось такого элемента.");
    }
    else {
        printf("\nОтвет = %d", result);
    }

    return 0;
}
