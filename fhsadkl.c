//////////////////////////seqlist.c文件

//#include "seqlist.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//
//void seqLisInit(seqlist* sl)  {        //初始化 
//	sl->_array = (int*)malloc(4 * sizeof(Datetype));
//	sl->_size = 0;
//	sl->_capacity = 4;
//}
//
//void seqListPushback(seqlist* sl, Datetype value) { //尾插
//	//checkCapacity(sl);
//	//sl->_array[sl->_size++] = value;
//
//	seqLisInsert(sl, sl->_size, value);
//}
//void seqListPopback(seqlist* sl) { //尾删
//	//if (sl->_size) {
//	//	sl->_size--;
//	//}
//	seqLisErase(sl, sl->_size - 1);
//}
//
//void seqListPushFront(seqlist* sl, Datetype value) { // 头插
//	//checkCapacity(sl);
//	////从后往前要将对应下标进行移动
//	//size_t end = sl->_size;
//	//while (end > 0) {
//	//	sl->_array[end] = sl->_array[end - 1];
//	//	end--;
//	//}
//	//sl->_array[0] = value;
//	//sl->_size++;
//	seqLisInsert(sl, 0, value);
//}
//void seqListPopFront(seqlist* sl) { // 头删
//	//if (sl->_size) {  // 头删要满足表中有元素
//	////头删: 从前往后进行删除
//	//	size_t start = 1;
//	//	while (start <sl->_size) {
//	//		sl->_array[start-1] = sl->_array[start];
//	//		start++;
//	//	}
//	//	--sl->_size;
//	//}
//	seqLisErase(sl, 0);
//}
//void seqLisInsert(seqlist* sl, Datetype pos, int value) {  // 在pos位置的前面插入value
//
//	if (pos <= sl->_size) {
//		checkCapacity(sl);
//		// 从后向前
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
//void seqLisErase(seqlist* sl, Datetype pos) { //删除pos位置的数据
//	if (pos < sl->_size) {
//		//从前向后
//		size_t start = pos + 1;
//		while (start < sl->_size) {
//			sl->_array[start - 1] = sl->_array[start];
//			start++;
//		}
//		--sl->_size;
//	}
//}
//
//void seqLisFind(seqlist* sl, int value) { //查找与value元素相等的元素
//	for (int i = 0; i < sl->_size; i++) {
//		if (sl->_array[i] == value) {
//			return 1;
//		}
//		return -1;
//	}
//}
//void seqlistPrint(seqlist* sl) {  //打印
//	for (int i = 0; i < sl->_size; i++) {
//		printf("%d ", sl->_array[i]);
//	}
//	printf("\n");
//}
//
//void checkCapacity(seqlist* sl) {  //扩容
//	if (sl->_size == sl->_capacity) {
//		sl->_capacity *= 2;
//		Datetype* NewCapacity = (Datetype*)malloc(sl->_capacity*sizeof(Datetype));
//		memcpy(NewCapacity, sl->_array, sl->_size*sizeof(Datetype));
//		free(sl->_array);
//		sl->_array = NewCapacity;
//		//sl->_array = (Datetype*)realloc(sl->_array,sl->_capacity*sizeof(Datetype));
//	}
//}

//////////////////////////seqlist.h文件
//#pragma once
//
//typedef int Datetype;
////动态结构体:
//typedef struct seqlist{
//	Datetype* _array;
//	Datetype _size; //结构体中元素的个数
//	Datetype _capacity; //结构体所能容纳的量
//
//}seqlist;
//
//void seqLisInit(seqlist* sl); //初始化
//
//void seqListPushback(seqlist* sl, Datetype value); //尾插
//void seqListPopback(seqlist* sl); //尾删
//
//void seqListPushFront(seqlist* sl, Datetype value); // 头插
//void seqListPopFront(seqlist* sl); // 头删
//
//
//void seqLisInsert(seqlist* sl, Datetype pos, int value); // 在pos位置的前面插入value
//void seqLisErase(seqlist* sl, Datetype pos); //删除pos位置的数据
//
//void seqLisFind(seqlist* sl, int value); //查找与value元素相等的元素
//void seqlistPrint(seqlist* sl); //打印
//
//void checkCapacity(seqlist* sl); //扩容


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
	//尾插和尾删
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

	//头插 和 头删
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
	test4(); //利用 Insert和Erase实现尾插 尾删 头插 头删
	system("color A");
	system("pause");
	return 0;
}



















