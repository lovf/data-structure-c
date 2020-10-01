//第七种排序: 归并排序
//基本思想: 先进行分解然后进行合并

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//
void PrintArr(int* arr, int size) {
	for (int i = 0; i < size;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}
//进行将数组中元素进行排序
void mergeSortR(int* arr, int begin,int mid, int end, int* tmp) {
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) { //分成的组,那一组元素小先把哪一个元素放进新开的空间中
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//还有剩余的元素每有进行拷贝过来

	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1+1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2+1));
	//把新开空间的元素放进到原来的数组内
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin+1));
}
//对数组进行分解:
void mergeSort(int* arr, int begin,int end,int tmp) {
	if (begin >= end)
		return;
	//子区间有序,首先子区间进行排序,
	//子区间的分解
	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid, tmp);
	mergeSort(arr, mid+1, end, tmp);
	//合并有序数组
	mergeSortR(arr, begin, mid, end , tmp);
}

//归并排序: 等于直接调用接口就可以了
void merge(int* arr, int size) {
	int* tmp = (int*)malloc(sizeof(int)*size);
	mergeSort(arr, 0, size - 1, tmp);
	free(tmp); //释放新开的内存空间

}

int main () {
	int arr[]= { 10, 6, 7, 1, 3, 9, 4, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("未排序的数组: \n");
	PrintArr(arr, size);

	merge(arr, size);
	printf("经过归并排序之后的数组: \n");
	PrintArr(arr, size);
    system("color A");
    system ("pause");
    return 0;
}

//归并排序总结:
//第一步: 先对数组进行分组递归.
//第二步: 对分好组的数组进行排序合并
