//List.c�ļ�
#include "List.h"

#include <stdio.h>
#include <stdlib.h>

void listInit(List* lst) {
	//����һ��ͷ���,����ѭ���ṹ
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
	node->_prev = last; //�������ڲ���

	node->_next = lst->_header;
	lst->_header->_prev = node; //�����ⲿ����
	//ListInsert(lst->_header, data);

}

void ListPopBack(List* lst) {
		Node* last, *prev;
	//ע��: ����ɾ��header
		if (lst->_header->_next == lst->_header) {  //��ʾһ�������� ,û�����ݿ���ɾ��
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

//����ǰλ�õ�ǰ�����һ��data
void ListInsert(Node* pos, Type data) {

	Node* prev = pos->_prev;;
	Node* node = creatNode(data);
	//prev  pos node
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}

//��ǰλ�õ�ǰ�����ɾ��
void ListErase(Node* pos) {
	Node* prev, *next;
	//ɾ����ǰλ�õĽڵ�
	//ע��hearder ���ܽ���ɾ��
	if (pos->_next == pos) {  //��ʾ��
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
�����˳����ص�:(���Գ���)
 1.˳���  
�ŵ�: 1>֧��������� 2>�ṹʵ�ּ� 3>�����ṹ 4> β�� βɾ����O(1)
ȱ��: ����λ�õĲ���ɾ��ΪO(n),�����ݴ���.
ʹ�ó���: Ƶ�����ʳ���

 2.���� (˫��)
�ŵ�: 1>����λ�õĲ���ɾ��ΪO(1) 2>û�������ݴ���.
ȱ��: 1>�ṹʵ�ָ��� 2>�������ṹ 3>��֧���������
ʹ�ó���: Ƶ�����볡������


//list.h�ļ�

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

//����ǰ�ڵ����һ��λ�ò���һ��data
void ListInsert(Node* pos, Type data);
//��ǰ�ڵ����һ��λ��ɾ��
void ListErase(Node* pos);
void ListDestory(List* lst);
void ListPrint(List* lst);

//test.c�ļ�
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
	//test1(); //ִ��β��βɾ�Ĳ���
	test2();
	//test3();
    system("color A");
    system ("pause");
    return 0;
}