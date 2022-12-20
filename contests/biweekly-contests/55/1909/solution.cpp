class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
		bool ans = true;
		int cnt = 0;
		int skip = -1;

		for (int i = 1; i < nums.size(); ++i)
		{
			int t = i - 1;
			if (skip == t)
				t = t - 1;
			if (nums[i] <= nums[t])
			{
				if (skip != -1)
					return false;
				if (i == 1)
                {
					skip = t;
                    continue;
                }
				if (nums[i] <= nums[t] && nums[i] <= nums[t - 1])
					skip = i;
				else
					skip = t;
			}
		}
		return ans;
    }
};

