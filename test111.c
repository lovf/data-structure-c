//Stack.c�ļ�
//#include "Stack.h"
//void stackInit(Stack* st, size_t n) {
//	st->_array = (Type*)malloc(sizeof(Type)* n);
//	st->_capacity = n;
//	st->_size = 0;
//
//}
//
//void stackPush(Stack* st, Type data) { //��ջ
//	//�������
//	if (st->_capacity == st->_size) {
//		st->_capacity *= 2;
//		st->_array = (Type*)realloc(st->_array, st->_capacity*sizeof(Type));
//	}
//	//β��
//	st->_array[st->_size++] = data;
//}
//
//void stackPop(Stack* st) {  //��ջ
//
//	if (st->_size > 0) {
//		--st->_size;
//	}
//}
//
//Type stackTop(Stack* st) {//���ջ��Ԫ��
//
//	return st->_array[st->_size - 1];
//
//}
//
//size_t stackSize(Stack* st) {//ջ�Ĵ�С
//	return st->_size;
//}
//
//size_t stackEmpty(Stack* st) {  //�ж�ջ�Ƿ�Ϊ��
//	if (st->_size == 0) {
//		return 1;
//	}
//	return 0;
//}
//void stackDestory(Stack* st) {
//	free(st->_array);
//	st->_capacity = st->_size = 0;
//}
//Stack.h�ļ�
//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//
////��˳�����ʵ��ջ
//
//typedef int Type;
//typedef struct Stack {
//
//	Type* _array;
//	size_t _size;
//	size_t _capacity;
//
//}Stack;
//
//void stackInit(Stack* st, size_t n);
//
//void stackPush(Stack* st, Type data); //��ջ
//void stackPop(Stack* st);  //��ջ
//size_t stackTop(Stack* st); //���ջ��Ԫ��
//
//size_t stackSize(Stack* st); //ջ�Ĵ�С
//size_t stackEmpty(Stack* st);  //�ж�ջ�Ƿ�Ϊ��
//void stackDestory(Stack* st);


//test.c�ļ�
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void test() {
	Stack st;
	stackInit(&st, 10);

	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (stackEmpty(&st) != 1) {
	
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}

int main () {

	test();

    system("color A");
    system ("pause");
    return 0;
}