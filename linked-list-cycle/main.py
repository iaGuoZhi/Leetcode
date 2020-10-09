# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return False

        fast = head.next.next
        low = head.next

        while fast is not low:
            if fast is None or fast.next is None:
                return False
            fast = fast.next.next
            low = low.next
        
        return True