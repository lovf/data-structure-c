//����: �Ƚ��ȳ�ԭ��
//���: β��
//����: ͷɾ
//ʵ��: ˳���,����
//˳���: β��O(1)  ͷɾO(n)
//������: β��O(n)  ͷɾO(1)
//       ����βָ��ĵ�����,β��O(1) ͷɾO(1)

//����ʵ�ַ�ʽ:  ����βָ��ĵ�����,β��O(1) ͷɾO(1)
//˳���,����
//ջ,����:Ԫ�صķ��ʲ�����˳����һ���Ĺ���
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

//���г�ʼ��
void queueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

//�����ڵ�
QNode* creatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QDataType));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//��Ӳ���---��β���
void queuePush(Queue* q, QDataType data) {
	QNode* node = creatNode(data);
	//�ն���
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		//����ֱ����βָ�����ӵ��½ڵ�
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}
//���Ӳ���---��ͷ����
void queuePop(Queue* q) {
	if (q->_front){
		QNode* next = q->_front->_next;
		//free(q->_front);
		q->_front = next;
		//ɾ��֮��Ϊ�ձ�
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}   
}
//��ȡ��ͷԪ��
QDataType queueFront(Queue* q) {
	return q->_front->_data;

}
//��ȡ��βԪ��
QDataType queueBack(Queue* q) {
	return q->_rear->_data;

}
//���еĴ�С
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
//�����пղ���
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


