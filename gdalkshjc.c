����10: ����Ļ��Ľṹ
	//����˼·
	//���ַ�����
	//1.���������ֵ�洢�������Ȼ��������βһ���жϣ��������False��
	//2.����ָ�룬�ҵ��м�ڵ㣬����������ת��Ȼ�����ǰ��������һ���������ͬ��false��ע��Ƚ�ʱwhile������Ϊ����������Ϊ�գ������Ͳ��ÿ�����������ż���������
	//����ָ���˼·:1�����ÿ�������ָ��ȥѰ��������м�ڵ㣻2������������м�ڵ㷴ת��һ�������
	//3�������Ƚ�����ǰһ���Ԫ�غͺ�һ���Ԫ�أ��жϽڵ��ֵ�Ƿ���ȣ��ó��Ƿ�Ϊ����

	//����1.
	//��һ��:�ҵ��м���Ǹ��ڵ�
	//�ڶ��� : ���м��Ǹ������������ν��з�ת,
	//  ������ : ������֮�����ǰ��һ����������ݽ��бȽ�(ֻҪ��һ�����ݲ�һ����ô���Ǵ����)
			bool isPalindrome(struct ListNode* head){
				struct ListNode* fast, *slow;
				if (head == NULL || head->next == NULL) {
					return true;
				}
				//�ҵ����м��� return slow�����м���
				fast = slow = head;
				while (fast && fast->next) {
					slow = slow->next;
					fast = fast->next->next;
				}
				struct ListNode* cur, *newH, *next;
				newH = NULL;
				cur = slow;
				while (cur) {
					next = cur->next;
					cur->next = newH;
					newH = cur;
					//��������
					cur = next;
				}
				cur = newH;
				while (head && cur) {
					if (head->val != cur->val) {
						return false;
					}
					else {
						head = head->next;
						cur = cur->next;
					}
				}
				return true;
			}
	////����2:���淨  ������ת��������
	////��һ��:���������η��뵽�´�����������
	////�ڶ���:���ν��бȽϷ����Ԫ��
	bool isPalindrome(struct ListNode* head){
		struct ListNode* cur;
		int idx = 0;
		int arr[1000000] = { 0 };
		cur = head;
		while (cur) {
			arr[idx++] = cur->val;
			cur = cur->next;
		}
		int start = 0;
		int end = idx - 1;
		while (start < end) {
			if (arr[start] != arr[end])
				return false;
			start++;
			end--;
		}
		return true;
	}

