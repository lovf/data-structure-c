��ָ Offer 18. ɾ������Ľڵ�
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣

����ɾ����������ͷ�ڵ㡣

ע�⣺����Ա�ԭ���иĶ�

ʾ�� 1:

���� : head = [4, 5, 1, 9], val = 5
��� : [4, 1, 9]
 ���� : ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
	  ʾ�� 2 :

  ���� : head = [4, 5, 1, 9], val = 1
   ��� : [4, 5, 9]
	���� : ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.


		 ˵����

		 ��Ŀ��֤�����нڵ��ֵ������ͬ
		 ��ʹ�� C �� C++ ���ԣ��㲻��Ҫ free �� delete ��ɾ���Ľڵ�
		 ͨ������53, 891�ύ����91, 302

	 struct ListNode* deleteNode(struct ListNode* head, int val){
		 struct ListNode* cur = head;
		 struct ListNode* prev = NULL;
		 while (cur) {
			 if (cur->val == val) {
				 struct ListNode* next = cur->next;
				 if (prev == NULL)
					 head = next;
				 else
					 prev->next = next;
				 free(cur);
				 cur = next;
			 }
			 else  {
				 prev = cur;
				 cur = cur->next;
			 }
		 }
		 return head;
	 }
