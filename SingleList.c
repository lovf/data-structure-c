////Singlist.h文件
//#pragma once
//
//typedef int Type;
//
////节点的定义
//typedef struct Node{
//	struct Node* _next;
//	Type _data;
//}Node;
//
//typedef struct SingleList{
//	Node* _header;
//}SingleList;
//
////初始化
//void singleListInit(SingleList* sl);
//
////创建数组
//Node* creatNode(SingleList* sl, Type data);
////尾插
//void singleListPushBack(SingleList* sl, Type data);
////尾删
//void singleListPopBack(SingleList* sl);
//
////头插
//void singleListPushFront(SingleList* sl, Type data);
////头删
//void singleListPopFront(SingleList* sl);
//
////给当前节点的后面插入一个元素
//void singleListInsertAfter(Node* pos, Type data);
////删除当前位置的节点
//void singleListErase(Node* pos);
//
////查找
//Node* singleListFind(SingleList* sl, Type value);
////打印
//void singleListPrint(SingleList* sl);
//
////销毁
//void singleListDestroy(SingleList* sl);
//test.c文件测试代码
//#include "SingleList.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//void test1() {
//	SingleList sl;
//	singleListInit(&sl);
//	singleListPushBack(&sl, 1);
//	singleListPushBack(&sl, 2);
//	singleListPushBack(&sl, 3);
//	singleListPushBack(&sl, 4);
//	singleListPushBack(&sl, 5);
//
//	singleListPrint(&sl);
//
//	singleListPopBack(&sl);
//	singleListPrint(&sl);
//	singleListPopBack(&sl);
//	singleListPrint(&sl);
//	singleListPopBack(&sl);
//	singleListPrint(&sl);
//
//	singleListPopBack(&sl);
//	singleListPrint(&sl);
//	singleListPopBack(&sl);
//	singleListPrint(&sl);
//
//
//
//
//
//}
//
//void test2() {
//	SingleList sl;
//	singleListInit(&sl);
//	singleListPushBack(&sl, 1);
//	singleListPushBack(&sl, 2);
//	singleListPushBack(&sl, 3);
//	singleListPushBack(&sl, 4);
//	singleListPushBack(&sl, 5);
//	singleListPrint(&sl);
//
//
//	/*singleListPushFront(&sl, 10);
//	singleListPrint(&sl);
//	singleListPushFront(&sl, 11);
//	singleListPrint(&sl);
//	singleListPushFront(&sl, 12);
//	singleListPrint(&sl);
//
//
//	singleListPopFront(&sl);
//	singleListPrint(&sl);
//	singleListPopFront(&sl);
//	singleListPrint(&sl);
//	singleListPopFront(&sl);
//	singleListPrint(&sl);*/
//
//	Node* find = singleListFind(&sl, 3);
//
//	singleListInsertAfter(find, 200);
//	singleListPrint(&sl);
//
//	singleListErase(find);
//	singleListPrint(&sl);
//}
//
//
//int main() {
//
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}


#include "SingleList.h"
#include <stdio.h>
#include <stdlib.h>

//初始化
void singleListInit(SingleList* sl) {
	sl->_header = NULL;
}

//创建节点
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//尾插
void singleListPushBack(SingleList* sl, Type data) {
	Node* node = creatNode(data);
	if (sl->_header == NULL) {
		sl->_header = node;
	}
	else {
		//找到最后一个节点的位置------然后将新的节点插入
		Node* last = sl->_header;
		while (last->_next) {
			last = last->_next;
		}
		last->_next = node;
		node = NULL;
	}
}

//尾删
void singleListPopBack(SingleList* sl) {
	
	//空链表
	if (sl->_header == NULL) {
		return NULL;
	}
	else {
		//非空链表
		//找到最后一个元素的前驱节点
		Node* prev = NULL;
		Node* Tail = sl->_header;
		while (Tail->_next) {
			prev = Tail;
			Tail = Tail->_next;
		}
		//假设要删除的节点恰好是头节点
		if (Tail == sl->_header) {
			sl->_header = NULL;//假设要删除的节点恰好是头节点
		}
		else {
			prev->_next = NULL;
		}
		//free()是C语言中释放内存空间的函数，通常与申请内存空间的函数malloc()结合使用，可以释放由 malloc()、calloc()、realloc() 等函数申请的内存空间。
		//free(Tail);
	}
}

//头插
void singleListPushFront(SingleList* sl, Type data) {
	Node* node = creatNode(data);
	if (sl->_header == NULL) {
		sl->_header = node;
	}
	else {
		node->_next = sl->_header;
		sl->_header = node;
	}
}

//头删
void singleListPopFront(SingleList* sl) {
	if (sl->_header == NULL) {
		return NULL;
	}
	else{
		Node* cur = sl->_header;
		sl->_header = cur->_next;
		//free(cur);
	}
}

//给当前节点的后面插入一个元素
void singleListInsertAfter(Node* pos, Type data) {
	Node* node = creatNode(data);
	//pos  node  next 
	if (pos == NULL) {
		return;
	}
	else{
		node->_next = pos->_next;
		pos->_next = node;
	}
}
//删除当前位置的节点的后面元素
void singleListErase(Node* pos) {
	Node* next = pos->_next;
	if (pos == NULL) {
		return;
	}
	//pos next  
	if (next) {
		pos->_next = next->_next;
		//free(next);
	}

}
//查找
Node* singleListFind(SingleList* sl, Type value) {

	Node* cur = sl->_header;
	while (cur) {
		if (cur->_data == value)
			return cur;
		cur = cur->_next;
	}
	return -1;
}
//打印
void singleListPrint(SingleList* sl) {
	Node* cur = sl->_header;
	while (cur) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");

}
//销毁
void singleListDestroy(SingleList* sl) {

	Node* cur = sl->_header;
	while (cur) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}
