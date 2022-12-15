class Solution {
	vector<vector<int>> grids;
	vector<int> in;
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
		grids.resize(n + 1);
		in.resize(n + 1);
		queue<int> q;
		int ans = 0;

		for (int i = 0; i < relations.size(); ++i)
		{
			grids[relations[i][0]].push_back(relations[i][1]);
			in[relations[i][1]]++;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}

		while (q.size())
		{
			int sz = q.size();
			for (int j = 0; j < sz; ++j)
			{
			    int cur = q.front();
			    q.pop();
			    for (int i = 0; i < grids[cur].size(); ++i)
			    {
			    	in[grids[cur][i]]--;
			    	if (in[grids[cur][i]] == 0)
			    	{
			    		q.push(grids[cur][i]);
			    	}
			    }
			}
			ans++;
		}

		for (int i = 1; i <= n; ++i)
			if (in[i])
				return -1;
		return ans;
    }
};

