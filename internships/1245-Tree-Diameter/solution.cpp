class Solution {
	int max_num = 10010;
	int ans = 0;
	vector<vector<int>> grids;
	vector<int> t1, t2;
	void dfs(int u, int p)
	{
		for (int next: grids[u])
		{
			if (next == p)
				continue;
            dfs(next, u);
			int cur = t1[next] + 1;
			if (cur >= t1[u])
			{
				t2[u] = t1[u];
				t1[u] = cur;
				ans = max(t1[u] + t2[u], ans);
			} else if (cur > t2[u])
			{
				t2[u] = cur;
				ans = max(t1[u] + t2[u], ans);
			}
		}
	}


public:
    int treeDiameter(vector<vector<int>>& edges) {
        grids.resize(max_num);
        t1.resize(max_num);
        t2.resize(max_num);
		for (int i = 0; i < edges.size(); ++i)
		{
			grids[edges[i][0]].push_back(edges[i][1]);
			grids[edges[i][1]].push_back(edges[i][0]);
		}
		dfs(0, -1);
		return ans;
    }
};

