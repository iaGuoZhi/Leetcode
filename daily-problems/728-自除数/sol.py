class Solution:
    def isSelfDevided(self, num: int) -> bool:
        n = num
        if n == 0:
            return False
        while n:
            if n % 10 == 0:
                break
            if(num % (n % 10) != 0) :
                break
            n = n // 10
        if n == 0:
            return True
        return False

    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for i in range(left, right + 1):
            if self.isSelfDevided(i):
                ans.append(i)
        return ans
