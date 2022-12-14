class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
		vector<bool> visited(n, false);
		vector<vector<int>> grids(n, vector<int>());
		queue<int> q;

		for (int i = 0; i < edges.size(); ++i)
		{
			grids[edges[i][0]].push_back(edges[i][1]);
			grids[edges[i][1]].push_back(edges[i][0]);
		}

		q.push(0);
		visited[0] = true;
		while (q.size())
		{
			int point = q.front();
			q.pop();
			for (int next : grids[point])
			{
				if (visited[next])
					return false;
				grids[next].erase(remove(grids[next].begin(), grids[next].end(), point), grids[next].end());
				q.push(next);
				visited[next] = true;
			}
		}

		for (bool visit : visited)
		{
			if (!visit)
				return false;
		}
		return true;
    }
};
