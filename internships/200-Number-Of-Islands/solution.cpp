class Solution {
	void dfs(vector<vector<char>>& grid, int row, int column)
	{
		if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == '0')
			return;

		grid[row][column] = '0';
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i != j && i + j != 0)
				{
					dfs(grid, row + i, column + j);
				}
			}
		}
	}
public:
    int numIslands(vector<vector<char>>& grid) {
		int num = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
				{
					num++;
				    dfs(grid, i, j);
				}
			}
		}
		return num;
    }
};
