class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        ans = []
        non_exist = []
        size = m + n
        total = size * mean
        m_total = 0
        n_total = 0

        for i in rolls:
            m_total += i
        n_total = total - m_total

        while n_total > 0:
            cur = n_total / n
            if cur > 6 or cur < 1:
                return non_exist
            ans.append(int(cur))
            n_total -= int(cur)
            n -= 1

        return ans
