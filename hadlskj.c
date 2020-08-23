//1.ԭ���Ƴ������е�val,Ҫ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�ΪO(1):

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
	int value = 5; // value ��ʾҪɾ��������
	int ret=removeNum(arr,size,value); //ret��ʾ����������ĳ���.
	
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
	int value = 5; // value ��ʾҪɾ��������
	int ret=removeNum(arr,size,value); //ret��ʾ����������ĳ���.
	
	printf("%d\n",ret); 
	for (int i = 0; i < ret;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
    system("color A");
    system ("pause");
    return 0;
}
//2.ɾ�����������е��ظ���.

#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(int arr[], int size) {
	int i = 0, j = 1, idx = 0;
	//���õĵ���j��i���б仯,�۲�����Ƿ����,Ȼ��idx�����������б仯
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
	//��j�Ѿ���������������ʱ�����һ��Ԫ��Ҳ��һ�����ظ�������,��ʱ�����Ҳͬ��Ҫ���㸴��.
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



































































