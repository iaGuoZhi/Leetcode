class Solution {
	int get(string s)
	{
		for (int i = 0; i < string.size(); ++i)
		{
			if (!(s[i] >= '0' && s[i] <= '9'))
				return s.size();
		}
		return atoi(s);
	}

public:
    int maximumValue(vector<string>& strs) {
		int ans = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			ans = max(ans, get(strs[i])):
		}
		return ans;
    }
};

