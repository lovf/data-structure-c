���� 13:�����е�����k���ڵ�
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣
ʾ����
����һ������ : 1->2->3->4->5, �� k = 2.�������� 4->5.


		 ����1.���ÿ���ָ�����
	 ��һ�� : ����ȷ�������ڼ����ڵ�, ����ȷ����ָ���ߵ�����һ��λ��
	   �ڶ��� : ����ָ�����������ƶ�

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	struct ListNode* slow, *fast;
	slow = fast = head;
	while (k--) {
		if (fast) {
			fast = fast->next;
		}
		else {
			return NULL;
		}
	}

	while (fast) {
		fast = fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

����2:���淨���
��һ�� : ���������������, �õ�����ĳ���
  �ڶ��� : �ٰѽڵ���n - k��λ��, �͵õ�������k���ڵ�
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	struct ListNode* cur = head;
	int idx = 0;
	while (cur) {
		idx++;
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i < idx - k; i++) {
		cur = cur->next;
	}
	return cur;
}