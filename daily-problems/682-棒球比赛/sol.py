class Solution:
    def calPoints(self, ops: List[str]) -> int:
        scores = []
        for s in ops:
            if s == "C":
                scores = scores[:-1]
                continue
            if s == "D":
                scores.append(scores[-1] * 2)
                continue
            if s == "+":
                scores.append(scores[-1] + scores[-2])
                continue
            scores.append(int(s))

        ans = 0
        for score in scores:
            ans += score

        return ans

