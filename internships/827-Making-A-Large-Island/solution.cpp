class Solution {
	void dfs(vector<vector<int>> & grid, int row, int column, vector<pair<int, int>> &paths)
	{
		if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] != 1)
			return;

		paths.push_back({row, column});
		grid[row][column] = 0;

		for (int k = -1; k <= 1; k++)
		{
			for (int t = -1; t <= 1; t++)
			{
				if (k != t && k + t != 0 && row + k >= 0 && row + k < grid.size() && column + t >= 0 && column + t < grid[0].size())
				{
					dfs(grid, row + k, column + t, paths);
				}
			}
		}
	}
public:
    int largestIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> maps(m * n + 2, 0);
		int base = 2;
		int ans = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				vector<pair<int, int>> paths;
				dfs(grid, i, j, paths);
				for (int k = 0; k < paths.size(); k++)
				{
					auto [row, column] = paths[k];
					maps[base] = paths.size();
					grid[row][column] = base;
				}
				if (paths.size())
					base++;
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 0)
				{
					int num = 0;
					vector<int> neighbors;
					for (int k = -1; k <= 1; k++)
					{
						for (int t = -1; t <= 1; t++)
						{
							if (k != t && k + t != 0 && i + k >= 0 && i + k < m && j + t >= 0 && j + t < n && grid[i + k][j + t] != 0!= 0)
							{
								neighbors.push_back(grid[i + k][j + t]);
							}
						}
					}
					sort(neighbors.begin(), neighbors.end());
					for (int k = 0; k < neighbors.size(); ++k)
					{
						num += maps[neighbors[k]];
						if (k < neighbors.size() - 1 && neighbors[k] == neighbors[k + 1])
							k++;
					}
					ans = max(num + 1, ans);
				}
			}
		}
		if (ans == 0 && grid[0][0] != 0)
			ans = m * n;
		return ans;
    }
};
