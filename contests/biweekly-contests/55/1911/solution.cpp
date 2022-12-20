class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
		long long to_add = 0, to_minus = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			to_add = max(to_add, to_minus - (long long)nums[i]);
			to_minus = max(to_minus, to_add + (long long)nums[i]);
		}
		return max(to_add, to_minus);
    }
};

