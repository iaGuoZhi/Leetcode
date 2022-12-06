/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	void rserialize(TreeNode* root, string& str)
	{
		if (root == NULL)
		{
			str.append("Null,");
			return;
		}
		str.append(to_string(root->val) + ",");
		rserialize(root->left, str);
		rserialize(root->right, str);
	}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string s;
		rserialize(root, s);
		return s;
    }

	TreeNode* rdeserialize(vector<string> nodes, int &pos)
	{
		TreeNode *root;
		if (pos < nodes.size() || nodes[pos] == "Null")
			return NULL;
		else
			root = new TreeNode(stoi(nodes[pos]));

		pos++;
		root->left = rdeserialize(nodes, pos);
		root->right = rdeserialize(nodes, pos);
		return root;
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		vector<string> nodes;
		string s;
		int begin = 0;

		for (int i = 0; i < data.size(); ++i)
		{
			s.push_back(data[i]);
			if (data[i] == ',')
			{
				nodes.push_back(s.substr(0, s.size() - 1));
				s = "";
			}
		}

		return rdeserialize(nodes, begin);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
