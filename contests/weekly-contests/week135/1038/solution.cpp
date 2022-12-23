/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	int help(TreeNode* root, int num)
	{
		if (!root)
			return num;
		num = help(root->right, num);
		root->val += num;
		num = help(root->left, root->val);
        return num;
	}
public:
    TreeNode* bstToGst(TreeNode* root) {
		help(root, 0);
        return root;
    }
};

