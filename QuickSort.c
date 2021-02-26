#include"QuickSort.h"

//�ҳ���׼ֵ
//1.�Ӻ���ǰ����,�ҵ���һ��С�ڻ�׼ֵ������
//2.��ǰ������,�ҵ���һ�����ڻ�׼ֵ������
//3.���ҵ������ֽ��н���,ѭ��ִ�� ����1 2

//4.���������ǰ�ƶ�,Ȼ��������λ�����׼ֵ��λ�ý��н���

//��������
void Swap(int* array, int left, int right) {
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

//���л���λ�õ�ֵ
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
	//�ٰ�������λ�úͳ�ʼֵ��λ�ý��н���
	Swap(array, start, begin);
	return begin;
}

//hora����ʵ�ֿ�������
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
























































