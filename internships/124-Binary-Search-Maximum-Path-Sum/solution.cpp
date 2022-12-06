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
	int ans = -10000;

	int maxPathSum2(TreeNode* root) {
		if (root == NULL)
			return -10000;
	    int left_val = maxPathSum2(root->left);
		int right_val = maxPathSum2(root->right);
		int res = max({left_val + root->val, right_val + root->val, root->val});

		ans = max(res, ans);
		ans = max(ans, root->val + left_val + right_val);
		return res;
	}
public:
    int maxPathSum(TreeNode* root) {
		maxPathSum2(root);
		return ans;
    }
};
