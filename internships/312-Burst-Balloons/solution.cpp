class Solution {
public:
    int maxCoins(vector<int>& nums) {
		vector<int> balloons(nums.size() + 2, 0);
		vector<vector<int>> scores(nums.size() + 2, vector<int>(nums.size() + 2, 0));
		int ans = 0;
		balloons[0] = 1;
		balloons[nums.size() + 1] = 1;
		for (int i = 0; i < nums.size(); ++i)
			balloons[i + 1] = nums[i];

		for (int i = scores.size() - 3; i >= 0; --i)
		{
			for (int j = 2; j < scores.size(); ++j)
			{
				for (int k = i + 1; k < j; ++k)
				{
					int num = balloons[i] * balloons[j] * balloons[k];
					num += (scores[i][k] + scores[k][j]);
					scores[i][j] = max(scores[i][j], num);
					ans = max(scores[i][j], ans);
				}
			}
		}
		return scores[0][nums.size() + 1];
    }
};

