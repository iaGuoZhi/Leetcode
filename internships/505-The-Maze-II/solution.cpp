class Solution {
	int m, n;
	int x[4] = {0, 0, 1, -1};
	int y[4] = {1, -1, 0, 0};
	bool inGrid(int i, int j)
	{
		return i >= 0 && i < m && j >= 0 && j < n;
	}
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int ans = 0;
		queue<vector<int>> q;

		m = maze.size();
		n = maze[0].size();

		q.push_back(start);
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; ++i)
			{
			    auto point = q.top();
			    q.pop();
				if (point == destination)
					return ans;
				for (int j = 0; j < 4; ++j)
				{
					if (inGrid(point[0] + x[j], point[1] + y[j]) && maze[point[0] + x[j]][point[1] + y[j]] == 0)
					{
						q.push({point[0] + x[j], point[1] + y[j]});
					}
				}
			}
			++ans;
		}

		return -1;
	}
};
