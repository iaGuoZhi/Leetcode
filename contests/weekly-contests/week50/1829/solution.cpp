class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int base = 0, mask = (1 << maximumBit) - 1;
		vector<int> ans;
		for (auto num : nums)
		{
			base = base ^ num;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			ans.push_back(base ^ mask);
			sum ^= nums[nums.size() - 1 - i];
		}

		return ans;
	}
};
