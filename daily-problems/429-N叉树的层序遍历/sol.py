"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []

        ans = list()
        q = deque([root])

        while q:
            q_len = len(q)
            level = list()
            for _ in range(q_len):
                node = q.popleft()
                level.append(node.val)
                for c_node in node.children:
                    q.append(c_node)
            ans.append(level)

        return ans
