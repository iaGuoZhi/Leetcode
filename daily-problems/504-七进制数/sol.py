class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        if num < 0:
            num = abs(num)
            flag = 1
        ans = []
        while num > 0:
            ans.append(str(num % 7))
            num //= 7
        if flag:
            num.append('-')
        ans = ans[::- 1]
        return ''.join(ans)
