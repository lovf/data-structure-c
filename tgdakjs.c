//heap.p�ļ�
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



///////////// 11��
//β��
void heapPush(Heap* hp, HPDataType data);
// ɾ���Ѷ�Ԫ��
void heapPop(Heap* hp);

HPDataType heapTop(Heap* hp);
HPDataType heapEmpty(Heap* hp);

void heapPrint(Heap* hp);

//heap.c�ļ�

#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
//����
//��һ����������ݴ���һ����,  �����һ����Ҷ�ӽڵ㿪ʼ(���һ����Ҷ�ӵĽڵ�: (�����С-2) / 2 ),�������µ���,ֱ�����������ڵ��λ��,����.
void shiftCreat(Heap* hp, HPDataType* array, int size) {
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_size = size;
	hp->_capacity = size;
	//���� ,�����һ����Ҷ�ӽڵ㿪ʼ����  parent =(size-2)/2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDownBig(hp->_array, size, parent);
	}

}

void Swap(int array[], int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;

}
//С�ѵ����µ��� parent: ��ʼ������λ��
void shiftDownLittle(HPDataType* array, int size, int parent) {
	//����λ��
	int child = 2 * parent + 1;
	while (child < size) {
		//�����Һ�����ѡһ����С��
		//��С��
		if (child + 1 < size && array[child + 1] < array[child])
			++child;
		//��ȥ�͸��ڵ�Ƚ�
		if (array[child] < array[parent]) {
			Swap(array, child, parent);
			// ����
			parent = child;
			child = 2 * parent + 1; //��Ȼ�����ӵ�λ��
		}
		else
			break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ѵ����µ��� parent: ��ʼ������λ��
void shiftDownBig(HPDataType* array, int size, int parent) {
	//����λ��
	int child = 2 * parent + 1;
	while (child < size) {
		//�����Һ�����ѡһ����С��
		//��С��
		if (child + 1 < size && array[child + 1] > array[child])
			++child;
		//��ȥ�͸��ڵ�Ƚ�
		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			// ����
			parent = child;
			child = 2 * parent + 1; //��Ȼ�����ӵ�λ��
		}
		else
			break;
	}
}
//�ѵĲ���: ����֮����Ȼ������һ���µĶ�
//����: 1. �Ȱ�Ԫ�ط�����������һ��λ��,Ȼ���ڽ������ϵ���
void heapPush(Heap* hp, HPDataType data) {
	//�������
	if (hp->_size == hp->_capacity) {
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, sizeof(HPDataType)*hp->_capacity);
	}

	//β��
	hp->_array[hp->_size++] = data;
	shiftUpBig(hp->_array, hp->_size - 1);

}
//ɾ���Ѷ�Ԫ��  (��ֵ)
//����: 1.�Ƚ���������β����Ԫ�� 2.ɾ�����һ��Ԫ�� 3. ����һ�� s���µ���
void heapPop(Heap* hp) {
	if (hp->_size > 0) {
		//1.�����Ѷ������һ��Ҭ��
		Swap(hp->_array, 0, hp->_size - 1);
		//2.ɾ�����һ��Ԫ��
		hp->_size--;
		//3.���½��е���
		shiftDownBig(hp->_array, hp->_size, 0);

	}
}

//���ϵ���  �Ѳ����ʱ����Ҫ���ϵ���
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
//���ϵ���  �Ѳ����ʱ����Ҫ���ϵ���
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

//test.c�ļ�
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void test() {
	//�������
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