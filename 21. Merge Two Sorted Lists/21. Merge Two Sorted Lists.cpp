/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	void mergeTwoListsRecursiveCore(ListNode* head, ListNode* list1, ListNode* list2) {
		ListNode** ppNode;
		if(list1 && list2)
		{
			if(list1->val <= list2->val)
			{
				ppNode = &list1;
			}
			else
			{
				ppNode = &list2;
			}
			
			if(head)
			{
				head->next = *ppNode;
			}
			head = head->next;
			(*ppNode) = (*ppNode)->next;
			mergeTwoListsRecursiveCore(head, list1, list2);
		}
		else if(list1 || list2)
		{
			ppNode = (list1) ? &list1 : &list2;
			
			if(head)
			{
				head->next = *ppNode;
			}
			*ppNode = NULL;
		}		
	}

	void mergeTwoListsIterationCore(ListNode* head, ListNode* list1, ListNode* list2) {
		ListNode** ppNode;
		while(list1 && list2)
		{
			if(list1->val <= list2->val)
			{
				ppNode = &list1;
			}
			else
			{
				ppNode = &list2;
			}
			
			if(head)
			{
				head->next = *ppNode;
			}
			head = head->next;
			(*ppNode) = (*ppNode)->next;
		}
		
		ppNode = (list1) ? &list1 : &list2;
		if(head)
		{
			head->next = *ppNode;
		}
		*ppNode = NULL;
	}

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		
		if(list1 && list2)
		{
			ListNode *head, *ret;
			if(list1->val <= list2->val)
			{
				head = list1;
				list1 = list1->next;
			}
			else
			{
				head = list2;
				list2 = list2->next;
			}
			ret = head;

			mergeTwoListsRecursiveCore(head, list1, list2);
			//mergeTwoListsIterationCore(head, list1, list2);
			return ret;
		}
		else
		{
			return (list1) ? list1 : list2 ;
		}
    }
};