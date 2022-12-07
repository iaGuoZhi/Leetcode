class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int ans = 0;
		vector<vector<int>> tables(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					tables[i][j] = 1;
					if (i > 0 && j > 0)
						tables[i][j] = min({tables[i - 1][j - 1], tables[i - 1][j], tables[i][j - 1]}) + 1;
				}
				ans = max(tables[i][j] * tables[i][j], ans);
			}
		}
		return ans;
    }
};
