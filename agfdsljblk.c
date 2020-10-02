//计数排序
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void countSort(int* arr, int size) {
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < size;i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int range = max - min + 1;//需要申请的内存进空间的范围
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);
	
	for (int i=0; i < size;i++) {
		countArr[arr[i]-min]++;
	}
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (countArr[i]--) {
			arr[idx++] = i + min;
		}
	}
	free(countArr);
	
}

void PrintArr(int* arr, int size) {
	for (int i = 0; i < size;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main () {
	int arr[] = { 5, 1, 2, 4, 3, 6, 9, 7, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, size);
	PrintArr(arr, size);
    system("color A");
    system ("pause");
    return 0;
}