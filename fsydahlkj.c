//////////二叉树的链式遍历方式:
前序遍历: node  left  right
中序遍历: left  node  right
后序遍历: left  right  node

层序遍历:  从第一层开始,,依次每一次都是从左向右进行遍历

//举例:
//1.二叉树的前序遍历:
//求一棵树总得结点个数: 左子树+右子树+1 (递归来完成)
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

//前序遍历的过程  
void  _preorderT(struct TreeNode* root, int* array, int* idx) {  //当前遍历到的节点  //数组(节点是保存在数组中) // 节点的位置  idx必须是全局的索引,不然在递归的过程中会被覆盖的
	if (root) {
		//当前节点 ,索引用指针
		array[*idx] = root->val;
		++(*idx);
		//左子树
		_preorderT(root->left, array, idx);
		//右子树
		_preorderT(root->right, array, idx);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	//数的节点个数等于   左子树的个数  +   右子树的个数 + 1
	int* array = (int*)malloc(getSize(root)*sizeof(int));
	//遍历,保存节点
	*returnSize = 0;
	_preorderT(root, array, returnSize); //内容就变成了数组的大小
	return array;
}

//2.二叉树的中序遍历:
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

//3.二叉树的后序遍历:
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