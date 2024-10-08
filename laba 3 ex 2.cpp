#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int GetValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода. Пожалуйста, введите целое число: ");
        }
        else {
            return 1;
        }
    }
}

void manualInput(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите %d-ый элемент массива: ", i + 1);
        GetValidInput(&array[i]);
    }
}

void randomInput(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int array[100];
    int size, choice;

    printf("Введите количество элементов в массиве (не менее 4): ");
    GetValidInput(&size);
    while (size < 4) {
        printf("Количество элементов должно быть не менее 4. Попробуйте снова: ");
        GetValidInput(&size);
    }

    printf("Выберите способ заполнения массива (1 - ручной ввод, 2 - случайный ввод): ");
    GetValidInput(&choice);
    while (choice != 1 && choice != 2) {
        printf("Неверный выбор. Введите 1 для ручного ввода или 2 для случайного ввода: ");
        GetValidInput(&choice);
    }

    if (choice == 1) {
        manualInput(array, size);
    }
    else {
        randomInput(array, size);
        printf("\nМассив был заполнен случайными числами.\n");
    }

    printf("\nВаш массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    BubbleSort(array, size);

    printf("\nВаш отсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    if (size >= 4) {
        printf("\n4 по минимуму элемент в массиве = %d\n", array[3]);
    }
    else {
        printf("\nМассив слишком мал для нахождения 4-го по величине элемента.\n");
    }

    return 0;
}
