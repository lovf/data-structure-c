//����������ʽ������ʽ:
//ǰ�����: node  left  right
//�������: left  node  right
//�������: left  right  node

//�������:  �ӵ�һ�㿪ʼ,,����ÿһ�ζ��Ǵ������ҽ��б���

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
//4.965. ��ֵ������ 
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��

bool isU(struct TreeNode* root, int key) { //�ж������ڵ��Ƿ����
	if (root == NULL)
		return true;
	return root->val == key  //�ж��ڵ��Ƿ����
		&& isU(root->left, key)   //�ж��������ǲ��Ǻͽڵ����
		&& isU(root->right, key); //�ж��������ǲ��Ǻͽڵ����

}

bool isUnivalTree(struct TreeNode* root) {
	return isU(root, root->val); //����ȥ���ڵ�
}
//5.��������������

int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int l = maxDepth(root->left); //������������ĳ���
	int r = maxDepth(root->right); //������������ĳ���

	return l > r ? l + 1 : r + 1; //�����Ǹ����ȴ�+1�������������������
}
//6.��ת������
void _vertT(struct TreeNode* root) {
	//1.��ת���Һ���
	//2.��ת�������� 
	if (root) {
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		_vertT(root->left);
		_vertT(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root) {
	_vertT(root);
	return root;
}
//7.��ָ Offer 27. �������ľ���
//�����һ������������һ�����������ú���������ľ���
struct TreeNode* mirror(struct TreeNode* root){
	if (root == NULL) {
		return root;
	}
	else {
		struct TreeNode* temp = root->left; //���Һ��ӽ��н���
		root->left = root->right;
		root->right = temp;
		mirror(root->left); //�ٽ������Һ���Ϊ�����������н���
		mirror(root->right);
	}
	return root;
}
struct TreeNode* mirrorTree(struct TreeNode* root){
	return mirror(root);
}
//8.��ͬ����

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) //ͬʱ�ߵ���,�ṹ��ͬ
		return true;

	if (p == NULL || q == NULL) //û��ͬʱ�ߵ�,�սṹ��ͬ
		return false;

	return p->val == q->val  //����Ӧλ�õ�ֵ�Ƿ���ͬ�Լ���Ӧλ�õ������Ƿ���ͬ
		&& isSameTree(p->left, q->left) //��Ӧλ�õ������Ƿ���ͬ
		&& isSameTree(p->right, q->right);
}
//9.�Գƶ�����
bool isS(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL) //ͬʱ�ߵ���,�ṹ��ͬ
		return true;
	if (q == NULL || p == NULL) //��ͬʱ�ߵ���,�ṹ����ͬ
		return false;
	return p->val == q->val   //���ν��б����Ƚ϶Զ�Ӧ��ֵ�Ĵ�С
		&& isS(p->left, q->right)
		&& isS(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return isS(root->left, root->right);
}
//10.. ��һ���������� ���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������

bool isS(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL) //ͬʱ�ߵ���,�ṹ��ͬ
		return true;
	if (q == NULL || p == NULL) //��ͬʱ�ߵ���,�ṹ����ͬ
		return false;
	return p->val == q->val   //���ν��б����Ƚ϶Զ�Ӧ��ֵ�Ĵ�С
		&& isS(p->left, q->left)
		&& isS(p->right, q->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isS(s, t) //�ȿ������ڵ� 
		|| isSubtree(s->left, t) //��������t�Ľڵ�
		|| isSubtree(s->right, t); //��������t�Ľڵ�
}

