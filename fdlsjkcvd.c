//����11:������м�ڵ�
// ����һ�������м䷨�����в��ұ���.���ȱ���һ�鵥������¼����ĳ���len���ٴα����Ա�����������len/2��ʱ���ص�ǰ�ڵ��Ϊ�м�ڵ㡣

// �����������ÿ���ָ�룬��ָ��ÿ������������ָ��ÿ����һ�������Կ�ָ���ߵľ���Ϊ��ָ����������ʵ���ָ�����������ĩβʱ����ָ��ָ���Ϊ�м�ڵ�


//����1.����ָ�뷽ʽ��Ѱ���м�ڵ�
 struct ListNode* middleNode(struct ListNode* head){
 struct ListNode* fast,*slow;
 fast=slow=head;
 while(fast && fast->next)  {
   slow=slow->next;
   fast =fast->next->next;
   }
 return slow;
 }

//����2:�����м䷨�����б�����Ѱ��
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* cur;
	cur = head;
	int size = 0;
	while (cur) {
		size++;
		cur = cur->next;
	}

	int len = size / 2;
	while (len--) {
		head = head->next;
	}
	return head;
}