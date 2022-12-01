class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> tables(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != 0 && j != 0) {
					tables[i][j] = min(tables[i - 1][j], tables[i][j - 1]);
				} else {
					if (i != 0)
						tables[i][j] = tables[i - 1][j];
					if (j != 0)
						tables[i][j] = tables[i][j - 1];
				}
				tables[i][j] += grid[i][j];
			}
		}
		return tables[m - 1][n - 1];
    }
};
