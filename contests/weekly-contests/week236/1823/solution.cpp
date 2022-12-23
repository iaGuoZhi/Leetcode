class Solution {
public:
    int findTheWinner(int n, int k) {
		vector<bool> visited(n, false);
		int cnt = n;
		int pos = 0;

		while (cnt > 1)
		{
			int cur = k;
			while (cur >= 1)
			{
				if (!visited[pos])
				{
                    if (cur == 1)
                        break;
					cur--;
				}
				pos = (pos + 1) % n;
			}
			visited[pos] = true;
			pos = (pos + 1) % n;
			cnt--;
		}

		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
				return i + 1;
		}

		return -1;
    }
};

