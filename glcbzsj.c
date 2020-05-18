//问题14: 分割链表
//编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，
//x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。
//示例 :
//输入 : head = 3->5->8->5->10->2->1, x = 5
//输出 : 3->1->2->10->5->5->8
//解题思路:
//第一步:先将小于x的链表放一起,大于X的链表放一起
//第二步:将两个链表进行整合到一起
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