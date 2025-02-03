/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	bool ret = false;
	struct ListNode *currPtr, *nextPtr;
	
	currPtr = head;
	nextPtr = (currPtr != NULL) ? currPtr->next : NULL;
	
	while((nextPtr != NULL) && (currPtr != NULL))
	{
		if(nextPtr == currPtr)
		{
			ret = true;
			break;
		}
		else
		{
			currPtr = currPtr->next;
			nextPtr = nextPtr->next;
			nextPtr = (nextPtr != NULL) ? nextPtr->next : NULL;			
		}
	}
	
	return ret;
}