//heap.h�ļ�
#pragma once 
#include <stdio.h>
#include <stdlib.h>

typedef  int  HpDataType;
typedef struct Heap{
	HpDataType* _array;
	HpDataType _size;
	HpDataType _capacity;

}Heap;

void creatHeap(Heap* hp, HpDataType* array, int size);

void Swap(HpDataType* array, int left, int right);

void heapDownL(HpDataType* array,int size,int parent);
void heapUpL(HpDataType* array, int size, int child);

void heapDownB(HpDataType* array, int size, int parent);
void heapUpB(HpDataType* array, int size, int child);

void heapPrint(Heap* array);


void heapPush(HpDataType* array, HpDataType data);

void heapPop(HpDataType* array);
void heapTop(HpDataType* array);
int heapEmpty(Heap* hp)
//******************************************************************************************************
//heap1.c�ļ�

#include "heap1.h";
#include <stdlib.h>
#include <stdlib.h>
#include<memory.h>


void creatHeap(Heap* hp, HpDataType* array, int size) {
	hp->_array = (HpDataType*)malloc(sizeof(HpDataType)*size);
	memcpy(hp->_array, array, sizeof(HpDataType)*size);
	hp->_capacity = size;
	hp->_size = size;

	for (int parent = (size - 2) / 2; parent >= 0; --parent) {
		heapDownL(hp->_array, size, parent);
		heapDownB(hp->_array, size, parent);

	}
}

void Swap(HpDataType* array, int left, int right) {
	int tep = array[left];
	array[left] = array[right];
	array[right] = tep;
}

////С�� ���µ���
void heapDownL(HpDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child] > array[child + 1])
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
void  heapUpL(HpDataType* array,int child)  {
	int parent = (child-1) / 2;
	while (child > 0) {
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		} else {
			break;
		}
	}
}

//��� ���µ���
void heapDownB(HpDataType* array, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && array[child] < array[child + 1])
			++child;
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
void heapUpB(HpDataType* array, HpDataType size, HpDataType child) {

	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

β��:��Ҫ��������Ƿ�,Ȼ��β��,Ȼ���ڽ������ϵ���,�ж������Ԫ���Ƿ���϶ѵ����
void heapPush(Heap* hp, HpDataType data) {
	�������
	if (hp->_capacity == hp->_size){
		hp->_capacity *= 2;
		hp->_array = (HpDataType*)realloc(hp->_array, sizeof(HpDataType)*hp->_capacity);
	}
	hp->_array[hp->_size++] = data;
	heapUpB(hp->_array, hp->_size, hp->_size - 1);//β��֮����ȻҪ�����ж��Ƿ���϶ѵĹ涨
}
ɾ���Ѷ���Ԫ��,��ɾ��������ֵ   ��鲻��ֱ��ɾ���������ݲ������ɾ��
void heapPop(Heap* hp) {
	1.����
	Swap(hp->_array, 0, hp->_size - 1);
	2.ɾ��
	--hp->_size;
	3.����Ԫ��
	heapDownB(hp->_array, hp->_size, 0);

}


void heapTop(Heap* hp) {
	return  hp->_array[0];
}

int heapEmpty(Heap* hp) {
	if (hp->_size == 0) {
		return 1;
	} else {
		return 0;
	}
}

//***************************************************************************************************

#include "heap1.h"
#include <stdio.h>
#include <stdlib.h>



void test() {
	Heap hp;
	int array[] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	int size = sizeof(array) / sizeof(array[0]);
	creatHeap(&hp, array, size);
	heapPrint(&hp);

	heapPush(&hp, 80);
	heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
}

int main() {

	test();

	system("pause");
	return 0;
}








