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
	vector<int> nums;

	void walk(TreeNode *root)
	{
		if (root == NULL)
			return;
		walk(root->left);
		nums.push_back(root->val);
		walk(root->right);
	}
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
		int l = 0, r = l + k;
		double minK = 0, ans_l = 0;

		walk(root);
		for (int i = l; i < r; i++)
		{
			minK += abs((double)nums[i] - target);
		}

		while (l + k < nums.size())
		{
			double curK = minK;
			curK -= abs((double)nums[l] - target);
			curK += abs((double)nums[r] - target);
			l++;
			r++;
			if (curK < minK)
			{
				minK = curK;
				ans_l = l;
			}
		}

		return vector<int>(&nums[ans_l], &nums[ans_l + k]);
    }
};

