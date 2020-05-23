#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void test() {
	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	creatHeap(&hp, array, 11);
	HeapPrint(&hp);
}
int main() {
	test();
	system("pause");
	return 0;
}

//*******************************************************************************************
//�����ļ�heap.h
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int HpDataType;

typedef struct Heap{
	HpDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;

void creatHeap(Heap* hp, HpDataType* _array, int size);
void Swap(HpDataType* array, int left, int right);
void shiftDown(HpDataType* array, int size, int parent);
void HeapPrint(Heap* hp);

//********************************************************************************
//�����ļ�heap.c
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//����
void creatHeap(Heap* hp, HpDataType* array, int size) {
	hp->_array = (HpDataType*)malloc(sizeof(HpDataType)*size);
	memcpy(hp->_array, array, sizeof(HpDataType)*size);
	hp->_capacity = size;
	hp->_size = size;
	//�����һ����Ҷ�ӵ�λ�ÿ�ʼ
	for (int parent = (size - 2) / 2; parent >= 0; --parent) {
		shiftDown(hp->_array, size, parent);
	}
}
void Swap(HpDataType* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
void shiftDown(HpDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child<size) {
		if (child + 1 && array[child]>array[child + 1])
			++child;
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void HeapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");

}
