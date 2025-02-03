/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int x = maxDepth(root->left);
		int y = maxDepth(root->right);
		return 1 + ((x >= y) ? x : y);
	}    
}