//**********************************************************************************************
I.二叉树的深度
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树[3, 9, 20, null, null, 15, 7]，

3
/ \
9  20
/ \
15   7
返回它的最大深度 3 。
//*********************************************************************************************
//法1:
 int maxDepth(struct TreeNode* root) {
     if(root == NULL) 
     return 0;
   int rootleft = 1;
   int rootright = 1; 
   if (root->left)
   rootleft += maxDepth(root->left);
   if (root->right)   
   rootright += maxDepth(root->right);
 return rootleft > rootright ? rootleft : rootright;
 }
//*****************************************************************************************
//法2:
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return l > r ? l + 1 : r + 1;

}