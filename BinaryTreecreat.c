#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	char val;
}Node;

//��������Զ���������:  ����ǰ��������д�����
Node* BinaryTreeCreat(char* str, int* idx) {
	if (str[*idx] != '#') {
		Node* root = (Node*)malloc(sizeof(Node));
		root->val = str[*idx];
		++(*idx);
		root->left = BinaryTreeCreat(str, idx);
		++(*idx);
		root->right = BinaryTreeCreat(str, idx);
		return root;
	}
	else
		return NULL;
}

//�������
void _inOrderTree(Node* root) {
	if (root) {
		//printf("%c ", root->val); //ǰ�����
		_inOrderTree(root->left);
		//printf("%c ", root->val);//�������
		_inOrderTree(root->right);
		printf("%c ", root->val);//�������
	}

}

int main() {
	char str[101] = { 0 };
	int idx = 0;
	scanf("%s", str);
	Node* root = BinaryTreeCreat(str, &idx);
	_inOrderTree(root);
	printf("\n");
	system("pause");
	return 0;
}
