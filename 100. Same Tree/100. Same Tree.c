/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if((p == NULL) && (q == NULL))
	{
		return true;
	}
	else if((p != NULL) && (q != NULL))
	{
		if(p->val == q->val)
		{
			bool lResult = isSameTree(p->left, q->left);
			bool rResult = isSameTree(p->right, q->right);
			return (lResult && rResult);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}