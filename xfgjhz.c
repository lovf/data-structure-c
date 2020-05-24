////heap.h文件
//#include <stdlib.h>
//#include <stdio.h>
//
//typedef int HpDatatype;
//typedef struct Heap{
//	HpDatatype* _array;
//	HpDatatype _size;
//	HpDatatype _capacity;
//}heaP;
//void Swap(int* array, int left, int right);
//void heapSort(int* array, int n);
//void shiftDownB(HpDatatype* _array, int size, int parent);
//
////**********************************************************************************************************
////heap.c文件
//#include "heap.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//void heapSort(int* array, int n) {
//	for (int i = (n - 2) / 2; i >= 0; --i) {
//		shiftDownB(array, n, i);
//	}
//	int size = n;
//	while (size > 0){
//		//实现尾删的过程:1.交换2.删除最后一个元素3.把破坏的堆结构重新进行调整
//
//		//1.交换位置
//		Swap(array, 0, size - 1);
//		//2.删除最后一个元素
//		--size;//这块的删除实际上是假删除
//		//3.重新调整破坏的堆的位置
//		shiftDownB(array, size, 0);
//	}
//}
//
//void Swap(int* array, int left, int right) {
//
//	int temp = array[left];
//	array[left] = array[right];
//	array[right] = temp;
//}
//
//
//void shiftDownB(HpDatatype* array, int size, int parent) {
//	int child = parent * 2 + 1;
//	while (child < size) {
//		if (child + 1 < size && array[child] < array[child + 1])
//			++child;
//		if (array[child]>array[parent]) {
//			Swap(array, child, parent);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else {
//			break;
//		}
//	}
//}
//*****************************************************************************************************
//*****************************************************************************************************




#include "heap.h"
#include <stdio.h>
#include <stdlib.h>



void test() {
	int array[] = { 30, 45, 15, 35, 36, 18, 53, 72, 48 , 92};

	heapSort(array, 10);
	for (int i = 0; i < 10;i++) {
		printf("%d ",array[i]);
	}
	printf("\n");

}
int main() {

	test();
	system("pause");
	return 0;
}