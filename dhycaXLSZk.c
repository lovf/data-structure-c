//反转单链表:


//利用头插的方式进行链表的反转
 struct ListNode* reverseList(struct ListNode* head) {
 struct ListNode* newH=NULL;
 struct ListNode* cur=head;
 struct ListNode*  next;
 while (cur) {
     next=cur->next;
     cur->next=newH;
     newH=cur;
     cur=next;
 }
 return newH;
 }
//三指针法
struct ListNode* reverseList(struct ListNode* head) {

	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode*  n3;
	while (n2) {
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		// if (n3) {
		// n3=n3->next;
		// }
	}
	return n1;
}