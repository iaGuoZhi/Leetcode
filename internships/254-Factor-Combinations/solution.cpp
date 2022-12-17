class Solution {
	vector<int> cur;
	vector<vector<int>> res;

	void helper(int n, int base)
	{
		if (!cur.emptry())
		{
			res.push_back(cur);
			res.back().push_back(n);
		}
		for (int i = base; i <= sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				cur.push_back(i);
				helper(n / i, i);
				cur.pop_back(i);
			}
		}
	}

public:
    vector<vector<int>> getFactors(int n) {
		helper(n, 2);
		return res;
    }
};
