from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def backtrace(nums: List[int], tmp : List[int]):
            if(len(nums)==0):
                res.append(tmp)
            for i in range(len(nums)):
                backtrace(nums[:i]+nums[i+1:], tmp+nums[i:i+1])
        backtrace(nums, [])
        return res

if __name__ == "__main__":
    nums = [1,2,3,5]
    print(Solution.permute(nums))