//栈是先进后出
//实现:顺序表,单链表(头插,头删操作)
//常用实现: stack的实现通过顺序表来实现,PushBack--->入栈操作  Popback---->出栈操作
//顺序表, 单链表--->实现栈都是O(1)操作
//遍历方式: 获取栈顶元素来进行判定 


#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//初始化
void stackInit(Stack* st, size_t n) {
	st->_array = (Type*)malloc(sizeof(int)*n); //申请空间
	st->_capacity = n;
	st->_size = 0;
}
//入栈操作
void stackPush(Stack* st,Type data) {
	//检查容量
	if (st->_size  == st->_capacity) {
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, sizeof(int)*st->_capacity);
	}
	//尾插操作
	st->_array[st->_size++] = data;//代表先给_size的位置先放入元素在进行++操作
}
//出栈操作
void stackPop(Stack* st) {
	//尾删操作
	if (st->_size) {
		--st->_size;
	}
}
//获取栈顶元素
//入栈操作
Type stackTop(Stack* st) {
	return st->_array[st->_size - 1];
}

//返回栈的大小
size_t stackSize(Stack* st) {
	return st->_size;
}
//判空操作
int stackEmpyt(Stack* st) {
	if (st->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
//销毁
void stackDestroy(Stack* st) {
	free(st->_array);
	st->_array = NULL;
	st->_capacity = st->_size = 0;
}
