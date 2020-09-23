//��������
//����˼��: ���Ѿ��ź���������и��������������һ�����ʵ�λ��
// ����֮ǰ�����һ���������Ѿ��ź�˳���
#include <stdio.h>
#include <stdlib.h>

void insertSort(int* array, int size) { //�����һ��Ԫ���Ѿ��ź�˳��
	for (int i = 0; i < size - 1; i++) {
		int end = i;
		int key = array[end + 1]; //�տ�ʼ�ȸ���һ��Ԫ�غ͵ڶ���Ԫ�ؽ��б��
		while (end >= 0 && array[end] >= key) {  //���бȽϴ�СȻ����н�������
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;  
	}
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 9, 10, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	printf("����֮ǰ��Ԫ��: \n");
	PrintArray(array, size);

	insertSort(array, size);
	printf("����֮���Ԫ��: \n");
	PrintArray(array, size);

	system("color A");
	system("pause");
	return 0;
}
