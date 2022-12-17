class Solution {
public:
    bool isOneEditDistance(string s, string t) {
		int s_begin = 0, t_begin = 0;
		int s_len = s.size(), t_len = t.size();
		int max_len = max(s_len, t_len);
		int step = 0;

		while(s_begin < max_len && t_begin < max_len)
		{
			if (s_begin >= s_len || t_begin >= t_len || s[s_begin] != t[t_begin])
			{
				if (step == 1)
					return false;
				if (s_len >= t_len)
					s_begin++;
				if (s_len <= t_len)
					t_begin++;
				step += 1;
			} else {
			    s_begin++;
			    t_begin++;
			}
		}

		return step == 1;
    }
};
