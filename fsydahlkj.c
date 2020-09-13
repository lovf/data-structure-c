//////////����������ʽ������ʽ:
ǰ�����: node  left  right
�������: left  node  right
�������: left  right  node

�������:  �ӵ�һ�㿪ʼ,,����ÿһ�ζ��Ǵ������ҽ��б���

//����:
//1.��������ǰ�����:
//��һ�����ܵý�����: ������+������+1 (�ݹ������)
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

//ǰ������Ĺ���  
void  _preorderT(struct TreeNode* root, int* array, int* idx) {  //��ǰ�������Ľڵ�  //����(�ڵ��Ǳ�����������) // �ڵ��λ��  idx������ȫ�ֵ�����,��Ȼ�ڵݹ�Ĺ����лᱻ���ǵ�
	if (root) {
		//��ǰ�ڵ� ,������ָ��
		array[*idx] = root->val;
		++(*idx);
		//������
		_preorderT(root->left, array, idx);
		//������
		_preorderT(root->right, array, idx);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	//���Ľڵ��������   �������ĸ���  +   �������ĸ��� + 1
	int* array = (int*)malloc(getSize(root)*sizeof(int));
	//����,����ڵ�
	*returnSize = 0;
	_preorderT(root, array, returnSize); //���ݾͱ��������Ĵ�С
	return array;
}

//2.���������������:
int getSize(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
void  _inorderT(struct TreeNode* root, int* array, int* idx) {
	if (root) {
		_inorderT(root->left, array, idx);
		array[*idx] = root->val;
		++(*idx);
		_inorderT(root->right, array, idx);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int* array = (int*)malloc(sizeof(int)*getSize(root));
	*returnSize = 0;
	_inorderT(root, array, returnSize);
	return array;
}

//3.�������ĺ������:
int getSize(struct TreeNode* root) {
	2
	if (root == NULL) {
		return 0;
	}
	return getSize(root->left) + getSize(root->right) + 1;
}
void  _postorderT(struct TreeNode* root, int* array, int* idx) {
	if (root) {
		_postorderT(root->left, array, idx);

		_postorderT(root->right, array, idx);

		array[*idx] = root->val;
		++(*idx);

	}
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int* array = (int*)malloc(sizeof(int)*getSize(root));
	*returnSize = 0;
	_postorderT(root, array, returnSize);
	return array;
}