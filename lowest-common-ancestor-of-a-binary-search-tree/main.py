class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        temp = None
        if p.val > q.val:
            temp = q
            q = p
            p = temp
        
        if p.val<= root.val<=q.val:
            return root
        
        if root.val<p.val<q.val:
            return self.lowestCommonAncestor(root.right, p, q)

        if p.val<q.val<root.val:
            return self.lowestCommonAncestor(root.left, p, q)
