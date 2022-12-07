class Solution {
	map<char, int> ori, cur;

	bool check()
	{
		for (auto it : ori)
		{
			if (it.second > cur[it.first])
				return false;
		}
		return true;
	}

public:
    string minWindow(string s, string t) {
		int l = 0, r = -1, len = INT_MAX, ans_l = -1;
		for (char c: t)
		{
			ori[c]++;
		}

		while (l < s.size() && r < s.size())
		{
			while(r < s.size())
			{
			    cur[t[r++]] += 1;
			    if (check())
			    	break;
			}

			while(check())
			{
			    if (r - l + 1 < len)
			    {
			    	len = r - l + 1;
			    	ans_l = l;
			    }
				cur[t[l++]] -= 1;
			}
		}

		if (ans_l == -1)
			return "";
		return s.substr(ans_l, len);
    }
};
