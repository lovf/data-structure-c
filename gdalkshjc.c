问题10: 链表的回文结构
	//解题思路
	//两种方法：
	//1.将链表里的值存储在数组里，然后数组首尾一次判断，不相等则False；
	//2.快慢指针，找到中间节点，将后半个链表反转，然后遍历前半个后后半个一起遍历，不同则false，注意比较时while的条件为，后半个链表不为空，这样就不用考虑奇数还是偶数的情况了
	//快慢指针的思路:1、采用快慢两个指针去寻找链表的中间节点；2、根据链表的中间节点反转后一半的链表；
	//3、迭代比较链表前一半的元素和后一半的元素，判断节点的值是否相等，得出是否为回文

	//方法1.
	//第一步:找到中间的那个节点
	//第二步 : 从中间那个链表往后依次进行翻转,
	//  第三步 : 将翻折之后的与前面一半的链表数据进行比较(只要有一个数据不一样那么就是错误的)
			bool isPalindrome(struct ListNode* head){
				struct ListNode* fast, *slow;
				if (head == NULL || head->next == NULL) {
					return true;
				}
				//找到了中间结点 return slow就是中间结点
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
					//更新链表
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
	////方法2:常规法  将链表转化成数组
	////第一步:将链表依次放入到新创建的数组中
	////第二步:依次进行比较放入的元素
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

