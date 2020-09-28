
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True 
        num1 = []
        num2 = []

        self.leftSearch(root.left, num1)
        self.rightSearch(root.right, num2)
        print(num1)
        print(num2)
        return num2==num1

    def leftSearch(self, node: TreeNode, nums: []):
        if not node:
            nums.append(' ')
            return
        nums.append(node.val)
        self.leftSearch(node.left, nums)
        self.leftSearch(node.right, nums)

    def rightSearch(self, node: TreeNode, nums:[]):
        if not node:
            nums.append(' ')
            return
        nums.append(node.val)
        self.rightSearch(node.right, nums)
        self.rightSearch(node.left, nums)