//seqlist.c�ļ�
#include "seqlist.h"
#include <stdlib.h>
#include <string.h>


//��ʼ��
void seqListInit(seqlist* sl) {
	sl->_array = (DataType*)malloc(4 * sizeof(DataType));
	sl->_capacity = 4;
	sl->_size = 0;
}
//β��
void seqListPushBack(seqlist* sl, DataType value) {
	/*checkCapacity(sl);
	sl->_array[sl->_size++] = value;*/
	seqListInsert(sl, sl->_size, value);
}
//βɾ: ɾ��˳����е����һ��Ԫ��
void seqListPopBack(seqlist* sl) {
	//����Ҫ�ͷſռ�
	/*if (sl->_size>0) {
		--sl->_size;
		}*/
	seqListErase(sl,sl->_size-1);
}
//ͷ��
void seqListPushFront(seqlist* sl, DataType value) {
	checkCapacity(sl);
	//Ԫ���ƶ���Ҫ�Ӻ���ǰ�ƶ�
	//int end = sl->_size;
	size_t end = sl->_size;
	while (end > 0) {
		sl->_array[end] = sl->_array[end-1];
		--end;
	}
	sl->_array[0] = value;
	++sl->_size;
	seqListInsert(sl,0,value);
}
//ͷɾ
void seqListPopFront(seqlist* sl) {
	//ע��Ԫ�ظ��ǵ�����
	//�ƶ�:��ǰ����ƶ�
	if (sl->_size) {
		size_t start = 1;
		//1->sl->_size-1 ---> 0~sl->-size-2
		while (start<sl->_size) {
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
	seqListErase(sl, 0);
}

//��posλ�õ�ǰ�����һ������value
void seqListInsert(seqlist* sl, size_t pos, DataType value) {

	//�����λ�ñ���Ϸ�
	if (pos <= sl->_size) {
		//��������Ƿ�
		checkCapacity(sl);
		//�ƶ�Ԫ��
		size_t end = sl->_size;
		while (end > pos) {
			sl->_array[end] = sl->_array[end-1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}
}
//ɾ��posλ�õ�Ԫ��
void seqListErase(seqlist* sl, size_t pos) {
	if (pos<sl->_size) {
	//ɾ��Ԫ��: ��ǰ����ƶ�
	//�ƶ���λ��: pos+1~size-1 --->pos~size-2
		size_t start = pos+1;
		while ( start< sl->_size) {
			sl->_array[start-1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}
//����
int seqlistFind(seqlist* sl, DataType value) {
	for (int i = 0; i < sl->_size;i++) {
		if (sl->_array[i] == value) {
			return i;
		}
		else {
			return -1;
		}

	}
}

void seqlistPrint(seqlist* sl) {
	for (int i = 0; i < sl->_size; i++) {
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}
void checkCapacity(seqlist* sl) {
	//���� 1.������ռ� 2.����ԭ�е����� 3.�ͷ�ԭ�еĿռ�
	//malloc ����ʧ��  ����NULL
	if (sl->_size == sl->_capacity) {
		sl->_capacity *= 2;
		//1.������Ŀռ�
		DataType* newArray = (DataType*)malloc(sl->_capacity*sizeof(DataType));
		//2.����ԭ��������
		memcpy(newArray,sl->_array,sl->_size*sizeof (DataType));
		//3.�ͷ�ԭ���Ŀռ�
		free(sl->_array);
		sl->_array = newArray;
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);
	}
}
//seqlist.h�ļ�
#include <stdio.h>
#pragma once 

//��̬˳���
typedef int DataType;
#define DataType int 
typedef struct seqlist{
	DataType* _array;
	//Ԫ�ظ���
	DataType _size;
	//����: ��ǰ���õĿռ�
	DataType _capacity;
}seqlist;
//˳����ʼ��
void seqListInit(seqlist* sl);
//β��
void seqListPushBack(seqlist* sl,DataType value);
//βɾ
void seqListPopBack(seqlist* sl);
//ͷ��
void seqListPushFront(seqlist* sl, DataType value);
//ͷɾ
void seqListPopFront(seqlist* sl);
//��posλ�õ�ǰ�����һ������value
void seqListInsert(seqlist* sl,size_t pos,DataType value);
//ɾ��posλ�õ�Ԫ��
void seqListErase(seqlist* sl, size_t pos);
//����
int seqlistFind(seqlist* sl, DataType value);

void seqlistPrint(seqlist* sl);
//����
void checkCapacity(seqlist* sl);


#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

void test1() {
	seqlist sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqlistPrint(&sl);
	seqListPopBack(&sl);
	seqlistPrint(&sl);
	seqListPopBack(&sl);
	seqlistPrint(&sl);
	seqListPopBack(&sl);
	seqlistPrint(&sl);
}
void test2() {

	seqlist sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	for (int i = 0; i < 10000;i++) {
		seqListPushFront(&sl,i);
	}
	seqlistPrint(&sl);

}
void test3() {
	seqlist sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqlistPrint(&sl);

	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);

}

void test4() {
	seqlist sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 3);
	seqListPushFront(&sl, 2);
	seqListPushFront(&sl, 1);
	seqlistPrint(&sl);
	seqListPushBack(&sl, 4);
	seqlistPrint(&sl);
	seqListPushBack(&sl, 5);
	seqlistPrint(&sl);
	seqListPushBack(&sl, 7);
	seqlistPrint(&sl);
	seqListPushBack(&sl, 9);
	seqlistPrint(&sl);
	seqListPushBack(&sl, 10);
	seqlistPrint(&sl);
	seqListInsert(&sl, 6, 8); //��Ӧ�����±�  �±�ǰ��Ĳ���
	seqlistPrint(&sl);
	seqListInsert(&sl, 5, 6);
	seqlistPrint(&sl);
}
void test5() {
	seqlist sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 3);
	seqListPushFront(&sl, 2);
	seqListPushFront(&sl, 1);
	seqListPushBack(&sl, 4);
	seqListPushBack(&sl, 5);
	seqlistPrint(&sl);

	seqListPopFront(&sl);
	seqlistPrint(&sl);
	seqListPopFront(&sl);
	seqlistPrint(&sl);

	seqListPopBack(&sl);
	seqlistPrint(&sl);
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test5();
	system("color A");
    system ("pause");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.ԭ���Ƴ������е�val,Ҫ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�ΪO(1):
#include <stdio.h>
#include <stdlib.h>

int removeNum(int arr[],int size,int value) {
	int i = 0,idx=0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != value) {
			arr[idx] = arr[i];
			++idx;
		}
	}
	return idx;
}

int main () {
	int arr[] = { 1, 2, 4, 7, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int value = 4;
	int ret = removeNum(arr, size, value); //ret �����ص�����ĳ���
	printf("�����еĸ���: %d\n",ret);
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����һ���ڴ�ռ������д���.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeNum(int arr[], int size, int value) {
	int* Newarr = (int*)malloc(size*sizeof(int));
	int i = 0, idx = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != value) {
			Newarr[idx++] = arr[i];
		}
	}
	memcpy(arr,Newarr,sizeof(int)*idx);
	free(Newarr);
	return idx;
}

int main() {
	int arr[] = { 1, 2, 4, 7, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int value = 4;
	int ret = removeNum(arr, size, value); //ret �����ص�����ĳ���
	printf("�����еĸ���: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("color A");
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2.ɾ�����������е��ظ���.
//����1:
#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(int arr[],int size) {
	int j = 1, i = 0, idx = 0;
	while (j < size) {
		arr[idx++] = arr[i];
		if (arr[i] != arr[j]) {
			++i;
			++j;		
		} else {
			//�ҵ���һ����ͬԪ�ص�λ��
			while (arr[i] == arr[j] && j < size)  
				++j;
				i = j;
				++j;
		}
	}
	//��j���������ʱ��,���һ��Ԫ�ؿ϶����ظ�,ҲҪ�����ƹ�ȥ
	if (i<size) {
		arr[idx++] = arr[i];
	}
	return idx;
}

int main() {
	int arr[] = { 1, 2, 4, 4, 6, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = removeDuplicate(arr, size); //ret �����ص�����ĳ���
	printf("���ظ�Ԫ�صĸ���Ϊ: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("color A");
	system("pause");
	return 0;
}
//����2.����˼ά �Ƚ���һ��Ԫ���ҵ�,Ȼ�������������Ԫ�ؽ��бȽ�
#include <stdio.h>
#include <stdlib.h>

int  removeDuplicate(int nums[], int size) {
	if (size == 0) {
		return 0;
	}
	int temp = nums[0];
	int idx = 1;
	for (int i = 1; i < size; i++){
		if (nums[i] != temp) {
			temp = nums[i];
			nums[idx++] = temp;
		}
	}
	return idx;
}

int main() {
	int nums[] = { 1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicate(nums, size);

	printf("���ظ���Ԫ�ظ���Ϊ: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
// ����3:����ָ��
#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(int nums[], int size) {

	int s = 0;
	for (int f = 1; f < size; f++) {
		if (nums[s] != nums[f]) {
			nums[++s] = nums[f];
		}
	}
	return s + 1;
}

void Print(int nums[], int ret) {
	for (int i = 0; i < ret; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main() {
	int nums[] = { 1, 1, 2, 3, 4, 4, 5, 6 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicate(nums, size);
	Print(nums, ret);
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3.�ϲ������������� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr1[], int m, int arr2[], int n) {
	//δ���붯̬�ڴ�ʱ, �Ӻ���ǰ���бȽ�
		int idx = m + n - 1;
	while (m > 0 && n > 0) {
		if (arr1[m - 1] >= arr2[n - 1]) {
			arr1[idx--] = arr1[m - 1];
			--m;
		}
		else {
			arr1[idx--] = arr2[n - 1];
			--n;
		}
	}
	if (n > 0) {
		memcpy(arr1, arr2, sizeof(int)*n);
	}
	for (int i = 0; i < 12; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

int main() {
	int arr1[] = { 1, 3, 3, 5, 7, 7 };
	int arr2[] = { 2, 4, 4, 5, 8, 9 };

	merge(arr1, 6, arr2, 6);
	system("color A");
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr1[], int m, int arr2[], int n) {
	int* newA = (int*)malloc(sizeof(int)*(m + n));
	int idx = 0;
	int n1 = 0;
	int n2 = 0;

	while (n1 < m && n2 < n) {
		if (arr1[n1] <= arr2[n2]) {
			newA[idx++] = arr1[n1++];
		}
		else {
			newA[idx++] = arr2[n2++];
		}
	}
	if (n1 < m)
		memcpy(newA + idx, arr1 + n1, sizeof(int)*(m - n1));
	if (n2 < n)
		memcpy(newA + idx, arr2 + n2, sizeof(int)*(n - n2));
	memcpy(arr1, newA, sizeof(int)*(m + n));
	free(newA);

}
void Print(int arr1[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

}

int main() {
	int arr1[] = { 1, 3, 3, 5, 7, 7 };
	int arr2[] = { 2, 4, 4, 5, 8, 9 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	merge(arr1, size1, arr2, size2);
	Print(arr1, size1 + size2);
	system("color A");
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//4.��ת����.  �������е�Ԫ�������ƶ�k��Ԫ�ص�λ��,����k��һ���Ǹ���.
//ʵ��1: ����[1,2,3,4,5,6,7]��k����3 ���: [5,6,71,2,3,4]
//����1.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void RightRotateOne(int arr[], int size) {
	int end = size - 1;
	int start = arr[size - 1];
	while (end > 0) {
		arr[end] = arr[end - 1];
		--end;
	}
	arr[0] = start;
}

void RightRotateN(int arr[], int k1, int size) {
	for (int i = 1; i <= k1; i++) {
		RightRotateOne(arr, size);
		printf("������ת%d��: ", i);
		for (int i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	printf("������������ת�Ĵ���: ");
	scanf("%d", &k);
	RightRotateN(arr, k, size);
	system("color A");
	system("pause");
	return 0;
}

����2:
#include <stdio.h>
#include <stdlib.h>

void reverseOne(int arr[],int left,int right) {
	while (left<right) {
		int temp = arr[right];
		arr[right] = arr[left];
		arr[left] = temp;
		++left;
		--right;
	}
}

void reverseN(int arr[],int size,int k) {
	reverseOne(arr, 0, size - 1 - k); //ǰ�벿����ת
	reverseOne(arr, size - k,size-1); //��벿����ת
	reverseOne(arr, 0, size - 1); //������ת
}
void Print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	reverseN(arr,size,k);
	printf("��ת3�εĽ����: \n");
	Print(arr,size);
	system("color A");
	system("pause");
	return 0;
}
5.������ʽ�������ӷ�.

���˼·: 
1>.�Ȱ�����������
2>.Ȼ���������������
3>.Ȼ���ٰ��������������ʽ.
1200
+ 34
1234
�ӵ�λ��ʼ���
�͵�ÿһλ�Ľ��: �����ĵ�ǰλ��ֵ + ��һ���Ľ�λ(0/1)
�͵�ÿһλ����ķ�Χ:0-->18(�����ǽ�λ) + (0/1)  -->0~19
����н�λ,���µ�ǰλ�ĺ����λ֮��ĺ�
������֮��,�������λ�Ƿ��н�λ,��Ҫ��1  999+1-->1000






































