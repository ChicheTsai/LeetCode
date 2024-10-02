/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *prevNode, *currNode, *nextNode = NULL;
	prevNode = NULL;
	currNode = head;
	if(head)
	{
		nextNode = currNode->next;
	}
	
	while(nextNode)
	{
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
		nextNode = nextNode->next;
		//printf("%d\n",prevNode->val);
		//printf("%d %d\n",currNode->val, currNode->next->val);
		//printf("%d\n",prevNode->val);
	}
	
	if(currNode)
	{
		currNode->next = prevNode;
	}
	return currNode;
}