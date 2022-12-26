class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
		int xy = 0, xz = 0, yz = 0;

		for (auto g : grid)
			for (auto num : g)
				if (num)
					xy++;

		for (auto g : grid)
		{
			int high = 0;
			for (auto num : g)
				high = max(high, num);
			xz += high;
		}

		for (int i = 0; i < grid[0].size(); ++i)
		{
			int high = 0;
			for (int j = 0; j < grid.size(); ++j)
				high = max(grid[j][i], high);
			yz += high;
		}

		return xy + xz + yz;
    }
};
