//List.c文件
#include "List.h"

#include <stdio.h>
#include <stdlib.h>

void listInit(List* lst) {
	//构建一个头结点,构成循环结构
	lst->_header = creatNode(0);
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;

}

Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

void ListPushBack(List* lst, Type data) {
	Node* node = creatNode(data);
	Node* last = lst->_header->_prev;
	//last  node header 
	last->_next = node;
	node->_prev = last; //先连接内部的

	node->_next = lst->_header;
	lst->_header->_prev = node; //连接外部的线
	//ListInsert(lst->_header, data);

}

void ListPopBack(List* lst) {
		Node* last, *prev;
	//注意: 不能删除header
		if (lst->_header->_next == lst->_header) {  //表示一个空链表 ,没有数据可以删除
			return;
		}
		last = lst->_header->_prev;
		prev = last->_prev;
	
		prev->_next = lst->_header;
		lst->_header->_prev = prev;
		free(last);
	ListErase(lst->_header->_prev);
}

void ListPushFront(List* lst, Type data) {
	// header node front
	Node* node = creatNode(data);
	Node* front = lst->_header->_next;

	node->_next = front;
	front->_prev = node;
	node->_prev = lst->_header;
	lst->_header->_next = node;
	//ListInsert(lst->_header->_next, data);
}

void ListPopFront(List* lst) {
	/*Node* front, *next;
	if (lst->_header == lst->_header->_next) {
	return;
	}
	front = lst->_header->_next;
	next = front->_next;
	free(front);
	lst->_header->_next = next;
	next->_prev = lst->_header;*/
	ListErase(lst->_header->_next);
}

//给当前位置的前面插入一个data
void ListInsert(Node* pos, Type data) {

	Node* prev = pos->_prev;;
	Node* node = creatNode(data);
	//prev  pos node
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}

//当前位置的前面进行删除
void ListErase(Node* pos) {
	Node* prev, *next;
	//删除当前位置的节点
	//注意hearder 不能进行删除
	if (pos->_next == pos) {  //表示空
		return;
	}
	prev = pos->_prev;
	next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;

}

void ListPrint(List* lst) {
	Node*  cur = lst->_header->_next;
	while (cur != lst->_header) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
链表和顺序表特点:(面试常考)
 1.顺序表  
优点: 1>支持随机访问 2>结构实现简单 3>连续结构 4> 尾插 尾删均是O(1)
缺点: 任意位置的插入删除为O(n),有增容代价.
使用场景: 频繁访问场景

 2.链表 (双向)
优点: 1>任意位置的插入删除为O(1) 2>没有有增容代价.
缺点: 1>结构实现复杂 2>非连续结构 3>不支持随机访问
使用场景: 频繁插入场景场景


//list.h文件

typedef int Type;

typedef struct Node{
	Type _data;
	struct Node* _next;
	struct Node* _prev;
}Node;

typedef struct List{
	Node* _header;
}List;

void listInit(List* lst);
Node* creatNode(Type data);

void ListPushBack(List* lst, Type data);
void ListPopBack(List* lst);

void ListPushFront(List* lst, Type data);
void ListPopFront(List* lst);

//给当前节点的下一个位置插入一个data
void ListInsert(Node* pos, Type data);
//当前节点的下一个位置删除
void ListErase(Node* pos);
void ListDestory(List* lst);
void ListPrint(List* lst);

//test.c文件
#include "List.h"
#include <stdio.h>
#include <stdlib.h>



void test1() {
	List lst;
	listInit(&lst);
	ListPushBack(&lst, 1);
    ListPushBack(&lst, 2);
	ListPushBack(&lst, 3);
	ListPushBack(&lst, 4);
	ListPushBack(&lst, 5);
	ListPushBack(&lst, 6);
	ListPrint(&lst);
	//
	//ListPopBack(&lst);
	//ListPrint(&lst);
	//ListPopBack(&lst);
	//ListPrint(&lst);
	//ListPopBack(&lst);
	//ListPrint(&lst);
	//ListPopBack(&lst);
	//ListPrint(&lst);
	//ListPopBack(&lst);
	//ListPrint(&lst);
	//ListPopBack(&lst);
}

void test2() {
	List lst;
	listInit(&lst);
	ListPushFront(&lst, 1);
	ListPrint(&lst);
	ListPushFront(&lst, 2);
	ListPrint(&lst);
	ListPushFront(&lst, 3);
	ListPrint(&lst);
	ListPushFront(&lst, 4);
	ListPrint(&lst);

	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
}

int main () {
	//test1(); //执行尾插尾删的操作
	test2();
	//test3();
    system("color A");
    system ("pause");
    return 0;
}