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
	ListNode* help(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		ListNode *max = help(head->next);
		if (!max)
			return head;
		if (head->val < max->val)
		{
			return max;
		} else {
            head->next = max;
			return head;
		}
    }

public:
    ListNode* removeNodes(ListNode* head) {
		return help(head);
    }
};

