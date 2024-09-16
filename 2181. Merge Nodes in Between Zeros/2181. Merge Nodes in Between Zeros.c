/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
	int ans = 0;
	struct ListNode* ptr = head;
	while(ptr)
	{
		ans = ans * 2 + ptr->val;
		ptr = ptr->next;
	}/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
	struct ListNode* retHead = NULL;
	struct ListNode* ptrW = head;
	struct ListNode* currNode;
	struct ListNode* prevNode;
	struct ListNode* newNode;
	int val = 0;
	
	if(head && head->next)
	{
		currNode = head->next;
	}
	
	while(currNode)
	{
		if(currNode->val == 0x0)
		{
#if 1
			ptrW->val = val;
			prevNode = ptrW;
			ptrW = ptrW->next;
#else
			newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			newNode->val = val;
			newNode->next = NULL;
			if(retHead == NULL)
			{
				retHead = newNode;
				ptrW = newNode;
			}
			else
			{
				ptrW->next = newNode;
				ptrW = ptrW->next;
			}
#endif			
			val = 0x0;
		}
		else
		{
			val += currNode->val;
		}
		currNode = currNode->next;
	}
	
	prevNode->next = NULL;
	while(currNode)
	{
		ptrW = currNode;
		currNode = currNode->next;
		free(ptrW);		
	}	
	return head;
    
}