/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) 
	{
		return true;
	}
    else if (!p || !q) 
	{
		return false;
	}
	else
	{
		return (p->val == q->val) && \
		       isMirror(p->left, q->right) && \ 
               isMirror(p->right, q->left);
	}
}

bool isSymmetric(struct TreeNode* root) {
    if (root)
	{
		return isMirror(root->left, root->right);
	}
	return true;
}