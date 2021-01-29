//ջ���Ƚ����
//ʵ��:˳���,������(ͷ��,ͷɾ����)
//����ʵ��: stack��ʵ��ͨ��˳�����ʵ��,PushBack--->��ջ����  Popback---->��ջ����
//˳���, ������--->ʵ��ջ����O(1)����
//������ʽ: ��ȡջ��Ԫ���������ж� 


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��
void stackInit(Stack* st, size_t n) {
	st->_array = (Type*)malloc(sizeof(int)*n); //����ռ�
	st->_capacity = n;
	st->_size = 0;
}
//��ջ����
void stackPush(Stack* st,Type data) {
	//�������
	if (st->_size  == st->_capacity) {
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, sizeof(int)*st->_capacity);
	}
	//β�����
	st->_array[st->_size++] = data;//�����ȸ�_size��λ���ȷ���Ԫ���ڽ���++����
}
//��ջ����
void stackPop(Stack* st) {
	//βɾ����
	if (st->_size) {
		--st->_size;
	}
}
//��ȡջ��Ԫ��
//��ջ����
Type stackTop(Stack* st) {
	return st->_array[st->_size - 1];
}

//����ջ�Ĵ�С
size_t stackSize(Stack* st) {
	return st->_size;
}
//�пղ���
int stackEmpyt(Stack* st) {
	if (st->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
//����
void stackDestroy(Stack* st) {
	free(st->_array);
	st->_array = NULL;
	st->_capacity = st->_size = 0;
}
