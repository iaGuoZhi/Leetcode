class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
		int ans = 0;
		for (auto word: words)
		{
			int diff = false;
			for (int i = 0; i < word.size(); ++i)
			{
				if (i >= s.size() || word[i] != s[i])
					diff = true;
			}
			if (!diff)
				ans++;
		}
		return ans;
    }
};
