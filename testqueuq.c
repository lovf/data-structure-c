//�����ļ� queue.h
#pragma once 
#include <stdio.h>
#include <stdlib.h>


typedef int QDataType;

// ��ʽ�ṹ����ʾ����
typedef struct QNode{
	QDataType _data;
	struct QNode* _next;
}QNode;

//���еĽṹ
typedef struct Queue{

	QNode* _front;
	QNode* _rear;
	QDataType _size;
}Queue;

void queueInit(Queue* q);

QNode* creatQueue(QDataType data);
void queuePush(Queue* q, QDataType data);
void queuePop(Queue* q);

int queueSize(Queue* q);

int queuqEmpty(Queue* q);

void queueDestory(Queue* q);

//��ö�ͷ��Ԫ��
QDataType queueFront(Queue* q);
//��ö�β��Ԫ��
QDataType queueBack(Queue* q);
//*********************************************************************************************************
//
////�����ļ�queue.c
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queueInit(Queue* q) {

	q->_front = q->_rear = NULL;
	q->_size = 0;

}

QNode* creatQueue(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_next = NULL;
	node->_data = data;
	return node;
}

void queuePush(Queue* q, QDataType data) {
	QNode* node = creatQueue(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		q->_rear->_next = node; //�����һ���´����Ľڵ���������
		q->_rear = node; //������һ���ڵ�
	}
	++q->_size;
}
void queuePop(Queue* q) {
	if (q->_front == NULL) {
		return;
	}
	else {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL) {
			q->_rear = NULL;
			--q->_size;
		}
	}
}

int queueSize(Queue* q) {
	return q->_size;
	/*
	int num = 0;
	QNode* cur = q->_front;
	while (cur) {
	num++;
	cur = cur->_next;
	}
	return num;*/
}

int queuqEmpty(Queue* q) {
	if (q->_front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void queueDestory(Queue* q) {
	QNode* cur = q->_front;
	while (cur) {
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

//��ö�ͷ��Ԫ��
QDataType queueFront(Queue* q) {
	return q->_front->_data;
}
//��ö�β��Ԫ��
QDataType queueBack(Queue* q) {
	return q->_rear->_data;
}

//******************************************************************************************************

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


void test() {
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	while (queuqEmpty(&q) != 1) {
		printf("%d ", queueBack(&q));
		queuePop(&q);
	}
	printf("\n");
}

int main() {
	test();
	system("pause");
	return 0;
}
