class Solution {
public:
    int minimumTime(string s) {
		int n = s.size();
		vector<int> left_r(n, 0), left_k(n, 0), right_r(n, 0), right_k(n, 0);
		int ans = s.size();

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '1')
			{
				left_k[i] = (i == 0) ? 1 : left_k[i - 1] + 2;

				if (left_k[i] > i + 1)
				{
					left_k[i] = i + 1;
				}
			} else {
				left_k[i] = (i == 0) ? 0 : left_k[i - 1];
			}
		}
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] == '1')
			{
				right_k[i] = (i == s.size() - 1) ? 1 : right_k[i + 1] + 2;

				if (right_k[i] > s.size() - i)
				{
					right_k[i] = s.size() - i;
				}
			} else {
				right_k[i] = (i == s.size() - 1) ? 0 : right_k[i + 1];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			int val = left_k[i];
			if (i < n - 1)
				val += right_k[i + 1];
			ans = min(val, ans);
		}
		return ans;
    }
};
