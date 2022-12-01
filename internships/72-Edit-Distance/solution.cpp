class Solution {
public:
    int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> tables(m + 1, vector<int>(n + 1, 0));

		for (int i = 0; i <= m; i++)
			tables[i][0] = i;
		for (int i = 0; i <= n; i++)
			tables[0][i] = i;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					tables[i][j] = min({tables[i - 1][j] + 1, tables[i][j - 1] + 1, tables[i - 1][j - 1]});
				else
					tables[i][j] = min({tables[i - 1][j] + 1, tables[i][j - 1] + 1, tables[i - 1][j - 1] + 1});
			}
		}

		return tables[m][n];
    }
};
