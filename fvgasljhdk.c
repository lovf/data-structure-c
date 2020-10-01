//����������: �鲢����
//����˼��: �Ƚ��зֽ�Ȼ����кϲ�

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
//���н�������Ԫ�ؽ�������
void mergeSortR(int* arr, int begin,int mid, int end, int* tmp) {
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) { //�ֳɵ���,��һ��Ԫ��С�Ȱ���һ��Ԫ�طŽ��¿��Ŀռ���
		if (arr[begin1] <= arr[begin2])
			tmp[idx++] = arr[begin1++];
		else
			tmp[idx++] = arr[begin2++];
	}
	//����ʣ���Ԫ��ÿ�н��п�������

	if (begin1 <= end1)
		memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1+1));
	if (begin2 <= end2)
		memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2+1));
	//���¿��ռ��Ԫ�طŽ���ԭ����������
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin+1));
}
//��������зֽ�:
void mergeSort(int* arr, int begin,int end,int tmp) {
	if (begin >= end)
		return;
	//����������,�����������������,
	//������ķֽ�
	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid, tmp);
	mergeSort(arr, mid+1, end, tmp);
	//�ϲ���������
	mergeSortR(arr, begin, mid, end , tmp);
}

//�鲢����: ����ֱ�ӵ��ýӿھͿ�����
void merge(int* arr, int size) {
	int* tmp = (int*)malloc(sizeof(int)*size);
	mergeSort(arr, 0, size - 1, tmp);
	free(tmp); //�ͷ��¿����ڴ�ռ�

}

int main () {
	int arr[]= { 10, 6, 7, 1, 3, 9, 4, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("δ���������: \n");
	PrintArr(arr, size);

	merge(arr, size);
	printf("�����鲢����֮�������: \n");
	PrintArr(arr, size);
    system("color A");
    system ("pause");
    return 0;
}

//�鲢�����ܽ�:
//��һ��: �ȶ�������з���ݹ�.
//�ڶ���: �Էֺ���������������ϲ�
