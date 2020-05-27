//对称二叉树
//给定一个二叉树，检查它是否是镜像对称的。
//
//
//
//例如，二叉树[1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//
//但是下面这个[1, 2, 2, null, 3, null, 3] 则不是镜像对称的:
//
//1
/// \
//2   2
//\   \
//3    3

bool  isSy(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val && isSy(p->left, q->right) &&
		isSy(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return isSy(root->left, root->right);
}

