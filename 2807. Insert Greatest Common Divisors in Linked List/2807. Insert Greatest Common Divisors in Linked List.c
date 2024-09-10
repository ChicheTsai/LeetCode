/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getGCD(int v1, int v2)
{
	int tmp;
	if(v1 < v2)
	{
		tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	
	while(v1 % v2)
	{
		tmp = v1 - v2 * (v1/v2);
		v1 = v2;
		v2 = tmp;
	}
	return v2;
}	
 
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode *preNode = head, *nextNode, *newNode;
	if(preNode)
	{
		nextNode = preNode->next;
	}
	
	while(preNode && nextNode)
	{
		newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = getGCD(preNode->val, nextNode->val);
		preNode->next = newNode;
		newNode->next = nextNode;
		
		preNode = nextNode;
		nextNode = nextNode->next;		
	}
    
	return head;
}