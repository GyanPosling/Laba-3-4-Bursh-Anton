#include<stdio.h>
#include<locale.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

void getValuidInput(int* value) {
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

void scanfMatrix(int arr[100][100], int  rows, int cals) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cals; j++) {
			printf(" Введите[%d][%d] элемент: ", i + 1, j + 1);
			getValuidInput(&arr[i][j]);
		}
	}
}

void RandomInputMatrix(int arr[100][100], int rows, int cals) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cals; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

void printMatrix(int arr[100][100], int rows, int cals) {
	printf("Ваша матрица: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cals; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int SumElements(int arr[100][100], int rows, int cals) {
	int sum = 0;
	for (int i = rows / 2; i <= rows - 1; i++) {
		for (int j = cals / 2; j <= cals - 1; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}


int main() {

    setlocale(LC_ALL, "rus");
	int arr[100][100];
	int rows, cals;
	printf("Введите количество строк: ");
	getValuidInput(&rows);
	printf("Введите количество столбцов: ");
	getValuidInput(&cals);

	int choose;
	printf("Выберите метод для ввода матрицы:\n1. Ввод вручную\n2. Генерация случайных чисел\nВведите 1 или 2: ");
	getValuidInput(&choose);
	if (choose == 1) {
		scanfMatrix(arr, rows, cals);
	}
	 if (choose == 2) {
		RandomInputMatrix(arr, rows, cals);
	}
	if (choose != 1 && choose != 2){
		printf("Error.");
	}


	printMatrix(arr, rows, cals);

	int sum = SumElements(arr, rows, cals);

	printf("Сумма  элементов в четвертой области = %d ", sum);
	
	return 0;
}