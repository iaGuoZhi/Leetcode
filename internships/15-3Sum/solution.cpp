class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> ans;
		int sum = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1, k = len - 1;
			while(j < k)
			{
				sum = nums[i] + nums[j] + nums[k];
				if (sum == 0)
				{
					ans.push_back({nums[i], nums[j], nums[k]});
					while (j < len - 1 && nums[j] == nums[j + 1])
						j++;
					while (k > i + 1 && nums[k] == nums[k - 1])
						k--;
					j++;
					k--;
				}
				if (sum > 0)
					k--;
				if (sum < 0)
					j++;
			}
		}
		return ans;
    }
};
