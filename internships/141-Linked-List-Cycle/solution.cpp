/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *quick = head, *slow = head;
		while (slow)
		{
		    slow = slow->next;
		    quick = quick->next;
			if (quick != NULL)
				quick = quick->next;
		    if (quick == NULL || slow == NULL)
		    	return false;
		    if (quick == slow)
		    	return true;
		}
		return false;
    }
};
