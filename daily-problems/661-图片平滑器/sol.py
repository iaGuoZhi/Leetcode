class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        ans = [[0] * n for _ in range(m)]
        for x in range(m):
            for y in range(n):
                num = 0
                summ = 0
                for i in range(max(x - 1, 0), min(x + 2, m)):
                    for j in range(max(y - 1, 0), min(y + 2, n)):
                        num += 1
                        summ += img[i][j]
                ans[x][y] = summ // num
        return ans
