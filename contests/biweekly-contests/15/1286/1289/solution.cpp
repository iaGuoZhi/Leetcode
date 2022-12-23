class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
		for (int i = 1; i < grid.size(); ++i)
		{
			int min_1 = -1, min_2 = -1;
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (min_1 == -1 || grid[i - 1][min_1] > grid[i - 1][j])
					min_1 = j;
				else {
					if (min_2 == -1 || grid[i - 1][min_2] > grid[i - 1][j])
						min_2 = j;
				}
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (j != min_1)
					grid[i][j] += grid[i - 1][min_1];
				else
					grid[i][j] += grid[i - 1][min_2];
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < grid[0].size(); ++i)
		{
			ans = min(ans, grid[grid.size() - 1][i]);
		}
		return ans;
    }
};
