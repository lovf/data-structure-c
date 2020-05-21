//问题1:
在一个有序的数组中,找到只出现一次的数字并返回下标
方法1.异或
#include <stdio.h>
#include <stdlib.h>

int  findNumber(int arr[],int size) {
	int i = 0;
	int ret = 0;
	for (int i = 0; i < size - 1;i++) {
		ret = ret^arr[i];
	}
	return ret;
}

int main() {
	int arr[] = { 1, 1, 3, 5, 5, 6, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret=findNumber(arr,size);
	printf("%d\n",ret);
	system("pause");
	return 0;Kc
}
*******************************************************************************************************
方法2.使用递归
#include <stdio.h>
#include <stdlib.h>

int findNumber(int* arr,int size) {
	return size == 1 ? arr[0] : findNumber(arr + 1, size - 1) ^ arr[0];
}

int main() {
	int arr[] = { 1, 2, 4, 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = findNumber(arr, size);
	printf("只出现一次的数字是: %d\n",ret);
	system("pause");
	return 0;
}

方法3.创建一个新的数组,然后以原来数组的值作为作为新数组的返回下标,(此方法存在一定的弊端,数组的范围必须很大)

#include <stdio.h>
#include <stdlib.h>

int findNumber(int arr[],int size) {
	int oneFind[1024] = {0};
	for (int i = 0; i < size;i++){
		oneFind[arr[i]]++;
	}
	for (int i = 0; i < 1024; i++) {
		if (oneFind[i] == 1) {
			return i;
		}
	}
}
int main() {
	int arr[] = { 1, 1, 3, 10,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = findNumber(arr, size);
	printf("只出现一次的数字是: %d\n", ret);
	system("pause");
	return 0;
}
*****************************************************************************************************
问题2:合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
说明 :
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例 :
输入 :
	nums1 = [1, 2, 3, 0, 0, 0], m = 3
	nums2 = [2, 5, 6], n = 3

输出 : [1, 2, 2, 3, 5, 6]


方法1.从后往前进行判定:

#include <stdio.h>
#include <stdlib.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int idx = m + n - 1;
	while (m > 0 && n > 0) {
		if (nums1[m - 1] >= nums2[n - 1]) {
			nums1[idx--] = nums1[m - 1];
			--m;
		} else {
			nums1[idx--] = nums2[n - 1];
			--n;
		}
	}
	if (n > 0) {
		memcpy(nums1, nums2, sizeof(int)*n);
	}
}

int main() { 
	int nums1[] = { 1, 2, 3 };
	int nums2[] = { 1, 4, 5 };
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int size2 = sizeof(nums1) / sizeof(nums1[0]);
	merge(nums1, size1, 3, nums2, size2, 3);
	for (int i = 0; i < size1 + size2 - 1;i++) {
	
		printf("%d ",nums1[i]);
	
	}

	system("pause");
	return 0;

}
********************************************************************************************************
从前往后进行判定
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int* newA = (int*)malloc(sizeof(int)*(m + n));
	int idx = 0;
	int n1 = 0;
	int n2 = 0;
	while (n1<m && n > n2) {
		if (nums1[n1] <= nums2[n2]) {
			newA[idx++] = nums1[n1++];
		}
		else {
			newA[idx++] = nums2[n2++];
		}
	}
	if (n1 < m) {
		memcpy(newA + idx, nums1 + n1, sizeof(int*)*(m - n1));
	}
	if (n2 < n) {
		memcpy(newA + idx, nums2 + n2, sizeof(int*)*(n - n2));
	}
	memcpy(nums1, newA, sizeof(int)*(m + n));
	free(newA);
}
int main() {
	int nums1[] = { 1, 2, 3 };
	int nums2[] = { 1, 4, 5 };
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int size2 = sizeof(nums1) / sizeof(nums1[0]);
	merge(nums1, size1, 3, nums2, size2, 3);
	for (int i = 0; i < size1 + size2 - 1; i++) {

		printf("%d ", nums1[i]);

	}

	system("pause");
	return 0;

}


法3.可借助于先将两个数组合并到一起,然后在进行排序处理

#include <stdio.h>
#include <stdlib.h>

void merge(int nums1[], int size1, int  m, int nums2[], int size2, int n,int newA[],int size3) {
	for (int i = 0; i < m; i++) {
		newA[i] = nums1[i];
	}
	for (int j = 0, i = 3; j < n; j++, i++) {
		newA[i] = nums2[j];
	}
	//这一块是核心对整合到一起的数组进行排序(冒泡排序) 既有升序也有降序
	// 走的趟数
	int size = 6;
	for (int i = 0; i < size;i++) { 
		for (int j = size - 1 - i; j >= 0;j--) {  //每一趟比较的次数
			if (newA[j] < newA[j-1]) {
				int temp = newA[j - 1];
				newA[j - 1] = newA[j];
				newA[j] = temp;
			}
		}
	}
}
int main() {
	int newA[1024] = { 0 };
	int nums1[3] = { 1, 2, 3 };
	int nums2[3] = { 1, 4, 5 };
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int size2 = sizeof(nums1) / sizeof(nums1[0]);
	merge(nums1, size1, 3, nums2, size2, 3, newA,1024);
	for (int i = 0; i < size1+size2; i++) {
		printf(" %d", newA[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}