class Solution {
public:
    int takeCharacters(string s, int k) {
		int ans = 0;
		int cnts[3] = {0}, mids[3] = {0};
		int head = 0, tail = 0;
		for (auto c : s)
			cnts[c - 'a']++;
		for (int i = 0; i < 3; ++i)
			if (cnts[i] < k)
				return -1;
		while (tail != s.size())
		{
			mids[s[tail] - 'a']++;
			if (mids[s[tail] - 'a'] > cnts[s[tail] - 'a'] - k)
			{
                while (s[head] != s[tail])
                {
					mids[s[head] - 'a']--;
					head++;
				}
                mids[s[head] - 'a']--;
				head++;
			}
			tail++;
			ans = max(ans, tail - head);
		}
		return s.size() - ans;
    }
};
