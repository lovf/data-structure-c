147. ��������в�������
//��������в�������
//
//
//��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
//ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�
//
//
//
//���������㷨��
//
//���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//�ظ�ֱ�������������ݲ�����Ϊֹ��
//
//
//ʾ�� 1��
//
//���� : 4->2->1->3
// ��� : 1->2->3->4
//	  ʾ�� 2��
//
//  ���� : -1->5->3->4->0
//   ��� : -1->0->3->4->5
//
struct ListNode* insertionSortList(struct ListNode* head){
	struct ListNode* cur, *prev, *start, *newH;//��ǰλ�� , ǰ�� ,��ʼλ�� ,�µ�ͷ ,

	if (head == NULL || head->next == NULL) {
		return head;
	}
	//�Զ��������Ԫ�ؽ��г�ʼ��
	prev = head;
	cur = head->next;
	newH = (struct ListNode*)malloc(sizeof(struct ListNode));//�µ�ͷ
	while (cur) {
		if (cur->val >= prev->val) { //˵������Ҫ����
			prev = cur;
			cur = cur->next;
		}
		else {
			start = newH;
			while (start->next && start->next->val <= cur->val) {
				start = start->next;
				prev->next = cur->next;
				cur->next = start->next;
				start->next = cur;
				cur = prev->next;
			}
		}
	}
	cur = newH->next;
	free(newH);
	return cur;
}