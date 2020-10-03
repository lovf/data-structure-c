//sort1.c文件
#include "sort1.h"
#include "Stack1.h"
#include "queue1.h"
//
/*
时间复杂度:最坏O(n^2)  平均 O(n ^ 2) 最好O(n)
空间复杂度: O(1)
稳定性:稳定
数据敏感:
*/
//
//直接插入排序
void insertSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) { //假如这快的下标取到n-1的位置那么在于后面key=array[end+1],end+1就会越界.
		//新数据的插入
		//end:有序序列的最后一个位置
		int end = i;
		//key:待插入数据
		int key = array[end + 1];
		// 找到第一个小于等于key的位置
		while (end >= 0 && array[end] > key) {
			//当前数据向后移动
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

//希尔排序
void shellsort(int* array, int n) {
	//gap:代表步长  (步长是几代表元素被分成几组)
	int gap = n;
	while (gap > 1) {  //最后一次一定是一个1
		//多轮插入排序
		gap = gap / 3 + 1;
		//一轮的插入排序
		for (int i = 0; i < n - gap; i++) {
			//通过步长gap进行逻辑分组
			//组内进行插入排序
			//不同组元素交替进行排序
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key) {

				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}

//选择排序
//时间复杂度:最坏O(n ^ 2) 平均 O(n ^ 2) 最好O(n^2)
//空间复杂度 : O(1)
//稳定性 : 稳定
//数据敏感 :不敏感
void Selectsort1(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int start = i; //未排序的最左端
		int min = start;//最小值的位置
		for (int j = start + 1; j < n; j++) {
			if (array[min]>array[j])
				min = j;
		}
		Swap(array, start, min);
	}
}

void Swap(int* array, int left, int right) {
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}

void Selectsort2(int* array, int n) {

	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		//每一次选择最大值和最小值
		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (array[i] >= array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		//最小值放在begin
		Swap(array, begin, min);
		//如果最大值位置发生了改变,需要更新
		if (max == begin)
			max = min;
		//最大值放到end
		Swap(array, end, max);
		++begin;
		--end;
	}
}
//堆排序

//选择排序
//时间复杂度:最坏O(nlogn) 
//空间复杂度 : O(1)
//稳定性 : 不稳定
//数据敏感 :不敏感
void shiftDown(int* array, int n, int parent) {
	int child = 2 * parent + 1;
	while (child<n) {
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		if (array[child]>array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}


//1.建堆
//2.循环尾删
void heapSort(int* array, int n) {
	//最后一个非叶子节点开始
	for (int i = (n - 2) / 2; i >= 0; i--)  {
		shiftDown(array, n, i);
	}

	int size = n;
	while (size>0) {
		Swap(array, 0, size - 1);
		--size;
		shiftDown(array, size, 0);
	}
}

//冒泡排序
//选择排序
//时间复杂度:最坏O(n ^ 2) 平均 O(n ^ 2) 最好O(n)
//空间复杂度 : O(1)
//稳定性 : 稳定
//数据敏感 :敏感
void Bubblesort(int* array, int n) {
	while (n) {
		//对已经有序的序列,通过标签提前结束排序过程
		//flag: 1---->一轮排序过程中没有元素发生交换
		int flag = 1;
		int end = n;
		//一轮排序
		for (int i = 0; i<end - 1; i++) {
			//for (int i = 1; i<end; i++)
			//相邻元素进行比较
			if (array[i] > array[i + 1]) {
				Swap(array, i, i + 1);
				flag = 0;
				//Swap(array, i, i - 1);
			}
		}
		//没有发生元素交换,数据已经有序
		if (flag)
			break;
		--n;
	}
}



void Bubblesort2(int* array, int size) {
	//按照趟数来进行排序

	for (int i = 0; i < size; i++) { //第一趟
		for (int j = 0; j < size - 1 - i; j++) { //第一次比较的次数
			if (array[j + 1] < array[j]) {
				/*int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;*/
				Swap(array, j + 1, j);
			}
		}

	}

}
//快速排序

//三数取中
int getMid(int* arr, int begin, int end) {
	int mid = begin + (begin + end) / 2;
	//begin mid end 选择中间值的位置
	if (arr[begin] < arr[mid]) {
		//begin< mid
		if (arr[mid] < arr[end])
			return mid;
		else {
			//begin< mid,end<=mid
			if (arr[begin]>arr[end])
				return begin;
			else
				return end;
		}
	}
	else {
		if (arr[begin] < arr[mid])
			return mid;
		else {
			//begin >= mid; ens >= mid;
			if (arr[begin] < arr[mid])
				return begin;
			else
				return end;
		}
	}
}
//选择排序
//时间复杂度:最坏O(n ^ 2) 平均 O(nlogn) 最好O(nlogn)
//空间复杂度 : O(logn) 函数调用栈,极端情况就是O(n)
//稳定性 : 不稳定
//数据敏感 :敏感
//1. hora 划分
int partion1(int* arr, int begin, int end) {
	//三数取中
	//int mid = getMid(arr, begin, end);
	////交换 mid-->begin
	//Swap(arr,begin,mid);



	//选择基准值
	int key = arr[begin];
	int start = begin;//记录一下起始的位置
	//划分
	while (begin < end) { //只要没有相遇,就从后往前找第一个小于key的值 
		//就从后往前找第一个小于key的值 
		while (begin < end && arr[end] >= key)//这个循环走完可能找到了小于key的值 ,也可能begin和end相遇了.
			--end;
		//就从前向后找第一个大于key的值 
		while (begin < end && arr[begin] <= key)  //这个循环走完可能找到了大于key的值 ,也可能begin和end相遇了.
			++begin;
		//交换begin和end位置
		Swap(arr, begin, end);
	}
	//key和相遇的位置进行交换
	Swap(arr, start, begin); //相遇的位置begin或者是end
	//返回基准值的位置(实际就是相遇的位置)
	return begin;
}

void quick1(int* arr, int begin, int end) {
	if (begin >= end)
		return;
	//划分当前区间
	int keypos = partion1(arr, begin, end);
	//划分子区间
	quick1(arr, begin, keypos - 1);//先划分左边
	quick1(arr, keypos + 1, end); //划分右边
}

//问题1: 能否从前向后找第一个大的进行排序行不行?
//不行,最终可能会导致大数被划分的基准值的左边:最后一步基准值与相遇的位置进行交换时.
//不管递增递减都是从后面进行查找
//对于基准值在前面: (无论如何都是从后往前找)
//升序:先从后向前找小的,然后在从前往后找大的
//降序:先从后向前找大的,然后在从前往后找小的      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. 挖坑 划分
int partion2(int* arr, int begin, int end) {
	//三数取中
	//int mid = getMid(arr, begin, end);
	////交换 mid-->begin
	//Swap(arr,begin,mid);

	//选择基准值
	int key = arr[begin];
	int start = begin;//记录一下起始的位置
	//划分
	while (begin < end) { //只要没有相遇,就从后往前找第一个小于key的值 
		//就从后往前找第一个小于key的值 
		while (begin < end && arr[end] >= key)//这个循环走完可能找到了小于key的值 ,也可能begin和end相遇了.
			--end;
		//填坑 begin 位置的坑:
		arr[begin] = arr[end]; //去填起始位置的坑

		//就从前往后找第一个大于key的值 
		while (begin < end && arr[begin] <= key)  //这个循环走完可能找到了大于key的值 ,也可能begin和end相遇了.
			++begin;
		//填坑 end
		arr[end] = arr[begin];
	}
	//填充最后一个位置的坑:相遇的位置---->填充基准值
	//相遇位置的坑
	arr[begin] = key;
	//返回基准值得位置:
	return begin;
}

void quick2(int* arr, int begin, int end) {
	if (begin >= end)
		return;
	//划分当前区间
	int keypos = partion2(arr, begin, end);
	//划分子区间
	quick2(arr, begin, keypos - 1);//先划分左边
	quick2(arr, keypos + 1, end); //划分右边
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3.前后指针 划分
int partion3(int* arr, int begin, int end) {
	//三数取中
	//int mid = getMid(arr, begin, end);
	////交换 mid-->begin
	//Swap(arr,begin,mid);

	int prev = begin;//最后一个小于基准值的位置
	int cur = prev + 1;//表示下一个小于基准值的位置
	int key = arr[begin];
	while (cur <= end) {

		//新发现的小数据和尾指针的位置不连续,则中间含有大于基准值的数据,故进行交换,大数据向后移动,小数据向前移动
		if (arr[cur] < key && ++prev != cur)
			Swap(arr, prev, cur);

		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}

void quick3(int* arr, int begin, int end) {
	if (begin >= end)
		return;
	//划分当前区间
	int keypos = partion3(arr, begin, end);
	//划分子区间
	quick2(arr, begin, keypos - 1);//先划分左边
	quick2(arr, keypos + 1, end); //划分右边
}

//栈实现非递归快排
void quickSortNoR1(int* arr, int n) {
	Stack st;
	stackInit(&st, 10);
	//起始区间入栈 先入右再入左
	if (n > 1) {
		stackPush(&st, n - 1);
		stackPush(&st, 0);
	}
	//遍历栈,划分栈中的区间
	while (stackEmpty(&st) != 1) {
		//获取栈顶区间
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//划分
		int keyPos = partion3(arr, begin, end);
		//子区间入栈: 先入右,在入左
		//右: keyPos+1,end
		if (keyPos + 1 < end) {
			stackPush(&st, end);
			stackPush(&st, keyPos + 1);
		}
		//左: begin,keyPos-1 先入右,在入左
		if (begin < keyPos - 1) {
			stackPush(&st, keyPos - 1);
			stackPush(&st, begin);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//队列实现非递归快排
void quickSortNoR2(int* arr, int n) {
	Queue q;
	queueInit(&q);

	if (n>1) {
		queuePush(&q, 0);
		queuePush(&q, n - 1);
	}
	while (queueEmpty(&q) != 1) {
		int begin = queueFront(&q);
		queuePop(&q);
		int end = queueFront(&q);
		queuePop(&q);
		//划分
		int keyPos = partion3(arr, begin, end);
		//子区间入队
		//左: begin,keyPos-1 先入左,在入右
		if (begin < keyPos - 1) {
			queuePush(&q, begin);
			queuePush(&q, keyPos - 1);
		}
		if (keyPos + 1 < end) {
			queuePush(&q, keyPos + 1);
			queuePush(&q, end);
		}
	}
}
//归并排序
//时间复杂度:O(nlogn)
//空间复杂度 : O(n) 
//稳定性 : 稳定
//数据敏感 :不敏感 (不均匀划分)
//合并: 需要知道两个有序子序列的空间:[begin,mid],[mid+1,end] temp为辅助空间
void merge(int* arr, int begin, int mid, int end, int* tmp) {

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//查看是否有剩余的元素
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	//然后再将数据拷贝到原始空间
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void mergeSortR(int* arr, int begin, int end, int* tmp) {
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//int mid = (end + begin) / 2;

	//保证子区间有序,首先子区间的排序
	mergeSortR(arr, begin, mid, tmp);
	mergeSortR(arr, mid + 1, end, tmp);
	//合并有序子序
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	mergeSortR(arr, 0, n - 1, tmp);
	free(tmp);
}

//8.计数排序
//时间复杂度:
//空间复杂度 : 
//稳定性 : 稳定
//数据敏感 :不敏感 (不均匀划分) (指最好和最坏影响比较大)
void countSort(int* arr, int size) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	} //循环结束的时候就能找到最大值和最小值
	int range = max - min + 1;
	//开辅助空间进行计数
	int* countArr = (int*)malloc(sizeof(int)*range);
	//初始化为0
	memset(countArr, 0, sizeof(int)*range);
	//统计计数
	for (int i = 0; i < size; i++) {
		countArr[arr[i] - min]++;
	}
	//恢复数据
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (countArr[i]--) {
			arr[idx++] = i + min;
		}
	}
	free(countArr);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sort1.h文件
#pragma once 
//1.直接插入排序
void insertSort(int* arr, int n);
void testTime();

//2.希尔排序
void shellsort(int* arr, int n);
//3.选择排序
void Selectsort1(int* arr, int n);
void Swap(int* arr, int left, int right);
void Selectsort2(int* arr, int n);
//4.堆排序
void shiftDown(int* arr, int child, int parent);
void heapSort(int* arr, int n);
//5.冒泡排序
void Bubblesort(int* arr, int n);

//6.快速排序
//1>.hora法
void quick1(int* arr, int begin, int end);
int partion1(int* arr, int begin, int end);

//2>.挖坑法
//1.hora法
void quick2(int* arr, int begin, int end);
int partion2(int* arr, int begin, int end);

//3>.前后指针法(小的往前换,大的往后换)   
void quick3(int* arr, int begin, int end);
int partion3(int* arr, int begin, int end);
int getMid(int* arr, int begin, int end);
//栈实现非递归快排

void quickSortNoR1(int* arr, int n);
//队列实现非递归快排
void quickSortNoR2(int* arr, int n);


//7.归并排序
void merge(int* arr, int begin, int mid, int end, int* tmp);
void mergeSortR(int* arr, int begin, int end, int* tmp);
void mergeSort(int* arr, int n);

//8.计数排序
void countSort(int* arr, int size);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//queue.c文件
#include "queue1.h"
#include <stdio.h>
#include <stdlib.h>


void queueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

QNode* creatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//队尾入队
//思路：先让尾指针指向node，然后让尾指针向后移动移动一个元素（移动到node的位置）;
void queuePush(Queue* q, QDataType data) {
	QNode* node = creatNode(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		q->_rear->_next = node;
		q->_rear = node;

	}
	++q->_size;
}
//
//
//头删出队
void queuePop(Queue* q)  {
	if (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL) //删除之后是否为空表
			q->_rear = NULL;//如果q->_rear 不为空时,那么 就变成了野指针 .
		--q->_size;
	}
}

QDataType queueFront(Queue* q) {
	return q->_front->_data;
}

QDataType queueBack(Queue* q) {
	return q->_rear->_data;
}

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

int queueEmpty(Queue* q) {
	if (q->_front == NULL) {
		return 1;
	}
	return 0;
}

void queuePrint(Queue* q) {
	QNode* cur = q->_front;
	while (cur) {
		QNode* next = cur->_next;
		free(next);
		cur = cur->_next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//queue.h文件

#pragma once 
#include <stdlib.h>
#include <stdio.h>

typedef int QDataType;

typedef struct  QNode{
	struct	QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;


void queueInit(Queue* q);
QNode* creatNode(QDataType data);
//入队
void queuePush(Queue* q, QDataType data);
//出队
void queuePop(Queue* q);


QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);
int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queuePrint(Queue* q);

void queuqDestory(Queue* q);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Stack1.c文件


#include "Stack1.h"
void stackInit(Stack* st, size_t n) {
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;

}

void stackPush(Stack* st, Type data) { //入栈
	//检查容量
	if (st->_capacity == st->_size) {
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity*sizeof(Type));
	}
	//尾插
	st->_array[st->_size++] = data;
}

void stackPop(Stack* st) {  //出栈

	if (st->_size > 0) {
		--st->_size;
	}
}

Type stackTop(Stack* st) {//获得栈顶元素

	return st->_array[st->_size - 1];

}

size_t stackSize(Stack* st) {//栈的大小
	return st->_size;
}

size_t stackEmpty(Stack* st) {  //判断栈是否为空
	if (st->_size == 0) {
		return 1;
	}
	return 0;
}
void stackDestory(Stack* st) {
	free(st->_array);
	st->_capacity = st->_size = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//stack1.h文件
#pragma once
#include <stdio.h>
#include <stdlib.h>

//用顺序表来实现栈

typedef int Type;
typedef struct Stack {

	Type* _array;
	size_t _size;
	size_t _capacity;

}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Type data); //入栈
void stackPop(Stack* st);  //出栈
size_t stackTop(Stack* st); //获得栈顶元素

size_t stackSize(Stack* st); //栈的大小
size_t stackEmpty(Stack* st);  //判断栈是否为空
void stackDestory(Stack* st);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "sort1.h" 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

/*
时间复杂度:最坏O(n^2)  最好O(n)
空间复杂度: O(1)
稳定性:稳定性
数据敏感:
*/


void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {  //不能等于n-1,不然导致end+1越界了
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test1() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	printArray(array, size);

	printf("insertSort: \n");
	insertSort(array, size);
	printArray(array, size);
}

void test2() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	shellsort(array, size);
	printf("shellSort: \n");
	printArray(array, size);
}

//void testTime() {
//	srand((unsigned int)time(NULL));
//	int n;
//	scanf("%d",&n);
//	int* array = (int*)malloc(sizeof(int)*n);
//	for (int i = 0; i < n; i++) {
//		array[i] = rand();
//	}
//	//测随机数组的时间复杂度
//	size_t begin = clock();//clock() 代表时钟.
//	insertSort(array, n);
//	size_t end = clock();
//	printf("insertSort :%d\n", end - begin);
//
//	//测排好序数组的时间复杂度
//	begin = clock();
//	insertSort(array, n);
//	end = clock();
//	printf("sorted insertSort :%d\n", end - begin);
//}
//
//void test2() {
//	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
//	int size = sizeof(array) / sizeof(array[0]);
//
//	int* copy = (int*)malloc(sizeof(int)*size);
//	memcpy(copy, array, sizeof(int)*size);
//	printArray(array, size);
//	printf("insertSort: \n");
//	insertSort(array, size);
//	printArray(array, size);
//
//	printf("shellSort: \n");
//	insertSort(copy, size);
//	printArray(copy, size);
//
//}

void test3() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	Selectsort2(array, size);
	printf("SelectSort2: \n");
	printArray(array, size);
}

void test4() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	Bubblesort(array, size);
	printf("BubbleSort: \n");
	printArray(array, size);
}

void test5() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	heapSort(array, size);
	printf("heapSort: \n");
	printArray(array, size);
}

//void test6() {
//	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
//	int size = sizeof(array) / sizeof(array[0]);
//	heapSort(array, size);
//	printArray(array, size);
//}

void test7() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	int begin = 0;
	int end = size - 1;
	quick1(array, begin, end);
	printf("quick1Sort: \n");
	printArray(array, size);
}
void test8() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	int begin = 0;
	int end = size - 1;
	quick1(array, begin, end);
	printf("quick2Sort: \n");
	printArray(array, size);

}
void test9() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	int begin = 0;
	int end = size - 1;
	quick1(array, begin, end);
	printf("quick3Sort: \n");
	printArray(array, size);
}

void test10() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	quickSortNoR1(array, size);
	printf("quickSortNoR1: \n");
	printArray(array, size);


}
void test11() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	quickSortNoR2(array, size);
	printf("quickSortNoR2: \n");
	printArray(array, size);

}
void test12() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	mergeSort(array, size);
	printf("mergeSort: \n");
	printArray(array, size);
}

void test13() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	countSort(array, size);
	printf("countSort: \n");
	printArray(array, size);

}

int main() {

	//testTime();
	test1();
	test2();
	test3();
	test4();
	test5();
	//test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	system("color A");
	system("pause");
	return 0;
}




