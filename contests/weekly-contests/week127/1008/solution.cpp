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
	TreeNode* help(vector<int>& preorder, int begin, int end)
	{
		TreeNode *root;
		int i;
		if (begin > end)
			return NULL;

		root = new TreeNode(preorder[begin]);
		for (i = begin + 1; i <= end; ++i)
			if (preorder[i] > preorder[begin])
				break;
		root->left = help(preorder, begin + 1, i - 1);
		root->right = help(preorder, i, end);
		return root;
	}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		return help(preorder, 0, preorder.size() - 1);
    }
};
