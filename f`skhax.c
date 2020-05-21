//����1:
��һ�������������,�ҵ�ֻ����һ�ε����ֲ������±�
����1.���
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
����2.ʹ�õݹ�
#include <stdio.h>
#include <stdlib.h>

int findNumber(int* arr,int size) {
	return size == 1 ? arr[0] : findNumber(arr + 1, size - 1) ^ arr[0];
}

int main() {
	int arr[] = { 1, 2, 4, 1, 2, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = findNumber(arr, size);
	printf("ֻ����һ�ε�������: %d\n",ret);
	system("pause");
	return 0;
}

����3.����һ���µ�����,Ȼ����ԭ�������ֵ��Ϊ��Ϊ������ķ����±�,(�˷�������һ���ı׶�,����ķ�Χ����ܴ�)

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
	printf("ֻ����һ�ε�������: %d\n", ret);
	system("pause");
	return 0;
}
*****************************************************************************************************
����2:�ϲ�������������
�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣
˵�� :
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ�� :
���� :
	nums1 = [1, 2, 3, 0, 0, 0], m = 3
	nums2 = [2, 5, 6], n = 3

��� : [1, 2, 2, 3, 5, 6]


����1.�Ӻ���ǰ�����ж�:

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
��ǰ��������ж�
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


��3.�ɽ������Ƚ���������ϲ���һ��,Ȼ���ڽ���������

#include <stdio.h>
#include <stdlib.h>

void merge(int nums1[], int size1, int  m, int nums2[], int size2, int n,int newA[],int size3) {
	for (int i = 0; i < m; i++) {
		newA[i] = nums1[i];
	}
	for (int j = 0, i = 3; j < n; j++, i++) {
		newA[i] = nums2[j];
	}
	//��һ���Ǻ��Ķ����ϵ�һ��������������(ð������) ��������Ҳ�н���
	// �ߵ�����
	int size = 6;
	for (int i = 0; i < size;i++) { 
		for (int j = size - 1 - i; j >= 0;j--) {  //ÿһ�˱ȽϵĴ���
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