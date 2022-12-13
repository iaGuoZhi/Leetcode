class Node {
public:
	int x;
	int y;
	int val;
	Node(int x, int y, int val): x(x), y(y), val(val){}
	bool operator <(const Node &a) const {
		return this->val < a.val;
	}
};

class Solution {
	int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int ans = INT_MAX;
		priority_queue<Node> q;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		q.push(Node(0, 0, grid[0][0]));
		visited[0][0] = true;

		while(q.size())
		{
			Node cur = q.top();
			q.pop();
			ans = min(ans, cur.val);

			if (cur.x == m - 1 && cur.y == n - 1)
				return ans;

			for (int i = 0; i < 4; ++i)
			{
				int dx = cur.x + xx[i], dy = cur.y + yy[i];
				if (dx < 0 || dx >= m || dy < 0 || dy >= n || visited[dx][dy])
					continue;
				visited[dx][dy] = true;
				q.push(Node(dx, dy, grid[dx][dy]));
			}
		}
		return ans;
	}
};
