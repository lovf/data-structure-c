//问题11:链表的中间节点
// 方法一：利用中间法来进行查找遍历.首先遍历一遍单链表，记录链表的长度len，再次遍历以便链表，遍历到len/2次时返回当前节点记为中间节点。

// 方法二：利用快慢指针，快指针每次走两步，慢指针每次走一步，所以快指针走的距离为慢指针的两倍，故当快指针遍历到链表末尾时，慢指针指向记为中间节点


//方法1.快慢指针方式来寻找中间节点
 struct ListNode* middleNode(struct ListNode* head){
 struct ListNode* fast,*slow;
 fast=slow=head;
 while(fast && fast->next)  {
   slow=slow->next;
   fast =fast->next->next;
   }
 return slow;
 }

//方法2:利用中间法来进行遍历来寻找
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