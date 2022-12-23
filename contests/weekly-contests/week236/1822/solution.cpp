class Solution {
public:
    int arraySign(vector<int>& nums) {
		int cnt = 0;
		for (auto num : nums)
		{
			if (num == 0)
				return 0;
			if (num < 0)
				cnt++;
		}

		if (cnt % 2 == 0)
			return 1;
		return -1;
    }
};
