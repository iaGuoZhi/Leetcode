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
        let fast = head.next;
        let slow = head;
        while !fast.is_none() && !fast.next.is_none() && fast != slow {
            fast = fast.next.next;
            slow = slow.next;
        }

        if fast == slow {
            return true;
        } else {
            return false;
        }
    }
};
