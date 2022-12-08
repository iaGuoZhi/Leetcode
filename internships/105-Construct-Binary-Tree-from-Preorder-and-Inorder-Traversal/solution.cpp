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
	map<int, int> tables;
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
		if (pre_left > pre_right)
			return NULL;

		int val = preorder[pre_left];
		TreeNode *root = new TreeNode(val);
		int idx = tables[val];
		root->left = myBuildTree(preorder, inorder, pre_left + 1, pre_left + idx - in_left, in_left, idx - 1);
		root->right = myBuildTree(preorder, inorder, pre_left + idx - in_left + 1, pre_right, idx + 1, in_right);
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();

		for (int i = 0; i < len; i++)
			tables[inorder[i]] = i;

		return myBuildTree(preorder, inorder, 0, len - 1, 0, len - 1);
    }
};
