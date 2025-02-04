/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode *ptr1 = list1, *ptr2 = list2;
	struct ListNode *node, *preNode = NULL, *head = NULL;
	bool pick = false;
	int minVal = 0x7FFF;
	
	while((ptr1 != NULL) || (ptr2 != NULL))
	{
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->next = NULL;
		if(ptr1)
		{
			minVal = ptr1->val;			
		}

		if(ptr2 && ptr2->val < minVal)
		{
			node->val = ptr2->val;
			ptr2 = ptr2->next;
		}
		else
		{
			node->val = ptr1->val;
			ptr1 = ptr1->next;			
		}
		
		minVal = 0x7FFF;
		
		if(head == NULL)
		{
			head = node;
		}
		
		if(preNode == NULL)
		{
			preNode = node;
		}
		else
		{
			preNode->next = node;
			preNode = preNode->next;
		}		
	}
	return head;
    
}