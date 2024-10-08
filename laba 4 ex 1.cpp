#include <stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void GetValidInput(int* value) {
	while (1) {
		if (scanf_s("%d", value) != 1) {
			while (getchar() != '\n');
			printf("Ошибка ввода.\n");
		}
		else {
			break;
		}
	}
}

void RandomInput(int arr[100][100], int rows, int cols) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

void manualInput(int arr[100][100], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("Введите [%d][%d] элемент ", i + 1, j + 1);
			GetValidInput(&arr[i][j]);
		}
	}
}

void PrintMatrix(int arr[100][100], int rows, int cols) {
	printf("Ваша матрица: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int FindCountSameElements (int *row,  int size){
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (row[i] == row[j]) {
				count++;
				break;
			}
		}
			
	}
   return count;
}

void  BubbleSortRows(int matrix[][100], int cols, int rows) {
	int temp[100];

	for (int i = 0; i < rows - 1; i++) {
		
		for (int j = 0; j < rows - 1 - i; j++) {
			if (FindCountSameElements(matrix[j], cols) > FindCountSameElements(matrix[j + 1], cols)) {
				for (int k = 0; k < cols; k ++) {
					temp[k] = matrix[j][k];
					matrix[j][k] = matrix[j + 1][k];
					matrix[j + 1][k] = temp[k];
				}

			}
		}
	}
	
}

int main() {
	setlocale(LC_ALL, "rus");

	int arr[100][100];
	int rows, cols;
	printf("Введите количество строк: ");
	GetValidInput(&rows);
	printf("Введите количество столбцов: ");
	GetValidInput(&cols);

	int choose;
	printf("Выберите метод для ввода матрицы:\n1. Ввод вручную\n2. Генерация случайных чисел\nВведите 1 или 2: ");
	GetValidInput(&choose);
	if (choose == 1) {
		manualInput(arr, rows, cols);
	}
	if (choose == 2) {
		RandomInput(arr, rows, cols);
	}
	if (choose != 1 && choose != 2) {
		printf("Error.");
	}

	printf("Ваша не отсортированная матрица: \n");
	PrintMatrix(arr, rows, cols);
	printf("Ваша не отсортированная матрица: \n ");
	BubbleSortRows(arr, rows, cols);
	PrintMatrix(arr, rows, cols);

}