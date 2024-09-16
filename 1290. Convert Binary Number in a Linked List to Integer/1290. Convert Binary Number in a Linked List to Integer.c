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
	}
	return ans;
	
    
}