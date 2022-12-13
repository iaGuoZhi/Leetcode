class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
		vector<vector<int>> tables(vals.size(), vector<int>());
		int ans = INT_MIN;

		for (int i = 0; i < edges.size(); ++i)
		{
            if (vals[edges[i][1]] > 0)
			    tables[edges[i][0]].push_back(vals[edges[i][1]]);
            if (vals[edges[i][0]] > 0)
			    tables[edges[i][1]].push_back(vals[edges[i][0]]);
		}

		for (int i = 0; i < vals.size(); ++i)
		{
			sort(tables[i].begin(), tables[i].end(), std::greater<>());
		}

		for (int i = 0; i < vals.size(); ++i)
		{
			int cur = 0;
			cur += vals[i];
			for (int j = 0; j < k; ++j)
			{
				if (j >= tables[i].size() || tables[i][j] <= 0)
                    break;
				cur += tables[i][j];
			}
			ans = max(cur, ans);
		}
		return ans;
    }
};
