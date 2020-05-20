//List.h �ļ�����
//#pragma once 
//
//typedef int Type;
//typedef struct  Node {
//	Type _data;
//	struct Node* _next;
//	struct Node* _prev;
//}Node;
//
//typedef struct List{
//	Node* _header;
//}List;
//
//
//void listInit(List* lst);
//Node* creatNode(Type data);
//
//void listPushBack(List* lst, Type data);
//void listPopBack(List* lst);
//
//void listPushFront(List* lst);
//void listPopFront(List* lst);
//
//void listInsert(List* lst, Type data);
//void listErase(List* lst);
//
//void listPrint(List* lst);
//
//void Destory(List* lst);





//List.c �ļ�����

//#include "LIst.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//
//void listInit(List* lst) {
//	lst->_header = creatNode(0);
//	lst->_header->_prev = lst->_header;
//	lst->_header->_next = lst->_header;
//}
//
//Node* creatNode(Type data) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->_prev = node->_next = NULL;
//	node->_data = data;
//	return node;
//}
//
//void listPushBack(List* lst, Type data) {
//	/*Node* node = creatNode(data);
//	Node* Tail = lst->_header->_prev;
//
//	Tail->_next = node;
//	node->_prev=Tail;
//	lst->_header->_prev = node;
//	node->_next = lst->_header;*/
//	listInsert(lst->_header, data);//��Ϊ���һ��Ԫ�ص�ָ����lst->_header
//}
//void listPopBack(List* lst) {
//
//	/*Node* Tail = lst->_header->_prev;
//	Node* prev = Tail->_prev;
//	free(Tail);
//	prev->_next = lst->_header;
//	lst->_header->_prev = prev;*/
//	listErase(lst->_header->_prev);
//
//}
//
//void listPushFront(List* lst, Type data) {
//	/*Node* Front = lst->_header->_next;
//	Node* node = creatNode(data);
//
//	Front->_prev = node;
//	node->_next = Front;
//	lst->_header->_next = node;
//	node->_prev = lst->_header;*/
//	listInsert(lst->_header->_next, data);
//}
//
//void listPopFront(List* lst) {
//	/*if (lst->_header == lst->_header->_next) {
//	return NULL;
//	}
//	Node* Front = lst->_header->_next;
//	Node* next = Front->_next;
//
//	free(Front);
//	lst->_header->_next = next;
//	next->_prev = lst->_header;
//	*/
//	listErase(lst->_header->_next);
//}
////
//void listInsert(Node* pos, Type data) {
//	Node* prev = pos->_prev;
//	Node* node = creatNode(data);
//
//	pos->_prev = node;
//	node->_next = pos;
//	node->_prev = prev;
//	prev->_next = node;
//}
//void listErase(Node* pos) {
//	if (pos->_next == pos) {
//		return NULL;
//	}
//
//	Node* prev = pos->_prev;
//	Node* next = pos->_next;
//	free(pos);
//	next->_prev = prev;
//	prev->_next = next;
//}
//
//void Destory(List* lst) {
//	Node* cur = lst->_header->_next;
//	while (cur != lst->_header) {
//		Node* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	free(lst->_header);
//	lst->_header = NULL;
//}
//
//void listPrint(List* lst) {
//	Node* cur = lst->_header->_next;
//	while (cur != lst->_header) {
//		printf("%d ", cur->_data);
//		cur = cur->_next;
//	}
//	printf("\n");
//}




#include "LIst.h"
#include <stdio.h>
#include <stdlib.h>

////β��  βɾ
//void  test1() {
//	List lst;
//	listInit(&lst);
//	listPushBack(&lst, 1);
//	listPrint(&lst);
//	listPushBack(&lst, 2);
//	listPrint(&lst);
//	listPushBack(&lst, 3);
//	listPrint(&lst);
//	listPushBack(&lst, 4);
//	listPrint(&lst);
//
//	listPopBack(&lst);
//	listPrint(&lst);
//	listPopBack(&lst);
//	listPrint(&lst);
//	listPopBack(&lst);
//	listPrint(&lst);
//	listPopBack(&lst);
//	listPrint(&lst);
//}
//
////ͷ��  ͷɾ
//void  test2() {
//	List lst;
//	listInit(&lst);
//	listPushFront(&lst,1);
//	listPrint(&lst);
//	listPushFront(&lst, 2);
//	listPrint(&lst);
//	listPushFront(&lst, 3);
//	listPrint(&lst);
//	listPushFront(&lst, 4);
//	listPrint(&lst);
//
//	listPopFront(&lst);
//	listPrint(&lst);
//	listPopFront(&lst);
//	listPrint(&lst);
//	listPopFront(&lst);
//	listPrint(&lst);
//	listPopFront(&lst);
//	listPrint(&lst);
//}
//
////����ǰλ�õ�ǰһ���ڵ����
//void  test3() {
//	List lst;
//	listInit(&lst);
//	listPushFront(&lst, 1);
//	listPrint(&lst);
//	listPushFront(&lst, 2);
//	listPrint(&lst);
//	listPushFront(&lst, 3);
//	listPrint(&lst);
//	listPushFront(&lst, 4);
//	listPrint(&lst);
//	listInsert(lst._header->_next, 100);
//	listPrint(&lst);
//}
//
////ɾ����ǰ�ڵ�
//void  test4() {
//	List lst;
//	listInit(&lst);
//	listPushFront(&lst, 1);
//	listPrint(&lst);
//	listPushFront(&lst, 2);
//	listPrint(&lst);
//	listPushFront(&lst, 3);
//	listPrint(&lst);
//	listPushFront(&lst, 4);
//	listPrint(&lst);
//	listErase(lst._header->_next);
//	listPrint(&lst);
//}
//
//int main() {
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	system("pause");
//	return 0;
//}
//*����listInsret() listErase()������ʵ��β�� βɾ  ͷ�� ͷɾ 
//ʵ��β�����
void test1() {
	List lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPrint(&lst);
	listPushBack(&lst, 2);
	listPrint(&lst);
	listPushBack(&lst, 3);
	listPrint(&lst);
	listPushBack(&lst, 4);
	listPrint(&lst);

	listPopBack(&lst);
	listPrint(&lst);
	listPopBack(&lst);
	listPrint(&lst);
	listPopBack(&lst);
	listPrint(&lst);
	listPopBack(&lst);
	listPrint(&lst);
}

void test2() {
	List lst;
	listInit(&lst);
	listPushFront(&lst, 1);
	listPrint(&lst);
	listPushFront(&lst, 2);
	listPrint(&lst);
	listPushFront(&lst, 3);
	listPrint(&lst);
	listPushFront(&lst, 4);
	listPrint(&lst);

	listPopFront(&lst);
	listPrint(&lst);
	listPopFront(&lst);
	listPrint(&lst);
	listPopFront(&lst);
	listPrint(&lst);
	listPopFront(&lst);
	listPrint(&lst);

}

int main() {
	//test1();
	test2();
	system("pause");
	return 0;

}
















