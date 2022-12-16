class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
		int slot = nums.size() / k;
		map<int, int> mp;
		for (auto num: nums)
			mp[num]++;

		for (auto it: mp)
		{
			if (it.second > slot)
				return false;
		}

		return true;
    }
};
