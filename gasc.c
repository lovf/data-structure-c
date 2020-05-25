226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

4
/ \
2     7
/ \ / \
1   3 6   9
输出：

4
/ \
7     2
/ \ / \
9   6 3   1
//********************************************
void  invert(struct TreeNode* root) {
	if (root){
		//翻转左右孩子
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		// 翻转左右子树
		invert(root->left);
		invert(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root){
	invert(root);

	return root;
}