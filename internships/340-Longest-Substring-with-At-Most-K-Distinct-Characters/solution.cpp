class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0)
            return 0;
		unordered_map<char, int> mp;
		int l = 0, r = 0;
		int ans = 0;

		while(r <= s.size())
		{
            if (r == s.size())
                break;
			mp[s[r]]++;
			if (mp.size() > k)
			{
				while(l < r)
				{
					mp[s[l]] -= 1;
					if (mp[s[l]] == 0)
					{
						mp.erase(s[l]);
                        l++;
						break;
					}
					l++;
				}
			}
            ans = max(ans, r - l + 1);
            r++;
		}
		return ans;
    }
};
