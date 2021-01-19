//定义代码:
//#pragma once
//#include <stdlib.h>
//#include <stdio.h>
//
//typedef int DataType;
//typedef struct seqlist{
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//}seqlist;
//void checkCapacity(seqlist* sl);
////链表初始化
//void seqlistInit(seqlist* sl);
//
////尾插:PushBack
//void seqlistPushBack(seqlist* sl, DataType value);
////尾删:PopBack
//void seqlistPopBack(seqlist* sl);
//
////头插:PushFront
//void seqlistPushFront(seqlist* sl, DataType value);
////头删:PopFront
//void seqlistPopFront(seqlist* sl);
//
////查找指定元素
//size_t Find(seqlist* sl, DataType value);
//
////打印顺序表
//void seqlistPrint(seqlist* sl);



#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

void checkCapacity(seqlist* sl) {
	//
	if (sl->_size == sl->_capacity) {
		sl->_capacity *= 2;
	////扩容量: 1.开空间  2.拷贝  3.释放原有空间
	//	DataType* newarray = (DataType*)malloc(sizeof(DataType)*sl->_capacity);
	//	memcpy(newarray, sl->_array, sizeof(DataType)*sl->_size);
	//	free(sl->_array);
	//	sl->_array = newarray;
		sl->_array = (DataType*)realloc(sl->_array,sizeof(DataType)*sl->_capacity);

	}
}
//链表初始化
void seqlistInit(seqlist* sl) {
	sl->_array = (DataType*)malloc(sizeof(DataType)* 4);
	sl->_capacity = 4;
	sl->_size = 0;
}

//尾插:PushBack
void seqlistPushBack(seqlist* sl, DataType value) {
	checkCapacity(sl);
	sl->_array[sl->_size++] = value;
}
//尾删:PopBack
void seqlistPopBack(seqlist* sl) {
	if (sl->_size) {
		--sl->_size;
	}
}

//头插:PushFront
void seqlistPushFront(seqlist* sl, DataType value) {
	checkCapacity(sl);
	size_t end = sl->_size;
	while (end > 0) {
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	++sl->_size;
}
//头删:PopFront
void seqlistPopFront(seqlist* sl) {
	if (sl->_size>0) {
		size_t start = 1;
		while (start < sl->_size) {
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	} 
}

//给pos位置的前面插入元素
void seqlistInsert(seqlist* sl, size_t pos, DataType value) {
	
	if (pos <= sl->_size) {
		checkCapacity(sl);
		size_t end = sl->_size;
		while (end > pos) {
			sl->_array[end] = sl->_array[end-1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}

}
//删除当前位置的元素
void seqlistErase(seqlist* sl, DataType pos) {
	if (pos < sl->_size) {
		size_t start = pos + 1;
		while (start < sl->_size) {
			sl->_array[start-1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}

//查找指定元素
size_t Find(seqlist* sl, DataType value) {
	for (int i = 0; i < sl->_size;++i) {
		if (sl->_array[i] == value) {
			return i;
		}
	
	}
	return -1;
}
//打印顺序表
void seqlistPrint(seqlist* sl) {

	for (int i = 0; i < sl->_size;i++) {
		printf("%d ", sl->_array[i]);
	}
	printf("\n");

}


//测试用例代码:
//#include "seqlist.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//
//void test1() {
//	seqlist sl;
//	seqlistInit(&sl);
//	seqlistPushBack(&sl, 1);
//	seqlistPushBack(&sl, 2);
//	seqlistPushBack(&sl, 3);
//	seqlistPushBack(&sl, 4);
//	seqlistPushBack(&sl, 5);
//	seqlistPushBack(&sl, 6);
//	seqlistPushBack(&sl, 7);
//	seqlistPushBack(&sl, 8);
//	seqlistPrint(&sl);
//
//	seqlistPopBack(&sl);
//	seqlistPrint(&sl);
//	seqlistPopBack(&sl);
//	seqlistPrint(&sl);
//	seqlistPopBack(&sl);
//	seqlistPrint(&sl);
//
//}
//
//void test2() {
//	seqlist sl;
//	seqlistInit(&sl);
//	seqlistPushFront(&sl, 1);
//	seqlistPushFront(&sl, 2);
//	seqlistPushFront(&sl, 3);
//	seqlistPushFront(&sl, 4);
//	seqlistPushFront(&sl, 5);
//	seqlistPrint(&sl);
//
//	/*seqlistPopFront(&sl);
//	seqlistPrint(&sl);
//	seqlistPopFront(&sl);
//	seqlistPrint(&sl);
//	seqlistPopFront(&sl);
//	seqlistPrint(&sl);*/
//
//
//	/*seqlistInsert(&sl, 2, 200);
//	seqlistPrint(&sl);
//
//	seqlistErase(&sl, 2);
//	seqlistPrint(&sl);*/
//
//	int ret = Find(&sl, 2);
//	printf("%d\n", ret);
//
//}
//int main() {
//
//	//test1();
//	test2();
//	system("pause");
//	return 0;
//}