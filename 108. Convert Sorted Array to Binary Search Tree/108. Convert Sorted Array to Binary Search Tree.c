/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* getNode(int* nums, int l, int r) {
	if(r < l)
	{
		return NULL;
	}
	else
	{
		struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		int mid = (l + r) / 2;
		node->val = nums[mid];
		node->left = getNode(nums, l, mid - 1);
		node->right = getNode(nums, mid + 1, r);
		
		return node;
	}
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	int mid = numsSize / 2;
	if(numsSize == 0x0)
	{
		return NULL;
	}
	else
	{
		struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		head->val = nums[numsSize / 2];
		head->left = getNode(nums, 0, numsSize / 2 - 1);
		head->right = getNode(nums, numsSize / 2 + 1, numsSize -1 );
        return head;
	}    
}