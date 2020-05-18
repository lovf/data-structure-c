//����14: �ָ�����
//��д������ x Ϊ��׼�ָ�����ʹ������С�� x �Ľڵ����ڴ��ڻ���� x �Ľڵ�֮ǰ����������а��� x��
//x ֻ�������С�� x ��Ԫ��֮��(������ʾ)���ָ�Ԫ�� x ֻ�账�ڡ��Ұ벿�֡����ɣ��䲻��Ҫ����������������֮�䡣
//ʾ�� :
//���� : head = 3->5->8->5->10->2->1, x = 5
//��� : 3->1->2->10->5->5->8
//����˼·:
//��һ��:�Ƚ�С��x�������һ��,����X�������һ��
//�ڶ���:����������������ϵ�һ��
struct ListNode* partition(struct ListNode* head, int x){
	struct ListNode* LH, *LT, *GH, *GT, *cur;
	if (head == NULL) {
		return NULL;
	}
	LH = LT = (struct ListNode*)malloc(sizeof(struct ListNode));
	GH = GT = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur = head;
	while (cur) {
		if (cur->val < x) {
			LT->next = cur;
			LT = LT->next;
		}
		else {
			GT->next = cur;
			GT = GT->next;
		}
		cur = cur->next;
	}
	GT->next = NULL;
	LT->next = GH->next;
	LT = LH;
	GT = GH;
	LH = LH->next;
	free(LT);
	free(GT);
	return LH;
}