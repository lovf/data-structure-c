//1.原地移除数组中的val,要求时间复杂度O(n),空间复杂度为O(1):

#include <stdio.h>
#include <stdlib.h>

int removeNum(int arr[], int size,int value) {
	int idx = 0, i = 0;
	for (int i = 0; i < size;i++) {
		if (arr[i] != value) {
			arr[idx++] = arr[i];
		}
	}
	return idx;
}
int main () {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof (arr) / sizeof(arr[0]);
	int value = 5; // value 表示要删除的数字
	int ret=removeNum(arr,size,value); //ret表示返回新数组的长度.
	
	printf("%d\n",ret); 
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}

///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeNum(int arr[], int size,int value) {
	int idx = 0, i = 0;
	int* Newarr = (int*)malloc(size*sizeof(int));
	for (int i = 0; i < size;i++) {
		if (arr[i] != value) {
			Newarr[idx++] = arr[i];
		}
	}
	memcpy(arr, Newarr, size*sizeof(int));
	free(Newarr);
	return idx;
}
int main () {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof (arr) / sizeof(arr[0]);
	int value = 5; // value 表示要删除的数字
	int ret=removeNum(arr,size,value); //ret表示返回新数组的长度.
	
	printf("%d\n",ret); 
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}
//2.删除排序数组中的重复项.

#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(int arr[], int size) {
	int i = 0, j = 1, idx = 0;
	//利用的的是j和i进行变化,观察二者是否相等,然后idx依次再向后进行变化
	while (j<size) {
		arr[idx++] = arr[i];
		if (arr[i] != arr[j]) {
			++i;
			++j;
		}
		else {
			while (arr[i] == arr[j] && j < size)
				++j;
			i = j;
			++j;
		}
	}
	//当j已经调到数组的外面的时候最后一个元素也是一个不重复的数字,此时在这块也同样要满足复制.
	if (i < size) {
		arr[idx++] = arr[i];
	}
	return idx;
}

int main () {
	int arr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int ret = removeDuplicate(arr, size);
	printf("%d\n",ret);
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}

	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}



































































