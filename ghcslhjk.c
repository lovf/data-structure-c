//�����������Լ�����
//��Ŀ����
//
//
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
//
//�������� :
//�������1���ַ��������Ȳ�����100��
//
//������� :
//�����ж���������ݣ�����ÿ�����ݣ�
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
//ÿ��������ռһ�С�
//
//ʾ��1
//����
//����
//abc##de#g##f###
//
//���
//����
//c b e g d f a
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
	struct  Node* left;
	struct  Node* right;
	char val;
}Node;

//����������
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

//ǰ����� / �������, �������
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
