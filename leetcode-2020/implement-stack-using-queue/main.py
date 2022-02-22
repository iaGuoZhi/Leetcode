class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q=[]


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        Len = len(self.q)
        while Len>1:
            self.q.append(self.q.pop(0))
            Len-=1


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.q)

obj = MyStack()
obj.push(124)
print(obj.top())
p1=obj.pop()
print(obj.empty())
