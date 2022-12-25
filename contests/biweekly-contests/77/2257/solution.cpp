class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		vector<vector<int>> grids(m, vector<int>(n, 0));
		int ans = 0;
		for (auto guard : guards)
			grids[guard[0]guard[1]] = 2;
		for (auto wall : walls)
			grids[wall[0]wall[1]] = 3;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				bool has_guard = false;
				if (has_guard && grids[i][j] == 0)
					grids[i][j] = 1;
				if (grids[i][j] = 2)
					has_guard = true;
				if (grids[i][j] = 3)
					has_guard = false;
			}
			for (int j = n - 1; j >= 0; --j)
			{
				bool has_guard = false;
				if (has_guard && grids[i][j] == 0)
					grids[i][j] = 1;
				if (grids[i][j] = 2)
					has_guard = true;
				if (grids[i][j] = 3)
					has_guard = false;
			}
		}

		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < m; ++i)
			{
				bool has_guard = false;
				if (has_guard && grids[i][j] == 0)
					grids[i][j] = 1;
				if (grids[i][j] = 2)
					has_guard = true;
				if (grids[i][j] = 3)
					has_guard = false;
			}
			for (int i = m - 1; i >= 0; --i)
			{
				bool has_guard = false;
				if (has_guard && grids[i][j] == 0)
					grids[i][j] = 1;
				if (grids[i][j] = 2)
					has_guard = true;
				if (grids[i][j] = 3)
					has_guard = false;
			}
		}

		for (auto grid : grids)
			for (auto num : grid)
				if (num == 0)
					ans++;
        
		return ans;
    }
};
