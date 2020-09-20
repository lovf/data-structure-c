//二叉树遍历
//利用字符串前序创建二叉树,中序打印出来

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char val;

}Node;


void order(struct Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		order(root->left);
		printf("%c ", root->val);
		order(root->right);
	}
}

Node* creatTree(char* str, int* idx) {
	if (str[*idx] != ' ') {
		Node* root = (Node*)malloc(sizeof(Node));
		root->val = str[*idx];
		++(*idx);
		root->left = creatTree(str, idx);
		++(*idx);
		root->right = creatTree(str, idx);
		return root;
	}
	else {
		return NULL;
	}
}

int main() {
	char str[] = "ABC  DE G  F   ";
	int i = 0;
	Node* root = creatTree(str, &i);
	order(root);
	system("color A");
	system("pause");
	return 0;
}
