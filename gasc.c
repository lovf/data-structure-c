226. ��ת������
��תһ�ö�������

ʾ����

���룺

4
/ \
2     7
/ \ / \
1   3 6   9
�����

4
/ \
7     2
/ \ / \
9   6 3   1
//********************************************
void  invert(struct TreeNode* root) {
	if (root){
		//��ת���Һ���
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		// ��ת��������
		invert(root->left);
		invert(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root){
	invert(root);

	return root;
}