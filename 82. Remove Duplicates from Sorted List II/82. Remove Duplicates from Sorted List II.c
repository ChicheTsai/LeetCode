/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *currNode = head, *tmp;
	struct ListNode *preNode = NULL;
	struct ListNode *listHead, *listNextHead;
	bool delFlag = false;
	
	while(currNode)
	{
		listHead = currNode;
		listNextHead = listHead->next;
		delFlag = false;
		while(listNextHead && listHead->val == listNextHead->val)
		{
			listNextHead = listNextHead->next;
			delFlag = true;			
		}
		
		if(delFlag == true)
		{		
			if(preNode == NULL)
			{
				while(head != listNextHead)
				{
					tmp = head;
					head = head->next;
					free(tmp);
				}
			}
			else
			{
				struct ListNode *tmp2;
				tmp2 = listHead;
				while(tmp2 != listNextHead)
				{
					tmp = tmp2;
					tmp2 = tmp2->next;
					free(tmp);
				}
				preNode->next = listNextHead;
			}
		}
		else
		{			
			preNode = listHead;
		}		
		currNode = listNextHead;		
	}    
	return head;
}