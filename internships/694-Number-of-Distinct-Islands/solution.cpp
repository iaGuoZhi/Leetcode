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

	map<int, vector<int>> dump()
	{
		map<int, vector<int>> mp;

		for (int i = 0; i < nums.size(); ++i)
		{
			mp[find(i)].push_back(i);
		}

		return mp;
	}
};

class Solution {
public:
    int m,n;
    vector <int> dx = {0,0,-1,1},dy = {1,-1,0,0};
    bool inGrid (int x,int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

	bool equal(vector<int> &nums1, vector<int> &nums2)
	{
		if (nums1.size() != nums2.size())
			return false;
		int raw_distance = nums2[0] / n - nums1[0] / n;
		int column_distance = nums2[0] % n - nums1[0] % n;

		for (int i = 1; i < nums1.size(); ++i)
		{
			if (nums2[i] / n - nums1[i] / n != raw_distance || nums2[i] % n - nums1[i] % n != column_distance)
				return false;
		}
		return true;
	}

    int numDistinctIslands(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		vector<bool> visited(m * n, false);
		map<int, vector<int>> mp;
		vector<vector<int>> arrs;
		int ans = 0;

		UnionFind unionfind(m * n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
			    if (grid[i][j] != 1)
                    continue;
				unionfind.add();
				visited[i * n + j] = true;

				for (int k = 0; k < 4; k++)
				{
					if(inGrid(i + dx[k], j + dy[k]) && visited[(i + dx[k]) * n + j + dy[k]] && grid[i + dx[k]][j + dy[k]] == 1)
						unionfind.Union(i * n + j, (i + dx[k]) * n + j + dy[k]);
				}
			}
		}

		mp = unionfind.dump();

		for (auto it : mp)
		{
			if (grid[it.first / n][it.first % n] == 1)
			{
			    arrs.push_back(it.second);
			    sort(arrs[arrs.size() - 1].begin(), arrs[arrs.size() - 1].end());
			}
		}

		for(int i = 0; i < arrs.size(); ++i)
		{
			bool has_equal = false;
			for (int j = i + 1; j < arrs.size(); ++j)
			{
				if (equal(arrs[i], arrs[j]))
				{
					has_equal = true;
					break;
				}
			}
			if (!has_equal)
			{
				ans++;
			}
		}
		return ans;
    }
};
