class Solution {
public:
    int appendCharacters(string s, string t) {
		int ti = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == t[ti])
			{
				ti++;
			}
		}
		return t.size() - ti;
    }
};
