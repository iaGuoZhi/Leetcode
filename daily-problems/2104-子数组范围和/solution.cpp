class Solution {
    long long subArrayRanges(vector<int> &nums, int begin, int end)
    {
        int i;
        long long cur_max, cur_min;
        long long res = 0;
        if(begin >= end)
            return 0;

        cur_max = (long long)nums[end];
        cur_min = (long long)nums[end];
        for(i = end - 1; i >= begin; --i)
        {
            cur_max = cur_max > nums[i] ? cur_max : (long long) nums[i];
            cur_min = cur_min < nums[i] ? cur_min : (long long) nums[i];
            res += (cur_max - cur_min);
        }

        res += subArrayRanges(nums, begin, end - 1);
        return res;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return subArrayRanges(nums, 0, nums.size() - 1);
    }
};

