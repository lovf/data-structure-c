//heap.h文件
#pragma  once 
#include <stdlib.h>
#include <memory.h>

typedef int HPDataType;

typedef struct Heap{
	HPDataType* _array;
	int _size;
	int _capacity;

}Heap;

void Swap(int array[], int left, int right);
void shiftCreat(Heap* hp, HPDataType* array, int size);
void shiftDown(HPDataType* array, int size, int parent);
void shiftUp(HPDataType* array, int size, int child);
void heapPrint(Heap* hp);
//heap.c文件
#include "heap.h"
#include <stdlib.h>
//建堆
void shiftCreat(Heap* hp, HPDataType* array, int size) {

	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_size = size;
	hp->_capacity = size;
	//建堆 ,从最后一个非叶子节点开始建堆  parent =(size-2)/2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDown(hp->_array, size, parent);
	}

}

void Swap(int array[], int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;

}
//小堆的向下调整 parent: 起始调整的位置
void shiftDown(HPDataType* array, int size, int parent) {
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size) {
		//从左右孩子中选一个最小的
		//建小堆
		if (child + 1 < size && array[child + 1] < array[child])
			++child;
		//在去和父节点比较
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			// 更新
			parent = child;
			child = 2 * parent + 1; //仍然是左孩子的位置
		}
		else
			break;
	}
}


//向上调整  堆插入的时候需要向上调整
void shiftUp(HPDataType* array, int size, int child) {
	int parent = (child - 1) / 2;

	while (child > 0) {
		if (array[child] < array[parent]) {

			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {

		printf("%d ", hp->_array[i]);
	}
	printf("\n");

}
//test.c文件
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void test() {
	//大堆数组
	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	shiftCreat(&hp, array, 11);
	heapPrint(&hp);
}

int main () {
	test();


    system("color A");
    system ("pause");
    return 0;
}