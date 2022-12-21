class Solution {
public:
    int minOperations(vector<int>& nums) {
		int base = nums[0];
		int ans = 0;

		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] < base + 1)
				ans += (base + 1 - nums[i]);
			base = max(base + 1, nums[i]);
		}

		return ans;

    }
};
