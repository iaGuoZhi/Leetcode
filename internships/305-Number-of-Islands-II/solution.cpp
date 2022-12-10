class UnionFind {
	int cnt = 0;
	vector<int> nums;

public:
	UnionFind(int n)
	{
		nums.resize(n);
		for(int i = 0; i < n; ++i)
			nums[i] = i;
	}

	int find(int x)
	{
		while (nums[x] != x)
		{
			x = nums[x];
		}
		return x;
	}

	void Union(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if (fx == fy)
			return;
		nums[fx] = fy;
		cnt--;
	}

	bool connect(int x, int y)
	{
		return find(x) == find(y);
	}

	void add()
	{
		cnt++;
	}

	int Cnt()
	{
		return cnt;
	}
};
class Solution {
public:
    int m,n;
    vector <int> dx = {0,0,-1,1},dy = {1,-1,0,0};
    bool inGrid (int x,int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    vector<int> numIslands2(int _m, int _n, vector<vector<int>>& positions) {
		m = _m;
		n = _n;
		vector<int> ans;
		vector<bool> visited(m * n, false);

		UnionFind unionfind(m * n);
		for (int i = 0; i < positions.size(); i++)
		{
			if (!visited[positions[i][0] * n + positions[i][1]])
			    unionfind.add();
			visited[positions[i][0] * n + positions[i][1]] = true;
			for (int k = 0; k < 4; k++)
			{
				if (inGrid(positions[i][0] + dx[k], positions[i][1] + dy[k])
						&& visited[(positions[i][0] + dx[k]) * n + positions[i][1] + dy[k]])
				{
			        unionfind.Union(positions[i][0] * n + positions[i][1], (positions[i][0] + dx[k]) * n + positions[i][1] + dy[k]);
				}
			}
			ans.push_back(unionfind.Cnt());
		}
		return ans;
	}
};
