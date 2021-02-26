#include"QuickSort.h"

//找出基准值
//1.从后向前查找,找到第一个小于基准值的数字
//2.从前向后查找,找到第一个大于基准值的数字
//3.将找到的数字进行交换,循环执行 步骤1 2

//4.继续向后向前移动,然后将相遇的位置与基准值的位置进行交换

//交换函数
void Swap(int* array, int left, int right) {
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

//进行划分位置的值
int PartionValue(int* array, int begin, int end) {
	int start = begin;
	int key = array[begin];
	while (begin < end) {
		while (begin < end && array[end] >= key)
			--end;
		while (begin < end && array[begin] <= key)
			++begin;
		Swap(array, begin, end);
	}
	//再把相遇的位置和初始值的位置进行交换
	Swap(array, start, begin);
	return begin;
}

//hora划分实现快速排序
void QuickSort(int* array, int begin, int end) {
	if (begin >= end)
		return ;
	int keyPos = PartionValue(array, begin, end);
	QuickSort(array, begin, keyPos - 1);
	QuickSort(array, keyPos + 1, end);
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size;i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
























































