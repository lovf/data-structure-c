//队列: 先进先出原则
//入队: 尾插
//出队: 头删
//实现: 顺序表,链表
//顺序表: 尾插O(1)  头删O(n)
//单链表: 尾插O(n)  头删O(1)
//       含有尾指针的单链表,尾插O(1) 头删O(1)

//常用实现方式:  含有尾指针的单链表,尾插O(1) 头删O(1)
//顺序表,链表
//栈,队列:元素的访问操作和顺序有一定的规则
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

//队列初始化
void queueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

//创建节点
QNode* creatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QDataType));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//入队操作---队尾入队
void queuePush(Queue* q, QDataType data) {
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		//插入直接让尾指针链接到新节点
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}
//出队操作---队头出队
void queuePop(Queue* q) {
	if (q->_front){
		QNode* next = q->_front->_next;
		//free(q->_front);
		q->_front = next;
		//删除之后为空表
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}   
}
//获取队头元素
QDataType queueFront(Queue* q) {
	return q->_front->_data;

}
//获取队尾元素
QDataType queueBack(Queue* q) {
	return q->_rear->_data;

}
//队列的大小
int queueSize(Queue* q) {
	/*int num = 0;
	QNode* cur = q->_front;
	while (cur) {
		++num;
		cur = cur->_next;
	}
	return num;*/
	return q->_size;
}
//队列判空操作
int queueEmpty(Queue* q) {
	if (q->_front == NULL)
		return 1;
	return 0;
}

void queueDestroy(Queue* q) {
	QNode* cur = q->_front;
	while (cur) {
		QNode* next = cur->_next;
		//free(cur);
		cur = next;
	}
	q->_rear = q->_front == NULL;
	q->_size = 0;
}


