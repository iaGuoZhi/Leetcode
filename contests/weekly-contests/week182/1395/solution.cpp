class Solution {
public:
    int numTeams(vector<int>& rating) {
		vector<vector<int>> nums(rating.size(), vector<int>(4, 0));

		for (int i = 0; i < rating.size(); ++i)
		{
			int left_smaller = 0, left_bigger = 0, right_smaller = 0, right_bigger = 0;

			for (int j = 0; j < i; ++j)
				if (rating[j] < rating[i])
					left_smaller++;
				else left_bigger++;
			for (int j = i + 1; j < rating.size(); ++j)
				if (rating[j] < rating[i])
					right_smaller++;
				else right_bigger++;
            nums[i][0] = left_smaller;
            nums[i][1] = left_bigger;
            nums[i][2] = right_smaller;
            nums[i][3] = right_bigger;
		}
		long long ans = 0;
		for (int i = 0; i < rating.size(); ++i)
		{
			ans += nums[i][3] * nums[i][0];
			ans += nums[i][1] * nums[i][2];
		}
		return ans;
    }
};

