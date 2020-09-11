//heap.p文件
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

void shiftDownLittle(HPDataType* array, int size, int parent);
void shiftUpLittle(HPDataType* array, int child);


void shiftDownBig(HPDataType* array, int size, int parent);
void shiftUpBig(HPDataType* array, int child);



///////////// 11次
//尾插
void heapPush(Heap* hp, HPDataType data);
// 删除堆顶元素
void heapPop(Heap* hp);

HPDataType heapTop(Heap* hp);
HPDataType heapEmpty(Heap* hp);

void heapPrint(Heap* hp);

//heap.c文件

#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
//建堆
//用一个数组的数据创建一个堆,  从最后一个非叶子节点开始(最后一个非叶子的节点: (数组大小-2) / 2 ),进行向下调整,直到调整到根节点的位置,结束.
void shiftCreat(Heap* hp, HPDataType* array, int size) {
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_size = size;
	hp->_capacity = size;
	//建堆 ,从最后一个非叶子节点开始建堆  parent =(size-2)/2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDownBig(hp->_array, size, parent);
	}

}

void Swap(int array[], int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;

}
//小堆的向下调整 parent: 起始调整的位置
void shiftDownLittle(HPDataType* array, int size, int parent) {
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//大堆的向下调整 parent: 起始调整的位置
void shiftDownBig(HPDataType* array, int size, int parent) {
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size) {
		//从左右孩子中选一个最小的
		//建小堆
		if (child + 1 < size && array[child + 1] > array[child])
			++child;
		//在去和父节点比较
		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			// 更新
			parent = child;
			child = 2 * parent + 1; //仍然是左孩子的位置
		}
		else
			break;
	}
}
//堆的插入: 插入之后仍然满足是一个新的堆
//步骤: 1. 先把元素放在数组最后的一个位置,然后在进行向上调整
void heapPush(Heap* hp, HPDataType data) {
	//检查容量
	if (hp->_size == hp->_capacity) {
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, sizeof(HPDataType)*hp->_capacity);
	}

	//尾插
	hp->_array[hp->_size++] = data;
	shiftUpBig(hp->_array, hp->_size - 1);

}
//删除堆顶元素  (最值)
//步骤: 1.先交换顶部和尾部的元素 2.删除最后一个元素 3. 进行一次 s向下调整
void heapPop(Heap* hp) {
	if (hp->_size > 0) {
		//1.交换堆顶和最后一个椰子
		Swap(hp->_array, 0, hp->_size - 1);
		//2.删除最后一个元素
		hp->_size--;
		//3.向下进行调整
		shiftDownBig(hp->_array, hp->_size, 0);

	}
}

//向上调整  堆插入的时候需要向上调整
void shiftUpLittle(HPDataType* array, int child) {
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//向上调整  堆插入的时候需要向上调整
void shiftUpBig(HPDataType* array, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] > array[parent]) {

			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

HPDataType heapTop(Heap* hp) {
	return hp->_array[0];

}
HPDataType heapEmpty(Heap* hp) {
	if (hp->_size == 0) {
		return 1;
	}
	else {
		return 0;
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

void test2() {
	int array[10] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	Heap hp;
	shiftCreat(&hp, array, 10);
	heapPrint(&hp);
	printf("heapPush: \n");
	heapPush(&hp, 80);
	heapPrint(&hp);
	printf("heapPop: \n");

	heapPop(&hp);
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
void test3() {

	int array[10] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	Heap hp;
	shiftCreat(&hp, array, 10);
	heapPrint(&hp);
	printf("heapPush: \n");
	heapPush(&hp, 80);
	heapPrint(&hp);
	printf("heapPop: \n");

	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 8);
	heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 100);
	heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
}

void test4() {
	int array[10] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	Heap hp;
	shiftCreat(&hp, array, 10);
	heapPrint(&hp);
	while (heapEmpty(&hp) != 1) {
		printf("%d\n",heapTop(&hp));
		heapPop(&hp);
	}
}

int main () {
	//test();
	//test2();
	//test3();
	test4();
	system("color A");
    system ("pause");
    return 0;
}