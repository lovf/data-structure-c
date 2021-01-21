////Singlist.h�ļ�
//#pragma once
//
//typedef int Type;
//
////�ڵ�Ķ���
//typedef struct Node{
//	struct Node* _next;
//	Type _data;
//}Node;
//
//typedef struct SingleList{
//	Node* _header;
//}SingleList;
//
////��ʼ��
//void singleListInit(SingleList* sl);
//
////��������
//Node* creatNode(SingleList* sl, Type data);
////β��
//void singleListPushBack(SingleList* sl, Type data);
////βɾ
//void singleListPopBack(SingleList* sl);
//
////ͷ��
//void singleListPushFront(SingleList* sl, Type data);
////ͷɾ
//void singleListPopFront(SingleList* sl);
//
////����ǰ�ڵ�ĺ������һ��Ԫ��
//void singleListInsertAfter(Node* pos, Type data);
////ɾ����ǰλ�õĽڵ�
//void singleListErase(Node* pos);
//
////����
//Node* singleListFind(SingleList* sl, Type value);
////��ӡ
//void singleListPrint(SingleList* sl);
//
////����
//void singleListDestroy(SingleList* sl);
//test.c�ļ����Դ���
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

//��ʼ��
void singleListInit(SingleList* sl) {
	sl->_header = NULL;
}

//�����ڵ�
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//β��
void singleListPushBack(SingleList* sl, Type data) {
	Node* node = creatNode(data);
	if (sl->_header == NULL) {
		sl->_header = node;
	}
	else {
		//�ҵ����һ���ڵ��λ��------Ȼ���µĽڵ����
		Node* last = sl->_header;
		while (last->_next) {
			last = last->_next;
		}
		last->_next = node;
		node = NULL;
	}
}

//βɾ
void singleListPopBack(SingleList* sl) {
	
	//������
	if (sl->_header == NULL) {
		return NULL;
	}
	else {
		//�ǿ�����
		//�ҵ����һ��Ԫ�ص�ǰ���ڵ�
		Node* prev = NULL;
		Node* Tail = sl->_header;
		while (Tail->_next) {
			prev = Tail;
			Tail = Tail->_next;
		}
		//����Ҫɾ���Ľڵ�ǡ����ͷ�ڵ�
		if (Tail == sl->_header) {
			sl->_header = NULL;//����Ҫɾ���Ľڵ�ǡ����ͷ�ڵ�
		}
		else {
			prev->_next = NULL;
		}
		//free()��C�������ͷ��ڴ�ռ�ĺ�����ͨ���������ڴ�ռ�ĺ���malloc()���ʹ�ã������ͷ��� malloc()��calloc()��realloc() �Ⱥ���������ڴ�ռ䡣
		//free(Tail);
	}
}

//ͷ��
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

//ͷɾ
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

//����ǰ�ڵ�ĺ������һ��Ԫ��
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
//ɾ����ǰλ�õĽڵ�ĺ���Ԫ��
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
//����
Node* singleListFind(SingleList* sl, Type value) {

	Node* cur = sl->_header;
	while (cur) {
		if (cur->_data == value)
			return cur;
		cur = cur->_next;
	}
	return -1;
}
//��ӡ
void singleListPrint(SingleList* sl) {
	Node* cur = sl->_header;
	while (cur) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");

}
//����
void singleListDestroy(SingleList* sl) {

	Node* cur = sl->_header;
	while (cur) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}
