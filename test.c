////SingleList.c 文件
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
////尾插操作
////思路: 找到最后一个元素,然后将新创造的节点连接在最后的一位即可.
//void singleListPushBack(Singlelist* sl, Type data) {
//	Node* node = creatNode(data);
//	if (sl->_head == NULL) {
//		sl->_head = node;
//	}
//	else  {
//		Node* last = sl->_head;
//		//找到最后一个节点
//		while (last->_next) {
//			last = last->_next;
//		}
//		//执行尾插操作
//		last->_next = node;
//	}
//}
////尾删操作:
////思路:找到最后一个节点删除,并且修改前驱的指向为NULl;
//void singleListPopBack(Singlelist* sl) {
//
//	//找到最后一个节点,并且修改被删除节点的前驱节点的指向
//	if (sl->_head) {
//		//找到最后一个节点,遍历的过程更新prev
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
////头插操作
////思路: 直接修改头部的指向并且插入新的节点
//void singleListPushFront(Singlelist* sl, Type data) {
//	Node* node = creatNode(data); //创造新的节点
//
//	if (sl->_head == NULL) {
//		sl->_head = node;   //假如头部为空的话,直接将新的节点放到给头部
//	}
//	else {
//		node->_next = sl->_head;  //修改指向
//		sl->_head = node;
//	}
//
//}
////头删操作
////思路:
////1.先将原来要释放的元素保留下来2.将下一个节点给头部3.然后在释放保留之前的节点
//void singleListPopFront(Singlelist* sl) {
//	if (sl->_head == NULL) {
//		return NULL;
//	}
//	else {
//		if (sl->_head) {
//			Node* cur = sl->_head; // 保留头结点
//			sl->_head = cur->_next; //将头结点的指向移到头结点的位置
//			free(cur); //释放之前保留的头结点
//		}
//	}
//}
//
////给pos 后面的节点插入元素
////思路:1.pos位置 2.pos的下一个位置 next 3. 新的节点 newNode  
//void singleListInsertAfter(Node* pos, Type data) {
//	if (pos == NULL) {
//		return;
//	}
//	else {
//		Node* newNode = creatNode(data);
//		//必须要了解 1.pos位置 2.pos的下一个位置 next 3. 新的节点 newNode  
//		Node* next = pos->_next;
//		newNode->_next = next;
//		pos->_next = newNode;
//	}
//}
//
//// 删除pos位置后面的节点
////思路: 要有pos  next  next->_next
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
////Singlelist.h文件
//
////不带头单向不循环链表
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

//test.c 测试文件
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
	printf("找到元素5,给5的后面插入100: ");
	singleListInsertAfter(pos, 100);
	singleListPrint(&sl);

	Node* pos1 = find(&sl, 1);   //找到 1 这个元素,在1 的后面插入200
	printf("找到元素1,给1的后面插入200: ");
	singleListInsertAfter(pos1, 200);  
	singleListPrint(&sl);


	Node* pos3 = find(&sl, 1);
	printf("找到元素1,删除1后面的元素: ");
	singleListEraseAfter(pos3);
	singleListPrint(&sl);

	Node* pos4 = find(&sl, 5);
	printf("找到元素5,删除5后面的元素: ");
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
