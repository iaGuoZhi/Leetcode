class Solution {
public:
    bool splitArray(vector<int>& nums) {
		vector<int> sums;
		int len = nums.size();
		int base;
		sums.push_back(0);
		for (int num: nums)
		{
			sums.push_back(sums[sums.size() - 1] + num);
		}
		base = sums[len] / 4;
		for (int i = 1; i < len; i++)
		{
			for (int j = i + 2; j < len; j++)
			{
				for (int k = j + 2; k < len; ++k)
				{
					if (sums[i] == sums[j] - sums[i + 1] && sums[i] == sums[k] - sums[j + 1]
							&& sums[i] == sums[len] - sums[k + 1])
						return true;
				}
			}
		}
		return false;
    }
};

