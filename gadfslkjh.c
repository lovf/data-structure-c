// //头插法
 struct ListNode* reverseList(struct ListNode* head) { 
 struct ListNode* prev=NULL;
 struct ListNode* cur=head;
 struct ListNode* next;
 while (cur) {
   next=cur->next; //先要给next进行标记,不然更新之后找不到断开的next;
   cur->next=prev;
   prev=cur;
   cur=next;
 }
 return prev;
 }
//三指针法:
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3;
	while (n2)  {
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		n3 = n3->next;
	}
	return n1;
}