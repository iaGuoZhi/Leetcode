class Solution {
	bool isEqual(char s, char p)
	{
		return p == '.' || s == p;
	}
public:
    bool isMatch(string s, string p) {
		s.insert(0, 1, 'a');
		p.insert(0, 1, 'a');
		vector<vector<bool>> table(p.size(), vector<bool>(s.size(), false));

		table[0][0] = true;
		for (int i = 1; i < p.size(); ++i)
		{
			for (int j = 1; j <= s.size(); ++j)
			{
				if (j < s.size() && isEqual(s[j], p[i]))
				{
					table[i][j] = table[i - 1][j - 1];
				}
				if(p[i] == '*')
				{
					// x*: 0 x
					table[i][j - 1] = table[i][j - 1] | table[i - 2][j - 1];
					// x*: n x
					if (j < s.size() && isEqual(s[j], p[i - 1]))
					{
					     table[i][j] = table[i][j] | table[i][j - 1];
					     table[i][j] = table[i][j] | table[i - 1][j];
					}
				}
			}
		}
		
		return table[p.size() - 1][s.size() - 1];
    }
};
