 ��ת������
��תһ�ö�������

ʾ����

���룺

     4
   /   \
  2     7
 / \   / \
1   3 6   9
�����

     4
   /   \
  7     2
 / \   / \
9   6 3   1
****************************************************************************
void _verse(struct TreeNode* root) {
  if (root) {
    //��ת������������
    struct TreeNode* temp = root->left;
      root->left = root->right;
      root->right = temp;
    //��ת������������
    _verse(root->left);
    _verse(root->right);
    }
}
 struct TreeNode* invertTree(struct TreeNode* root) {
   _verse(root);
    return root;
    
}