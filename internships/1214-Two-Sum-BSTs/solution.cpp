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
	map<int, int> tables1, tables2;
	void walk(TreeNode *root, map<int, int> &tables)
	{
		if (root == NULL)
			return;
		tables[root->val] += 1;
		walk(root->left, tables);
		walk(root->right, tables);
	}
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		int num = 0;
		walk(root1, tables1);
		walk(root2, tables2);

		for (auto it: tables1)
		{
			if (tables2[target - it.first] == 1)
				num++;
		}
        cout << num;
		return num != 0;
    }
};

