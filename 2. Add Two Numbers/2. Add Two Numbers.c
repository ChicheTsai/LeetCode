/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *ptr1 = l1, *ptr2 = l2;
	struct ListNode *node, *head = NULL, *preNode = NULL;
	int sum = 0, carry = 0;
	
	while(ptr1 || ptr2)
	{
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum = carry;
		if(ptr1)
		{
			sum += ptr1->val;
			ptr1 = ptr1->next;			
		}
		if(ptr2)
		{
			sum += ptr2->val;
			ptr2 = ptr2->next;
		}
				
		carry = sum / 10;
		if(sum >= 10)
		{
			sum -= 10;
		}
		
		node->val = sum;
		node->next = NULL;

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
	
	if(carry)
	{
		node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = 0x1;
		node->next = NULL;
		preNode->next = node;
	}
	
	return head;
    
}