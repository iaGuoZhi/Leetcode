class Solution {
public:
	vector<int> f;

	void init(int n)
	{
		f.resize(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			f[i] = i;
		}
	}

	int find(int u)
	{
		while(f[u] != u)
			u = f[u];
		return u;
	}

	void Union(int u, int v)
	{
		int pu = find(u), pv = find(v);
		f[pu] = pv;
	}

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		init(n);
		for (int i = 0; i < n; ++i)
		{
			pipes.push_back(vector<int>{0, i + 1, wells[i]});
		}
		sort(pipes.begin(), pipes.end(), [](const vector<int> &a, const vector<int> &b) {
				return a[2] < b[2];
		});
		int ret = 0;
		for (auto pipe: pipes)
		{
			if (find(pipe[0]) != find(pipe[1]))
            {
				Union(pipe[0], pipe[1]);
			    ret += pipe[2];
            }
		}
		return ret;
    }
};

