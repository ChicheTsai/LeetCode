/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	struct ListNode *ptr1 = head, *ptr2 = head;
	struct ListNode *preNode = NULL;
	while(n > 0)
	{
		ptr2 = ptr2->next;
		n--;
	}
	
	while(ptr2)
	{
		preNode = ptr1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	if(preNode == NULL)
	{
		head = ptr1->next;
	}
	else
	{
		preNode->next = ptr1->next;
	}
	free(ptr1);
	return head;
	
	
    
}