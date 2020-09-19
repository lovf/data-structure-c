//二叉树的链式遍历方式:
//前序遍历: node  left  right
//中序遍历: left  node  right
//后序遍历: left  right  node

//层序遍历:  从第一层开始,,依次每一次都是从左向右进行遍历

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
//4.965. 单值二叉树 
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。

bool isU(struct TreeNode* root, int key) { //判定各个节点是否相等
	if (root == NULL)
		return true;
	return root->val == key  //判定节点是否相等
		&& isU(root->left, key)   //判定左子树是不是和节点相等
		&& isU(root->right, key); //判定右子树是不是和节点相等

}

bool isUnivalTree(struct TreeNode* root) {
	return isU(root, root->val); //传过去根节点
}
//5.二叉树的最大深度

int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int l = maxDepth(root->left); //计算出左子树的长度
	int r = maxDepth(root->right); //计算出右子树的长度

	return l > r ? l + 1 : r + 1; //最终那个长度大+1就是整个二叉树的深度
}
//6.翻转二叉树
void _vertT(struct TreeNode* root) {
	//1.翻转左右孩子
	//2.翻转左右子树 
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
//7.剑指 Offer 27. 二叉树的镜像
//请完成一个函数，输入一个二叉树，该函数输出它的镜像。
struct TreeNode* mirror(struct TreeNode* root){
	if (root == NULL) {
		return root;
	}
	else {
		struct TreeNode* temp = root->left; //左右孩子进行交换
		root->left = root->right;
		root->right = temp;
		mirror(root->left); //再将以左右孩子为根的字树进行交换
		mirror(root->right);
	}
	return root;
}
struct TreeNode* mirrorTree(struct TreeNode* root){
	return mirror(root);
}
//8.相同的树

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) //同时走到空,结构相同
		return true;

	if (p == NULL || q == NULL) //没有同时走到,空结构不同
		return false;

	return p->val == q->val  //看对应位置的值是否相同以及对应位置的字树是否相同
		&& isSameTree(p->left, q->left) //对应位置的字树是否相同
		&& isSameTree(p->right, q->right);
}
//9.对称二叉树
bool isS(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL) //同时走到空,结构相同
		return true;
	if (q == NULL || p == NULL) //不同时走到空,结构不相同
		return false;
	return p->val == q->val   //依次进行遍历比较对对应的值的大小
		&& isS(p->left, q->right)
		&& isS(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return isS(root->left, root->right);
}
//10.. 另一个树的子树 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

bool isS(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL) //同时走到空,结构相同
		return true;
	if (q == NULL || p == NULL) //不同时走到空,结构不相同
		return false;
	return p->val == q->val   //依次进行遍历比较对对应的值的大小
		&& isS(p->left, q->left)
		&& isS(p->right, q->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	return isS(s, t) //先看两个节点 
		|| isSubtree(s->left, t) //左子树与t的节点
		|| isSubtree(s->right, t); //右子树与t的节点
}

