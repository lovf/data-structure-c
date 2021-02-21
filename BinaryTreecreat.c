#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	char val;
}Node;

//利用数组对二叉树创建:  借助前序遍历进行创建的
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

//中序遍历
void _inOrderTree(Node* root) {
	if (root) {
		//printf("%c ", root->val); //前序遍历
		_inOrderTree(root->left);
		//printf("%c ", root->val);//中序遍历
		_inOrderTree(root->right);
		printf("%c ", root->val);//后序遍历
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
