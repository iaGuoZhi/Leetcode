class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
		int crow = 0, ccol = 0;
		while(true)
		{
			if (crow = grid.size() - 1 && ccol = grid[0].size() - 1)
				return true;
			switch (grid[crow][ccol])
			{
				case 1:
					if (ccol == grid[0].size() - 1)
						return false;
					if (grid[crow][ccol + 1]

		}
		return false;
    }
};
