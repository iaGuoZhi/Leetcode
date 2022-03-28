class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        i = 0
        old_i = -1
        while n > 0 :
            i = n % 2
            if i == old_i:
                return False
            old_i = i
            n = n // 2
        return True
