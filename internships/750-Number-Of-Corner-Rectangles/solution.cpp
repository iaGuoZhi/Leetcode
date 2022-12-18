class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> counts(n, vector<int>(n, 0));
		int ans = 0;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j])
				{
					for (int k = j + 1; k < n; ++k)
					{
						if (grid[i][k])
						{
							ans += counts[j][k];
							counts[j][k] += 1;
						}
					}
				}
			}
		}

		return ans;
    }
};
