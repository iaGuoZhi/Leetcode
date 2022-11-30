class Solution {
	vector<string> recursion(string s, int n)
	{
		int left_cnt = 0, right_cnt = 0;
		vector<string> res;
		string ans;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				left_cnt++;
			}
			if (s[i] == ')')
			{
				right_cnt++;
			}
		}
		if (left_cnt > right_cnt)
		{
			ans = s;
			ans.push_back(')');
			res.push_back(ans);
		}
		if (left_cnt < n)
		{
			ans = s;
			ans.push_back('(');
			res.push_back(ans);
		}
		return res;
	}

public:
    vector<string> generateParenthesis(int n) {
		int i = 0;
		vector<string> res, ans;
		res.push_back("");
		while (i < 2 * n)
		{
			vector<string> ans;
			for (int j = 0; j < res.size(); ++j)
			{
				vector<string> cur_ans = recursion(res[j],  n);
				ans.insert(ans.end(), cur_ans.begin(), cur_ans.end());
			}
			i = i + 1;
            cout << ans.size();
			res = ans;
		}

		return res;
    }
};

