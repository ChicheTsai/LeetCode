/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	struct ListNode *ret = head;
	struct ListNode *head_2 = NULL, *head_3 = NULL;
	struct ListNode *tail_1 = NULL, *tail_2 = NULL;
	struct ListNode *prevNode = NULL, *currNode = head, *nextNode;
	int idx = 0;
	
	if(left == right)
	{
		return head;
	}
	
	while(currNode)
	{
		idx++;
		if(idx == left)
		{
			tail_1 = prevNode;
			head_2 = currNode;
		}
		if(idx == right)
		{
			tail_2 = currNode;
			head_3 = currNode->next;
		}
		
		prevNode = currNode;
		currNode = currNode->next;
	}

	if(tail_2 == NULL)
	{
		tail_2 = prevNode;
		head_3 = NULL;
	}
	
	if(tail_1 == NULL)
	{
		ret = tail_2;
	}
	
	prevNode = NULL;
	currNode = head_2;
	nextNode = head_2->next;
	
	while(nextNode && nextNode != head_3 )
	{
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
		nextNode = nextNode->next;
	}
	
	if(currNode)
	{
		currNode->next = prevNode;
	}

	head_2->next = head_3;
	
	if(tail_1)
	{
		tail_1->next = tail_2;
	}
	return ret;
    
}