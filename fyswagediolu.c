//旋转数组.  将数组中的元素向右移动k个元素的位置,其中k是一个非负数.
//实例1: 输入[1,2,3,4,5,6,7]和k等于3 输出: [5,6,71,2,3,4]
//方法1.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void RightRotateOne(int arr[],int size) {
	int end = size - 1;
	int start = arr[size-1];
	while (end>0) {
		arr[end] = arr[end - 1];
		--end;
	}
	arr[0] = start;
}

void RightRotateN(int arr[], int k1, int size) {
	for (int i = 1; i <= k1; i++) {
		RightRotateOne(arr, size);
		printf("向右旋转%d次: ",i);
		for (int i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main () {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 10, k1 = 0;
	printf("请输入向右旋转的次数: ");
	scanf("%d",&k);
	//k1 = k%size;
	RightRotateN(arr,k,size);
	//Print(arr, size);
    system("color A");
    system ("pause");
    return 0;
}
//方法2:
#include <stdio.h>
#include <stdlib.h>

void reverseOne(int arr[], int left, int right) {
	while (left < right) {
		int temp = arr[right];
		arr[right] = arr[left];
		arr[left] = temp;
		++left;
		--right;
	}
}

void reverseN(int arr[], int size, int k) {
	reverseOne(arr, 0, size - 1 - k);
	reverseOne(arr, size - k, size - 1);
	reverseOne(arr, 0, size - 1);
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
	reverseN(arr, size, k);
	Print(arr, size);
	system("color A");
	system("pause");
	return 0;
}