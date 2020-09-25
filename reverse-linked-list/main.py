
class ListNode:
    def __init__(self, x):
       self.val = x
       self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        node = head
        while node:
            tmp = node.next
            node.next=pre
            pre=node
            node=tmp
        return pre