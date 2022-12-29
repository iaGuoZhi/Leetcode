/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
		vector<vector<int>> nums;
		int n = 0;

		while(head)
		{
			vector<int> cur;
			for (int i = 0; i < n + 1; ++i)
			{
				cur.push_back(head->val);
				head = head->next;
				if (!head)
					break;
			}
			nums.push_back(cur);
			n++;
		}

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i].size() % 2 == 0)
				reverse(nums[i].begin(), nums[i].end());

		ListNode *root = NULL, *tail;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < nums[i].size(); ++j)
			    if (!root)
				{
					root = new ListNode(nums[i][j]);
					tail = root;
				} else {
					tail->next = new ListNode(nums[i][j]);
					tail = tail->next;
				}
		}

		return root;
    }
};

