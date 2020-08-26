//seqlist.c文件
#include "seqlist.h"
#include <stdlib.h>
#include <string.h>


//初始化
void seqListInit(seqlist* sl) {
	sl->_array = (DataType*)malloc(4 * sizeof(DataType));
	sl->_capacity = 4;
	sl->_size = 0;
}
//尾插
void seqListPushBack(seqlist* sl, DataType value) {
	/*checkCapacity(sl);
	sl->_array[sl->_size++] = value;*/
	seqListInsert(sl, sl->_size, value);
}
//尾删: 删除顺序表中的最后一个元素
void seqListPopBack(seqlist* sl) {
	//不需要释放空间
	/*if (sl->_size>0) {
		--sl->_size;
		}*/
	seqListErase(sl,sl->_size-1);
}
//头插
void seqListPushFront(seqlist* sl, DataType value) {
	checkCapacity(sl);
	//元素移动需要从后向前移动
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
//头删
void seqListPopFront(seqlist* sl) {
	//注意元素覆盖的问题
	//移动:从前向后移动
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

//在pos位置的前面插入一个数据value
void seqListInsert(seqlist* sl, size_t pos, DataType value) {

	//插入的位置必须合法
	if (pos <= sl->_size) {
		//检查容量是否够
		checkCapacity(sl);
		//移动元素
		size_t end = sl->_size;
		while (end > pos) {
			sl->_array[end] = sl->_array[end-1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}
}
//删除pos位置的元素
void seqListErase(seqlist* sl, size_t pos) {
	if (pos<sl->_size) {
	//删除元素: 从前向后移动
	//移动的位置: pos+1~size-1 --->pos~size-2
		size_t start = pos+1;
		while ( start< sl->_size) {
			sl->_array[start-1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}
//查找
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
	//增容 1.开更大空间 2.拷贝原有的内容 3.释放原有的空间
	//malloc 申请失败  返回NULL
	if (sl->_size == sl->_capacity) {
		sl->_capacity *= 2;
		//1.开更大的空间
		DataType* newArray = (DataType*)malloc(sl->_capacity*sizeof(DataType));
		//2.拷贝原来的内容
		memcpy(newArray,sl->_array,sl->_size*sizeof (DataType));
		//3.释放原来的空间
		free(sl->_array);
		sl->_array = newArray;
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);
	}
}
//seqlist.h文件
#include <stdio.h>
#pragma once 

//动态顺序表
typedef int DataType;
#define DataType int 
typedef struct seqlist{
	DataType* _array;
	//元素个数
	DataType _size;
	//容量: 当前可用的空间
	DataType _capacity;
}seqlist;
//顺序表初始化
void seqListInit(seqlist* sl);
//尾插
void seqListPushBack(seqlist* sl,DataType value);
//尾删
void seqListPopBack(seqlist* sl);
//头插
void seqListPushFront(seqlist* sl, DataType value);
//头删
void seqListPopFront(seqlist* sl);
//在pos位置的前面插入一个数据value
void seqListInsert(seqlist* sl,size_t pos,DataType value);
//删除pos位置的元素
void seqListErase(seqlist* sl, size_t pos);
//查找
int seqlistFind(seqlist* sl, DataType value);

void seqlistPrint(seqlist* sl);
//增容
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
	seqListInsert(&sl, 6, 8); //对应的是下标  下标前面的插入
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
//1.原地移除数组中的val,要求时间复杂度O(n),空间复杂度为O(1):
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
	int ret = removeNum(arr, size, value); //ret 代表返回的数组的长度
	printf("数组中的个数: %d\n",ret);
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//申请一块内存空间来进行处理.
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
	int ret = removeNum(arr, size, value); //ret 代表返回的数组的长度
	printf("数组中的个数: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("color A");
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2.删除排序数组中的重复项.
//方法1:
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
			//找到下一个不同元素的位置
			while (arr[i] == arr[j] && j < size)  
				++j;
				i = j;
				++j;
		}
	}
	//当j跳出数组的时候,最后一个元素肯定不重复,也要给复制过去
	if (i<size) {
		arr[idx++] = arr[i];
	}
	return idx;
}

int main() {
	int arr[] = { 1, 2, 4, 4, 6, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = removeDuplicate(arr, size); //ret 代表返回的数组的长度
	printf("不重复元素的个数为: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("color A");
	system("pause");
	return 0;
}
//方法2.常规思维 先将第一个元素找到,然后再依次与后面元素进行比较
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

	printf("不重复的元素个数为: %d\n", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
// 方法3:快慢指针
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
//3.合并两个有序数组 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr1[], int m, int arr2[], int n) {
	//未申请动态内存时, 从后向前进行比较
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
//4.旋转数组.  将数组中的元素向右移动k个元素的位置,其中k是一个非负数.
//实例1: 输入[1,2,3,4,5,6,7]和k等于3 输出: [5,6,71,2,3,4]
//方法1.
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
		printf("向右旋转%d次: ", i);
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
	printf("请输入向右旋转的次数: ");
	scanf("%d", &k);
	RightRotateN(arr, k, size);
	system("color A");
	system("pause");
	return 0;
}

方法2:
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
	reverseOne(arr, 0, size - 1 - k); //前半部分旋转
	reverseOne(arr, size - k,size-1); //后半部分旋转
	reverseOne(arr, 0, size - 1); //整体旋转
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
	printf("旋转3次的结果是: \n");
	Print(arr,size);
	system("color A");
	system("pause");
	return 0;
}
5.数组形式的整数加法.

求解思路: 
1>.先把数组变成整数
2>.然后在整数进行相加
3>.然后再把整数变成数组形式.
1200
+ 34
1234
从低位开始相加
和的每一位的结果: 加数的当前位的值 + 上一步的进位(0/1)
和的每一位结果的范围:0-->18(不考虑进位) + (0/1)  -->0~19
如果有进位,更新当前位的和与进位之后的和
相加完成之后,考虑最高位是否有进位,需要补1  999+1-->1000






































