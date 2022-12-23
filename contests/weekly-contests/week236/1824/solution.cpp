class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
		int n = obstacles.size();
		vector<vector<int>> steps(n, vector<int>(3, -1));
		int ans = INT_MAX;

		steps[0][1] = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i > 0 && obstacles[i] != j + 1)
					steps[i][j] = steps[i - 1][j];
			}

			for (int j = 0; j < 3; ++j)
            {
				if (steps[i][j] != -1)
				{
					for (int k = 1; k <= 2; ++k)
					{
						if(obstacles[i] != ((j + k) % 3 + 1))
						{
							if (steps[i][(j + k) % 3] == -1)
								steps[i][(j + k) % 3] = steps[i][j] + 1;
							else
								steps[i][(j + k) % 3] = min(steps[i][(j + k) % 3], steps[i][j] + 1);
						}
					}
				}
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			if (steps[n - 1][i] != -1)
			    ans = min(ans, steps[n - 1][i]);
		}
		return ans;
    }
};

