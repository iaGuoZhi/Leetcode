class Solution {
public:
    string removeOccurrences(string s, string part) {
		int s_len = s.size(), p_len = part.size();
		string ans = s;

		int i = 0;
		while (i <= ((int)ans.size()) - p_len)
		{
			if (ans.substr(i, p_len) == part)
			{
				ans.erase(i, p_len);
			    i = max(-1, i - p_len);
			}
			i++;
		}
        return ans;
    }
};

