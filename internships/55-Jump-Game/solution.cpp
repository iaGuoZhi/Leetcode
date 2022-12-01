class Solution {
public:
    bool canJump(vector<int>& nums) {
		int len = nums.size();
		int begin_val = 0, begin_idx = 0;
		for (int i = 0; i < len; ++i)
		{
			if (begin_val < i - begin_idx)
				return false;
			if (begin_val - nums[i] < i - begin_idx)
			{
				begin_idx = i;
				begin_val = nums[i];
			}
		}

		return true;
    }
};
