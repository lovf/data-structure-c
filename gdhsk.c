//**********************************************************************************************
I.�����������
����һ�ö������ĸ��ڵ㣬���������ȡ��Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

���磺

����������[3, 9, 20, null, null, 15, 7]��

3
/ \
9  20
/ \
15   7
�������������� 3 ��
//*********************************************************************************************
//��1:
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
//��2:
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return l > r ? l + 1 : r + 1;

}