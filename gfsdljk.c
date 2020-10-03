//sort1.c�ļ�
#include "sort1.h"
#include "Stack1.h"
#include "queue1.h"
//
/*
ʱ�临�Ӷ�:�O(n^2)  ƽ�� O(n ^ 2) ���O(n)
�ռ临�Ӷ�: O(1)
�ȶ���:�ȶ�
��������:
*/
//
//ֱ�Ӳ�������
void insertSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) { //���������±�ȡ��n-1��λ����ô���ں���key=array[end+1],end+1�ͻ�Խ��.
		//�����ݵĲ���
		//end:�������е����һ��λ��
		int end = i;
		//key:����������
		int key = array[end + 1];
		// �ҵ���һ��С�ڵ���key��λ��
		while (end >= 0 && array[end] > key) {
			//��ǰ��������ƶ�
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

//ϣ������
void shellsort(int* array, int n) {
	//gap:������  (�����Ǽ�����Ԫ�ر��ֳɼ���)
	int gap = n;
	while (gap > 1) {  //���һ��һ����һ��1
		//���ֲ�������
		gap = gap / 3 + 1;
		//һ�ֵĲ�������
		for (int i = 0; i < n - gap; i++) {
			//ͨ������gap�����߼�����
			//���ڽ��в�������
			//��ͬ��Ԫ�ؽ����������
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

//ѡ������
//ʱ�临�Ӷ�:�O(n ^ 2) ƽ�� O(n ^ 2) ���O(n^2)
//�ռ临�Ӷ� : O(1)
//�ȶ��� : �ȶ�
//�������� :������
void Selectsort1(int* array, int n) {
	for (int i = 0; i < n; i++) {
		int start = i; //δ����������
		int min = start;//��Сֵ��λ��
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
		//ÿһ��ѡ�����ֵ����Сֵ
		int min = begin;
		int max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (array[i] >= array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		//��Сֵ����begin
		Swap(array, begin, min);
		//������ֵλ�÷����˸ı�,��Ҫ����
		if (max == begin)
			max = min;
		//���ֵ�ŵ�end
		Swap(array, end, max);
		++begin;
		--end;
	}
}
//������

//ѡ������
//ʱ�临�Ӷ�:�O(nlogn) 
//�ռ临�Ӷ� : O(1)
//�ȶ��� : ���ȶ�
//�������� :������
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


//1.����
//2.ѭ��βɾ
void heapSort(int* array, int n) {
	//���һ����Ҷ�ӽڵ㿪ʼ
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

//ð������
//ѡ������
//ʱ�临�Ӷ�:�O(n ^ 2) ƽ�� O(n ^ 2) ���O(n)
//�ռ临�Ӷ� : O(1)
//�ȶ��� : �ȶ�
//�������� :����
void Bubblesort(int* array, int n) {
	while (n) {
		//���Ѿ����������,ͨ����ǩ��ǰ�����������
		//flag: 1---->һ�����������û��Ԫ�ط�������
		int flag = 1;
		int end = n;
		//һ������
		for (int i = 0; i<end - 1; i++) {
			//for (int i = 1; i<end; i++)
			//����Ԫ�ؽ��бȽ�
			if (array[i] > array[i + 1]) {
				Swap(array, i, i + 1);
				flag = 0;
				//Swap(array, i, i - 1);
			}
		}
		//û�з���Ԫ�ؽ���,�����Ѿ�����
		if (flag)
			break;
		--n;
	}
}



void Bubblesort2(int* array, int size) {
	//������������������

	for (int i = 0; i < size; i++) { //��һ��
		for (int j = 0; j < size - 1 - i; j++) { //��һ�αȽϵĴ���
			if (array[j + 1] < array[j]) {
				/*int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;*/
				Swap(array, j + 1, j);
			}
		}

	}

}
//��������

//����ȡ��
int getMid(int* arr, int begin, int end) {
	int mid = begin + (begin + end) / 2;
	//begin mid end ѡ���м�ֵ��λ��
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
//ѡ������
//ʱ�临�Ӷ�:�O(n ^ 2) ƽ�� O(nlogn) ���O(nlogn)
//�ռ临�Ӷ� : O(logn) ��������ջ,�����������O(n)
//�ȶ��� : ���ȶ�
//�������� :����
//1. hora ����
int partion1(int* arr, int begin, int end) {
	//����ȡ��
	//int mid = getMid(arr, begin, end);
	////���� mid-->begin
	//Swap(arr,begin,mid);



	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;//��¼һ����ʼ��λ��
	//����
	while (begin < end) { //ֻҪû������,�ʹӺ���ǰ�ҵ�һ��С��key��ֵ 
		//�ʹӺ���ǰ�ҵ�һ��С��key��ֵ 
		while (begin < end && arr[end] >= key)//���ѭ����������ҵ���С��key��ֵ ,Ҳ����begin��end������.
			--end;
		//�ʹ�ǰ����ҵ�һ������key��ֵ 
		while (begin < end && arr[begin] <= key)  //���ѭ����������ҵ��˴���key��ֵ ,Ҳ����begin��end������.
			++begin;
		//����begin��endλ��
		Swap(arr, begin, end);
	}
	//key��������λ�ý��н���
	Swap(arr, start, begin); //������λ��begin������end
	//���ػ�׼ֵ��λ��(ʵ�ʾ���������λ��)
	return begin;
}

void quick1(int* arr, int begin, int end) {
	if (begin >= end)
		return;
	//���ֵ�ǰ����
	int keypos = partion1(arr, begin, end);
	//����������
	quick1(arr, begin, keypos - 1);//�Ȼ������
	quick1(arr, keypos + 1, end); //�����ұ�
}

//����1: �ܷ��ǰ����ҵ�һ����Ľ��������в���?
//����,���տ��ܻᵼ�´��������ֵĻ�׼ֵ�����:���һ����׼ֵ��������λ�ý��н���ʱ.
//���ܵ����ݼ����ǴӺ�����в���
//���ڻ�׼ֵ��ǰ��: (������ζ��ǴӺ���ǰ��)
//����:�ȴӺ���ǰ��С��,Ȼ���ڴ�ǰ�����Ҵ��
//����:�ȴӺ���ǰ�Ҵ��,Ȼ���ڴ�ǰ������С��      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2. �ڿ� ����
int partion2(int* arr, int begin, int end) {
	//����ȡ��
	//int mid = getMid(arr, begin, end);
	////���� mid-->begin
	//Swap(arr,begin,mid);

	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;//��¼һ����ʼ��λ��
	//����
	while (begin < end) { //ֻҪû������,�ʹӺ���ǰ�ҵ�һ��С��key��ֵ 
		//�ʹӺ���ǰ�ҵ�һ��С��key��ֵ 
		while (begin < end && arr[end] >= key)//���ѭ����������ҵ���С��key��ֵ ,Ҳ����begin��end������.
			--end;
		//��� begin λ�õĿ�:
		arr[begin] = arr[end]; //ȥ����ʼλ�õĿ�

		//�ʹ�ǰ�����ҵ�һ������key��ֵ 
		while (begin < end && arr[begin] <= key)  //���ѭ����������ҵ��˴���key��ֵ ,Ҳ����begin��end������.
			++begin;
		//��� end
		arr[end] = arr[begin];
	}
	//������һ��λ�õĿ�:������λ��---->����׼ֵ
	//����λ�õĿ�
	arr[begin] = key;
	//���ػ�׼ֵ��λ��:
	return begin;
}

void quick2(int* arr, int begin, int end) {
	if (begin >= end)
		return;
	//���ֵ�ǰ����
	int keypos = partion2(arr, begin, end);
	//����������
	quick2(arr, begin, keypos - 1);//�Ȼ������
	quick2(arr, keypos + 1, end); //�����ұ�
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3.ǰ��ָ�� ����
int partion3(int* arr, int begin, int end) {
	//����ȡ��
	//int mid = getMid(arr, begin, end);
	////���� mid-->begin
	//Swap(arr,begin,mid);

	int prev = begin;//���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;//��ʾ��һ��С�ڻ�׼ֵ��λ��
	int key = arr[begin];
	while (cur <= end) {

		//�·��ֵ�С���ݺ�βָ���λ�ò�����,���м京�д��ڻ�׼ֵ������,�ʽ��н���,����������ƶ�,С������ǰ�ƶ�
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
	//���ֵ�ǰ����
	int keypos = partion3(arr, begin, end);
	//����������
	quick2(arr, begin, keypos - 1);//�Ȼ������
	quick2(arr, keypos + 1, end); //�����ұ�
}

//ջʵ�ַǵݹ����
void quickSortNoR1(int* arr, int n) {
	Stack st;
	stackInit(&st, 10);
	//��ʼ������ջ ������������
	if (n > 1) {
		stackPush(&st, n - 1);
		stackPush(&st, 0);
	}
	//����ջ,����ջ�е�����
	while (stackEmpty(&st) != 1) {
		//��ȡջ������
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//����
		int keyPos = partion3(arr, begin, end);
		//��������ջ: ������,������
		//��: keyPos+1,end
		if (keyPos + 1 < end) {
			stackPush(&st, end);
			stackPush(&st, keyPos + 1);
		}
		//��: begin,keyPos-1 ������,������
		if (begin < keyPos - 1) {
			stackPush(&st, keyPos - 1);
			stackPush(&st, begin);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����ʵ�ַǵݹ����
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
		//����
		int keyPos = partion3(arr, begin, end);
		//���������
		//��: begin,keyPos-1 ������,������
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
//�鲢����
//ʱ�临�Ӷ�:O(nlogn)
//�ռ临�Ӷ� : O(n) 
//�ȶ��� : �ȶ�
//�������� :������ (�����Ȼ���)
//�ϲ�: ��Ҫ֪���������������еĿռ�:[begin,mid],[mid+1,end] tempΪ�����ռ�
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
	//�鿴�Ƿ���ʣ���Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	//Ȼ���ٽ����ݿ�����ԭʼ�ռ�
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void mergeSortR(int* arr, int begin, int end, int* tmp) {
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	//int mid = (end + begin) / 2;

	//��֤����������,���������������
	mergeSortR(arr, begin, mid, tmp);
	mergeSortR(arr, mid + 1, end, tmp);
	//�ϲ���������
	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	mergeSortR(arr, 0, n - 1, tmp);
	free(tmp);
}

//8.��������
//ʱ�临�Ӷ�:
//�ռ临�Ӷ� : 
//�ȶ��� : �ȶ�
//�������� :������ (�����Ȼ���) (ָ��ú��Ӱ��Ƚϴ�)
void countSort(int* arr, int size) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	} //ѭ��������ʱ������ҵ����ֵ����Сֵ
	int range = max - min + 1;
	//�������ռ���м���
	int* countArr = (int*)malloc(sizeof(int)*range);
	//��ʼ��Ϊ0
	memset(countArr, 0, sizeof(int)*range);
	//ͳ�Ƽ���
	for (int i = 0; i < size; i++) {
		countArr[arr[i] - min]++;
	}
	//�ָ�����
	int idx = 0;
	for (int i = 0; i < range; i++) {
		while (countArr[i]--) {
			arr[idx++] = i + min;
		}
	}
	free(countArr);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sort1.h�ļ�
#pragma once 
//1.ֱ�Ӳ�������
void insertSort(int* arr, int n);
void testTime();

//2.ϣ������
void shellsort(int* arr, int n);
//3.ѡ������
void Selectsort1(int* arr, int n);
void Swap(int* arr, int left, int right);
void Selectsort2(int* arr, int n);
//4.������
void shiftDown(int* arr, int child, int parent);
void heapSort(int* arr, int n);
//5.ð������
void Bubblesort(int* arr, int n);

//6.��������
//1>.hora��
void quick1(int* arr, int begin, int end);
int partion1(int* arr, int begin, int end);

//2>.�ڿӷ�
//1.hora��
void quick2(int* arr, int begin, int end);
int partion2(int* arr, int begin, int end);

//3>.ǰ��ָ�뷨(С����ǰ��,�������)   
void quick3(int* arr, int begin, int end);
int partion3(int* arr, int begin, int end);
int getMid(int* arr, int begin, int end);
//ջʵ�ַǵݹ����

void quickSortNoR1(int* arr, int n);
//����ʵ�ַǵݹ����
void quickSortNoR2(int* arr, int n);


//7.�鲢����
void merge(int* arr, int begin, int mid, int end, int* tmp);
void mergeSortR(int* arr, int begin, int end, int* tmp);
void mergeSort(int* arr, int n);

//8.��������
void countSort(int* arr, int size);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//queue.c�ļ�
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
//��β���
//˼·������βָ��ָ��node��Ȼ����βָ������ƶ��ƶ�һ��Ԫ�أ��ƶ���node��λ�ã�;
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
//ͷɾ����
void queuePop(Queue* q)  {
	if (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL) //ɾ��֮���Ƿ�Ϊ�ձ�
			q->_rear = NULL;//���q->_rear ��Ϊ��ʱ,��ô �ͱ����Ұָ�� .
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
//queue.h�ļ�

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
//���
void queuePush(Queue* q, QDataType data);
//����
void queuePop(Queue* q);


QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);
int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queuePrint(Queue* q);

void queuqDestory(Queue* q);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Stack1.c�ļ�


#include "Stack1.h"
void stackInit(Stack* st, size_t n) {
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;

}

void stackPush(Stack* st, Type data) { //��ջ
	//�������
	if (st->_capacity == st->_size) {
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity*sizeof(Type));
	}
	//β��
	st->_array[st->_size++] = data;
}

void stackPop(Stack* st) {  //��ջ

	if (st->_size > 0) {
		--st->_size;
	}
}

Type stackTop(Stack* st) {//���ջ��Ԫ��

	return st->_array[st->_size - 1];

}

size_t stackSize(Stack* st) {//ջ�Ĵ�С
	return st->_size;
}

size_t stackEmpty(Stack* st) {  //�ж�ջ�Ƿ�Ϊ��
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
//stack1.h�ļ�
#pragma once
#include <stdio.h>
#include <stdlib.h>

//��˳�����ʵ��ջ

typedef int Type;
typedef struct Stack {

	Type* _array;
	size_t _size;
	size_t _capacity;

}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Type data); //��ջ
void stackPop(Stack* st);  //��ջ
size_t stackTop(Stack* st); //���ջ��Ԫ��

size_t stackSize(Stack* st); //ջ�Ĵ�С
size_t stackEmpty(Stack* st);  //�ж�ջ�Ƿ�Ϊ��
void stackDestory(Stack* st);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "sort1.h" 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

/*
ʱ�临�Ӷ�:�O(n^2)  ���O(n)
�ռ临�Ӷ�: O(1)
�ȶ���:�ȶ���
��������:
*/


void printArray(int* array, int n) {
	for (int i = 0; i < n; i++) {  //���ܵ���n-1,��Ȼ����end+1Խ����
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
//	//����������ʱ�临�Ӷ�
//	size_t begin = clock();//clock() ����ʱ��.
//	insertSort(array, n);
//	size_t end = clock();
//	printf("insertSort :%d\n", end - begin);
//
//	//���ź��������ʱ�临�Ӷ�
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




