#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int GetValidInput(int* value) {
    while (1) {
        if (scanf_s("%d", value) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода. Пожалуйста, введите корректное число: ");
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
    int size = 0;
    int sum = 1;
    int sum1 = 0;
    int minIndex = 0;

    int choice;
    printf("Выберите способ заполнения массива (1 - ручной ввод, 2 - случайный ввод): ");
    GetValidInput(&choice);
    while (choice != 1 && choice != 2) {
        printf("Неверный выбор. Введите 1 для ручного ввода или 2 для случайного ввода: ");
        GetValidInput(&choice);
    }

    if (choice == 1) {
        printf("Введите количество элементов в массиве (максимум 100): ");
        GetValidInput(&size);
        while (size < 1 || size > 100) {
            printf("Ошибка. Введите количество от 1 до 100: ");
            GetValidInput(&size);
        }
        manualInput(array, size);
    }
    else {
        printf("Введите количество элементов для случайного заполнения (максимум 100): ");
        GetValidInput(&size);
        while (size < 1 || size > 100) {
            printf("Ошибка. Введите количество от 1 до 100: ");
            GetValidInput(&size);
        }
        randomInput(array, size);
        printf("Массив был заполнен случайными числами.\n");
    }

    printf("Вы ввели следующие элементы массива:\n");
    for (int j = 0; j < size; j++) {
        printf("%d\n", array[j]);
    }

    for (int j = 0; j < size; j++) {
        if (array[j] > 0) {
            sum *= array[j];
        }
    }
    printf("Произведение положительных элементов: %d\n", sum);

    int min = array[0];
    for (int j = 1; j < size; j++) {
        if (array[j] < min) {
            min = array[j];
            minIndex = j;
        }
    }

    for (int j = 0; j < minIndex; j++) {
        sum1 += array[j];
    }

    printf("Минимальное число = %d\n", min);
    printf("Сумма всех элементов до минимального = %d\n", sum1);

    return 0;
}
