class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
		vector<vector<int>> homes;
		vector<int> xhomes, yhomes;
		int mx = 0, my = 0;
		int m = grid.size(), n = grid[0].size();
		int ans = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
				{
					homes.push_back({j, i});
					xhomes.push_back(j);
					yhomes.push_back(i);
				}
			}
		}

		int sz = homes.size();
		sort(xhomes.begin(), xhomes.end());
		sort(yhomes.begin(), yhomes.end());
		mx = xhomes[sz / 2];
		my = yhomes[sz / 2];

		for (auto home: homes)
		{
			ans += abs(home[0] - mx);
			ans += abs(home[1] - my);
		}

		return ans;
    }
};
