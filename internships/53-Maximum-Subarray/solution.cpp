class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int ans = INT_MIN, sum = 0;
		for (int i = 0; i < len; ++i)
		{
			if (sum < 0)
				sum = 0;
			sum += nums[i];
			if (sum > ans)
				ans = sum;
		}
		return ans;
    }
};
