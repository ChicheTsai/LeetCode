/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
	int n = 0;
	int ret = 0;
	struct ListNode* ptr = head;
	while(ptr)
	{
		n++;
		ptr = ptr->next;
	}
	
	if(n)
	{
		int arr[n/2];
		ptr = head;
		for(int i = 0;i < n; i++, ptr = ptr->next)
		{
			if(i < n / 2)
			{
				arr[i] = ptr->val;
			}
			else
			{
				arr[n - i - 1] += ptr->val;
			}
		}
		
		for(int i = 0;i < n/2; i++)
		{
			if(arr[i] > ret)
			{
				ret = arr[i];
			}
		}
	}
	return ret;
}