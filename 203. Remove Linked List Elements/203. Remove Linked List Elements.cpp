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
	void getFirstNode(ListNode** ppHead, int val) {
		ListNode* pHead = *ppHead;
        while(pHead)
        {
            if(pHead->val == val)
            {
                pHead = pHead->next;
            }
            else
            {
                break;
            }
        }
		
		*ppHead = pHead;
	}

	void removeElementsRecursiveCore(ListNode** ppHead, int val) {
		ListNode *pCurr, *pNext;
		pCurr = *ppHead;
		if(pCurr)
		{
			pNext = pCurr->next;
			if(pNext)
			{
				getFirstNode(&pNext, val);
				pCurr->next = pNext;
				pCurr = pCurr->next;
				removeElementsRecursiveCore(&pCurr, val);
			}
		}
	}

	ListNode* removeElementsIter(ListNode* head, int val) {
		ListNode *curPtr, *prePtr;
        if(head)
        {
			getFirstNode(&head, val);
            curPtr = head;
            while(curPtr && curPtr->next)
            {
                if(curPtr->val == val)
                {
                    prePtr->next = curPtr->next;
                }
                else
                {
                    prePtr = curPtr;
                }
                curPtr = curPtr->next;
            }

            if(curPtr && curPtr->val == val)
            {
                prePtr->next = NULL;
            }
        }
        return head;
	}
	
	ListNode* removeElementsRecursive(ListNode* head, int val) {
		ListNode *curPtr, *prePtr;
        if(head)
        {
			getFirstNode(&head, val);
			curPtr = head;
			removeElementsRecursiveCore(&curPtr, val);
		}
		return head;
	}

    ListNode* removeElements(ListNode* head, int val) {
#if 1
		ListNode *ret = removeElementsIter(head, val);
#else
		ListNode *ret = removeElementsRecursive(head, val);
#endif
		return ret;
             
    }
};