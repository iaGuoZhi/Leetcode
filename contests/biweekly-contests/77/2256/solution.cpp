#include <cstdlib>
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
		long long left = 0, right = 0;
        for (auto num : nums)
            left += (long long) num;
		long long min = left / nums.size();
        long long len = nums.size();
		long long ans = nums.size() - 1;

		for (long long i = nums.size() - 2; i >= 0; --i)
		{
			long long val;
			left -= nums[i + 1];
			right += nums[i + 1];
			
			val = abs((long long)(left / (i + 1) - right / (len - i - 1)));
		    if (val <= min)
			{
				min = val;
				ans = i;
			}
		}
		return ans;
    }
};

