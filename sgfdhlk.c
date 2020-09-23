//插入排序
//基本思想: 在已经排好序的数据中给待排序的数据找一个合适的位置
// 排序之前假设第一个数据是已经排好顺序的
#include <stdio.h>
#include <stdlib.h>

void insertSort(int* array, int size) { //假设第一个元素已经排好顺序
	for (int i = 0; i < size - 1; i++) {
		int end = i;
		int key = array[end + 1]; //刚开始先给第一个元素和第二个元素进行标记
		while (end >= 0 && array[end] >= key) {  //进行比较大小然后进行交换数据
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;  
	}
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	printf("排序之前的元素: \n");
	PrintArray(array, size);

	insertSort(array, size);
	printf("排序之后的元素: \n");
	PrintArray(array, size);

	system("color A");
	system("pause");
	return 0;
}
