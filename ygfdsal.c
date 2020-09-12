//sort.h�ļ�
#pragma once 

typedef struct Heap{
	int* _array;
	int _capacity;
	int _size;

}Heap;


void heapSort(int* array, int n);
void shiftDownBig(int* array, int n, int i);
void Swap(int* array, int left, int right);


//sort.c�ļ�

#include <stdio.h>
#include <stdlib.h>

void heapSort(int* array, int n) {
	//����
	for (int i = (n - 2) / 2; i >= 0; i--) {
		// �����  
		shiftDownBig(array, n, i);
	}
	//ѭ��βɾ
	int size = n;
	while (size > 0) {
		//����
		Swap(array, 0, size - 1);
		//ɾ��
		--size;
		shiftDownBig(array, size, 0);
	}
}

void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void shiftDownBig(int* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		while (child + 1 < size && array[child + 1] > array[child])
			child++;
		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}



//test.c�ļ�
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void test2() {
	int array[10] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 92 };
	heapSort(array, 10);
	for (int i = 0; i < 10;i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
}

int main () {

	test2();
    system("color A");
    system ("pause");
    return 0;
}