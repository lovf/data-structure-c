//////////////////////////seqlist.c�ļ�

//#include "seqlist.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//
//void seqLisInit(seqlist* sl)  {        //��ʼ�� 
//	sl->_array = (int*)malloc(4 * sizeof(Datetype));
//	sl->_size = 0;
//	sl->_capacity = 4;
//}
//
//void seqListPushback(seqlist* sl, Datetype value) { //β��
//	//checkCapacity(sl);
//	//sl->_array[sl->_size++] = value;
//
//	seqLisInsert(sl, sl->_size, value);
//}
//void seqListPopback(seqlist* sl) { //βɾ
//	//if (sl->_size) {
//	//	sl->_size--;
//	//}
//	seqLisErase(sl, sl->_size - 1);
//}
//
//void seqListPushFront(seqlist* sl, Datetype value) { // ͷ��
//	//checkCapacity(sl);
//	////�Ӻ���ǰҪ����Ӧ�±�����ƶ�
//	//size_t end = sl->_size;
//	//while (end > 0) {
//	//	sl->_array[end] = sl->_array[end - 1];
//	//	end--;
//	//}
//	//sl->_array[0] = value;
//	//sl->_size++;
//	seqLisInsert(sl, 0, value);
//}
//void seqListPopFront(seqlist* sl) { // ͷɾ
//	//if (sl->_size) {  // ͷɾҪ���������Ԫ��
//	////ͷɾ: ��ǰ�������ɾ��
//	//	size_t start = 1;
//	//	while (start <sl->_size) {
//	//		sl->_array[start-1] = sl->_array[start];
//	//		start++;
//	//	}
//	//	--sl->_size;
//	//}
//	seqLisErase(sl, 0);
//}
//void seqLisInsert(seqlist* sl, Datetype pos, int value) {  // ��posλ�õ�ǰ�����value
//
//	if (pos <= sl->_size) {
//		checkCapacity(sl);
//		// �Ӻ���ǰ
//		size_t end = sl->_size;
//		while (end > pos) {
//			sl->_array[end] = sl->_array[end - 1];
//			end--;
//		}
//		sl->_array[pos] = value;
//		sl->_size++;
//	}
//}
//
//void seqLisErase(seqlist* sl, Datetype pos) { //ɾ��posλ�õ�����
//	if (pos < sl->_size) {
//		//��ǰ���
//		size_t start = pos + 1;
//		while (start < sl->_size) {
//			sl->_array[start - 1] = sl->_array[start];
//			start++;
//		}
//		--sl->_size;
//	}
//}
//
//void seqLisFind(seqlist* sl, int value) { //������valueԪ����ȵ�Ԫ��
//	for (int i = 0; i < sl->_size; i++) {
//		if (sl->_array[i] == value) {
//			return 1;
//		}
//		return -1;
//	}
//}
//void seqlistPrint(seqlist* sl) {  //��ӡ
//	for (int i = 0; i < sl->_size; i++) {
//		printf("%d ", sl->_array[i]);
//	}
//	printf("\n");
//}
//
//void checkCapacity(seqlist* sl) {  //����
//	if (sl->_size == sl->_capacity) {
//		sl->_capacity *= 2;
//		Datetype* NewCapacity = (Datetype*)malloc(sl->_capacity*sizeof(Datetype));
//		memcpy(NewCapacity, sl->_array, sl->_size*sizeof(Datetype));
//		free(sl->_array);
//		sl->_array = NewCapacity;
//		//sl->_array = (Datetype*)realloc(sl->_array,sl->_capacity*sizeof(Datetype));
//	}
//}

//////////////////////////seqlist.h�ļ�
//#pragma once
//
//typedef int Datetype;
////��̬�ṹ��:
//typedef struct seqlist{
//	Datetype* _array;
//	Datetype _size; //�ṹ����Ԫ�صĸ���
//	Datetype _capacity; //�ṹ���������ɵ���
//
//}seqlist;
//
//void seqLisInit(seqlist* sl); //��ʼ��
//
//void seqListPushback(seqlist* sl, Datetype value); //β��
//void seqListPopback(seqlist* sl); //βɾ
//
//void seqListPushFront(seqlist* sl, Datetype value); // ͷ��
//void seqListPopFront(seqlist* sl); // ͷɾ
//
//
//void seqLisInsert(seqlist* sl, Datetype pos, int value); // ��posλ�õ�ǰ�����value
//void seqLisErase(seqlist* sl, Datetype pos); //ɾ��posλ�õ�����
//
//void seqLisFind(seqlist* sl, int value); //������valueԪ����ȵ�Ԫ��
//void seqlistPrint(seqlist* sl); //��ӡ
//
//void checkCapacity(seqlist* sl); //����


//test.c
#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

void test1() {
	seqlist sl;
	seqLisInit(&sl);
	seqListPushback(&sl, 1);
	seqListPushback(&sl, 2);
	seqListPushback(&sl, 3);
	seqlistPrint(&sl);
	seqListPopback(&sl);
	seqlistPrint(&sl);
	seqListPopback(&sl);
	seqlistPrint(&sl);
}
void test2() {
	seqlist sl;
	seqLisInit(&sl);
	seqListPushback(&sl, 1);
	seqListPushback(&sl, 2);
	seqListPushback(&sl, 3);
	seqlistPrint(&sl);

	seqListPushFront(&sl, 4);
	seqlistPrint(&sl);
	seqListPushFront(&sl, 5);
	seqlistPrint(&sl);
	seqListPushFront(&sl, 6);
	seqlistPrint(&sl);

	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);
}
void test3() {
	seqlist sl;
	seqLisInit(&sl);
	seqListPushback(&sl, 1);
	seqListPushback(&sl, 2);
	seqListPushback(&sl, 4);
	seqLisInsert(&sl, 2, 3);
	seqlistPrint(&sl);
	seqLisErase(&sl, 1);
	seqlistPrint(&sl);
}

void test4() {
	seqlist sl;
	seqLisInit(&sl);
	//β���βɾ
	seqListPushback(&sl, 1);
	seqListPushback(&sl, 2);
	seqListPushback(&sl, 3);
	seqListPushback(&sl, 4);
	seqListPushback(&sl, 5);
	seqListPushback(&sl, 6);
	seqlistPrint(&sl);

	seqListPopback(&sl);
	seqlistPrint(&sl);
	seqListPopback(&sl);
	seqlistPrint(&sl);

	//ͷ�� �� ͷɾ
	seqListPushFront(&sl, 2);
	seqListPushFront(&sl, 3);
	seqListPushFront(&sl, 4);
	seqListPushFront(&sl, 5);
	seqListPushFront(&sl, 6);

	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);
}

int main() {

	//test1();
	//test2();
	//test3();
	test4(); //���� Insert��Eraseʵ��β�� βɾ ͷ�� ͷɾ
	system("color A");
	system("pause");
	return 0;
}



















