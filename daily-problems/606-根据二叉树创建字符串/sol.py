# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        ans = ""
        st = [root]
        vis = set()
        while st:
            node = st[-1]
            if node in vis:
                if node != root:
                    ans += ")"
                st.pop()
            else:
                vis.add(node)
                if node != root:
                    ans += "("
                ans += str(node.val)
                if node.left is None and node.right:
                    ans += "()"
                if node.right:
                    st.append(node.right)
                if node.left:
                    st.append(node.left)
        return ans
