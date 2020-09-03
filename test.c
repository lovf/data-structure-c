////SingleList.c �ļ�
//#include "SingleList.h"
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void singleListInit(Singlelist* sl) {
//	sl->_head = NULL;
//}
//
//Node* creatNode(Type data) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->_data = data;
//	node->_next = NULL;
//	return node;
//}
////β�����
////˼·: �ҵ����һ��Ԫ��,Ȼ���´���Ľڵ�����������һλ����.
//void singleListPushBack(Singlelist* sl, Type data) {
//	Node* node = creatNode(data);
//	if (sl->_head == NULL) {
//		sl->_head = node;
//	}
//	else  {
//		Node* last = sl->_head;
//		//�ҵ����һ���ڵ�
//		while (last->_next) {
//			last = last->_next;
//		}
//		//ִ��β�����
//		last->_next = node;
//	}
//}
////βɾ����:
////˼·:�ҵ����һ���ڵ�ɾ��,�����޸�ǰ����ָ��ΪNULl;
//void singleListPopBack(Singlelist* sl) {
//
//	//�ҵ����һ���ڵ�,�����޸ı�ɾ���ڵ��ǰ���ڵ��ָ��
//	if (sl->_head) {
//		//�ҵ����һ���ڵ�,�����Ĺ��̸���prev
//		Node* prev = NULL;
//		Node* Tail = sl->_head;
//		while (Tail->_next) {
//			prev = Tail;
//			Tail = Tail->_next;
//		}
//		if (Tail == sl->_head) {
//			sl->_head = NULL;
//		}
//		else {
//			prev->_next = NULL;
//			free(Tail);
//		}
//	}
//}
////ͷ�����
////˼·: ֱ���޸�ͷ����ָ���Ҳ����µĽڵ�
//void singleListPushFront(Singlelist* sl, Type data) {
//	Node* node = creatNode(data); //�����µĽڵ�
//
//	if (sl->_head == NULL) {
//		sl->_head = node;   //����ͷ��Ϊ�յĻ�,ֱ�ӽ��µĽڵ�ŵ���ͷ��
//	}
//	else {
//		node->_next = sl->_head;  //�޸�ָ��
//		sl->_head = node;
//	}
//
//}
////ͷɾ����
////˼·:
////1.�Ƚ�ԭ��Ҫ�ͷŵ�Ԫ�ر�������2.����һ���ڵ��ͷ��3.Ȼ�����ͷű���֮ǰ�Ľڵ�
//void singleListPopFront(Singlelist* sl) {
//	if (sl->_head == NULL) {
//		return NULL;
//	}
//	else {
//		if (sl->_head) {
//			Node* cur = sl->_head; // ����ͷ���
//			sl->_head = cur->_next; //��ͷ����ָ���Ƶ�ͷ����λ��
//			free(cur); //�ͷ�֮ǰ������ͷ���
//		}
//	}
//}
//
////��pos ����Ľڵ����Ԫ��
////˼·:1.posλ�� 2.pos����һ��λ�� next 3. �µĽڵ� newNode  
//void singleListInsertAfter(Node* pos, Type data) {
//	if (pos == NULL) {
//		return;
//	}
//	else {
//		Node* newNode = creatNode(data);
//		//����Ҫ�˽� 1.posλ�� 2.pos����һ��λ�� next 3. �µĽڵ� newNode  
//		Node* next = pos->_next;
//		newNode->_next = next;
//		pos->_next = newNode;
//	}
//}
//
//// ɾ��posλ�ú���Ľڵ�
////˼·: Ҫ��pos  next  next->_next
//void singleListEraseAfter(Node* pos) {
//	if (pos == NULL) {
//		return;
//	}
//	else {
//		Node* next = pos->_next;
//		if (next) {
//			pos->_next = next->_next;
//			free(next);
//		}
//	}
//}
//
//Node* find(Singlelist* sl, Type data) {
//	Node* cur = sl->_head;
//	while (cur) {
//		if (cur->_data == data) {
//			return cur;
//		}
//		cur = cur->_next;
//	}
//	return  NULL;
//}
//
//void singleListPrint(Singlelist* sl) {
//	Node* cur = sl->_head;
//	while (cur) {
//		printf("%d ", cur->_data);
//		cur = cur->_next;
//	}
//	printf("\n");
//}
////Singlelist.h�ļ�
//
////����ͷ����ѭ������
//#pragma once 
//
//typedef int Type;
//
//typedef struct Node{
//	Type _data;
//	struct Node* _next;
//}Node;
//
//
//typedef struct Singlelist{
//	Node* _head;
//
//}Singlelist;
//
//Node* creatNode(Type data);
//
//void singleListInit(Singlelist* sl);
//
//void singleListPushBack(Singlelist* sl, Type data);
//void singleListPopBack(Singlelist* sl);
//
//
//void singleListPushFront(Singlelist* sl, Type data);
//void singleListPopFront(Singlelist* sl);
//
//
//void singleListInsertAfter(Node* pos, Type data);
//void singleListEraseAfter(Node* pos);
//
//void singleListPrint(Singlelist* sl);
//Node* find(Singlelist* sl, Type date);

//test.c �����ļ�
#include "SingleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test1() {
	Singlelist sl;

	singleListInit(&sl);
	singleListPushBack(&sl, 1);
	singleListPushBack(&sl, 2);
	singleListPushBack(&sl, 3);
	singleListPushBack(&sl, 4);
	singleListPushBack(&sl, 5);
	singleListPushBack(&sl, 6);
	singleListPrint(&sl);

	singleListPopBack(&sl);
	singleListPrint(&sl);
	singleListPopBack(&sl);
	singleListPrint(&sl);
	singleListPopBack(&sl);
	singleListPrint(&sl);
	singleListPopBack(&sl);
	singleListPrint(&sl);
	singleListPopBack(&sl);
	singleListPrint(&sl);
	singleListPopBack(&sl);
	singleListPrint(&sl);
}

void test2() {
	Singlelist sl;

	singleListInit(&sl);
	singleListPushFront(&sl, 1);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 5);
	singleListPushFront(&sl, 6);
	singleListPrint(&sl);

	singleListPopFront(&sl);
	singleListPrint(&sl);
	singleListPopFront(&sl);
	singleListPrint(&sl);
	singleListPopFront(&sl);
	singleListPrint(&sl);
}

void test3() {
	Singlelist sl;

	singleListInit(&sl);
	singleListPushFront(&sl, 1);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 5);
	singleListPushFront(&sl, 6);
	singleListPrint(&sl);

	Node* pos = find(&sl, 5);
	printf("�ҵ�Ԫ��5,��5�ĺ������100: ");
	singleListInsertAfter(pos, 100);
	singleListPrint(&sl);

	Node* pos1 = find(&sl, 1);   //�ҵ� 1 ���Ԫ��,��1 �ĺ������200
	printf("�ҵ�Ԫ��1,��1�ĺ������200: ");
	singleListInsertAfter(pos1, 200);  
	singleListPrint(&sl);


	Node* pos3 = find(&sl, 1);
	printf("�ҵ�Ԫ��1,ɾ��1�����Ԫ��: ");
	singleListEraseAfter(pos3);
	singleListPrint(&sl);

	Node* pos4 = find(&sl, 5);
	printf("�ҵ�Ԫ��5,ɾ��5�����Ԫ��: ");
	singleListEraseAfter(pos4);
	singleListPrint(&sl);
}

int main () {
	//test1();
    //test2();
	test3();
	system("color A");
    system ("pause");
    return 0;
}
