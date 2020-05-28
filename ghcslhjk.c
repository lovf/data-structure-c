//二叉树创建以及遍历
//题目描述
//
//
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//
//输入描述 :
//输入包括1行字符串，长度不超过100。
//
//输出描述 :
//可能有多组测试数据，对于每组数据，
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
//每个输出结果占一行。
//
//示例1
//输入
//复制
//abc##de#g##f###
//
//输出
//复制
//c b e g d f a
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
	struct  Node* left;
	struct  Node* right;
	char val;
}Node;

//创建二叉树
Node* creatTree(char* str, int* idx) {
	if (str[*idx] != '#'){
		Node* root = (Node*)malloc(sizeof(struct Node));
		root->val = str[*idx];
		++(*idx);
		root->left = creatTree(str, idx);
		++(*idx);
		root->right = creatTree(str, idx);
		return root;
	}
	else  {

		return NULL;
	}
}

//前序遍历 / 中序遍历, 后序遍历
void  inorder(Node*root){
	if (root) {
		inorder(root->left);
		printf("%c ", root->val);
		inorder(root->right);
	}
}


int main() {
	char str[101] = { 0 };
	scanf("%s", str);
	int idx = 0;
	Node* root = creatTree(str, &idx);
	inorder(root);
	printf("\n");
	system("pause");
	return 0;
}
