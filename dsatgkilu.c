#include <stdio.h>
#include <stdlib.h>


void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int* array, int left, int right) {

	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void selectSort(int* array, int size) {
	for (int i = 0; i < size; i++) {
		int start = i;
		int min = start;
		for (int j = start + 1; j < size; j++) {
			if (array[min]> array[j])
				min = j;
		}
		Swap(array, start, min);
	}
}

int main() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	selectSort(array, size);
	printArray(array, size);
	system("color A");
	system("pause");
	return 0;
}
