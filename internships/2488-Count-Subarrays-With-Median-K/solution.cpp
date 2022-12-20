class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		int pos = 0;
		vector<int> compares(n, 0);
		unordered_map<int, int> left;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] < k)
				compares[i] = -1;
			if (nums[i] > k)
				compares[i] = 1;
			if (nums[i] == k)
				pos = i;
		}

		int li = 0, ri = 0;
		for (int i = pos; i >= 0; --i)
		{
			li += compares[i];
			left[li]++;
		}

		for (int j = pos; j < n; ++j)
		{
			ri += compares[j];
			ans += (left[0 - ri] + left[1 - ri]);
		}

		return ans;
    }
};

