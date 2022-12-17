class Solution {
	int ans = 0;
	bool visited[9] = {false};
	void bfs(int pos, int m, int n, int len)
	{
		int r = pos / 3, c = pos % 3;

        if (len >= n)
			return;

		visited[pos] = true;
		len++;
		if (len >=m)
			ans++;

		for (int i = 0; i < 9; ++i)
		{
			if (visited[i])
				continue;
			int ir = i / 3, ic = i % 3;
			int midr = (r + ir) / 2, midc = (c + ic) / 2;
			if ((((midr != r && midr != ir) || (midc != c && midc != ic)) && ((r + ir) % 2 == 0) && ((c + ic) % 2 == 0)) && !visited[midr * 3 + midc])
				continue;
			bfs(i, m, n, len);
		}
		visited[pos] = false;
		len--;
	}

public:
    int numberOfPatterns(int m, int n) {
		for (int i = 0; i < 9; ++i)
			bfs(i, m, n, 0);
		return ans;
    }
};
