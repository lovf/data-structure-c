//合并两个有序数组 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr1[],int m, int arr2[],int n) {
	//未申请动态内存时,从后向前进行比较
	int idx = m + n - 1;
	while (m >0 && n >0) {
		if (arr1[m-1] >= arr2[n-1]) {
			arr1[idx--] = arr1[m - 1];
			--m;
		}
		else {
			arr1[idx--] = arr2[n - 1];
			--n;
		}
	}
	if (n>0) {
		memcpy(arr1,arr2,sizeof(int)*n);
	}
	for (int i = 0; i < 12; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

int main () {
	int arr1[] = { 1, 3, 3, 5, 7, 7 };
	int arr2[] = { 2, 4, 4, 5, 8, 9 };

	merge(arr1, 6, arr2,  6);
    system("color A");
    system ("pause");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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