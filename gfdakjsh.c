//�������� II
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
//
//˵�����������޸ĸ���������
//
//
//
//ʾ�� 1��
//
//���룺head = [3, 2, 0, -4], pos = 1
//�����tail connects to node index 1
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//
//ʾ�� 2��
//
//���룺head = [1, 2], pos = 0
//�����tail connects to node index 0
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//
//
//ʾ�� 3��
//
//���룺head = [1], pos = -1
//�����no cycle
//���ͣ�������û�л���
//���� �뻷�Ľڵ�

//�����ж��Ƿ��л�
//�ҵ������ĵ�
struct ListNode *Node(struct ListNode *head) {
	struct ListNode *fast, *slow;
	if (head == NULL) {
		return NULL;

	}
	fast = slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
//�������ĵ��Ƿ���ڻ���ͷ���
struct ListNode *detectCycle(struct ListNode *head) { //�������Ľڵ��Ƿ����ͷ���
	struct ListNode * cur = Node(head);
	while (cur) {
		while (cur != head) {  //���������ĵ㲻����ͷ���ʱ,��ôcur��head����������
			cur = cur->next;
			head = head->next;
		}
		return cur;
	}
	return NULL;
}