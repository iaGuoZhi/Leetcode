class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> tables(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == 0)
					tables[i][j] = 1;
				else
					tables[i][j] = tables[i - 1][j] + tables[i][j - 1];
			}
		}
		return tables[m - 1][n - 1];
    }
};
