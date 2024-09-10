/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
	struct ListNode** ret = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
	struct ListNode* newNode; 
	struct ListNode* node = head;
	struct ListNode* nodePre;
	int lenTotal = 0, lenEach = 0;
	*returnSize = k;
	
	while(node)
	{
		node = node->next;
		lenTotal++;
	}
	
	node = head;
	
	for(int i = 0;i < k; i++)
	{
		int j;
		lenEach = lenTotal / k;
		if(i < (lenTotal % k))
		{
			lenEach++;
		}
		
		for(j = 0;j < lenEach; j++)
		{
			if(node)
			{
				newNode = (struct ListNode*)malloc(sizeof(struct ListNode));				
				newNode->val = node->val;
				newNode->next = NULL;
				
				if(j == 0)
				{
					ret[i] = newNode;
					nodePre = newNode;
				}
				else
				{
					nodePre->next = newNode;
					nodePre = newNode;
				}
				node = node->next;				
			}			
		}
		if(j == 0)
		{
			ret[i] = NULL;				
		}

	}
	return ret;
}