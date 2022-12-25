class Solution {
	long long help(int len, vector<int> p)
	{
		long long ans = 1;
		sort(p.begin(), p.end());
		for (int i = 0; i < len; ++i)
		{
			ans *= (long long)(n - i);
			ans /= (long long)p[i];
			if (ans > 1E9 + 7)
				ans = ans % (1E9 + 7);
		}
		return ans;
	}
	
public:
    int countAnagrams(string s) {
		stringstream ss(s);
		string p;
		long long ans = 0;
		while(getline(ss, p, ' ')){
			int cnt = 1;
			map<char, int> mp;
			vector<int> nums;
			for (auto c : p)
			{
				mp[c]++;
				nums.push_back(mp[c]);
			}
			ans += help(nums.size(), nums);
			if (ans > 1E9 + 7)
				ans = ans % (1E9 + 7);
		}
		return ans
    }
};
