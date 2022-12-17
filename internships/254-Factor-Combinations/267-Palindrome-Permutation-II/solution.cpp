class Solution 
{
public:
    unordered_map<char, int> char_freq;
    vector<string> res;

    void dfs_backtrace(string cur, int n)
    {
		if (cur.size() > n)
		{
			return;
		}
		if (cur.size() == n)
		{
			res.push_back(cur);
		}
		for (auto [c, freq] : char_freq)
		{
			string s;
			if (freq > 0)
			{
				s = cur;
			    s.push_back(c);
			    s.push_front(c);
			    char_freq[c] -= 2;
			    dfs_backtrace(s, n);
			    char_freq[c] += 2;
			}
		}
    }

    vector<string> generatePalindromes(string s) 
    {
        int n = s.size();
        for (auto c: s)
        {
            if (char_freq.count(c) != 0)
                char_freq[c] ++;
            else
                char_freq[c] = 1;
        }
        int odd_cnt = 0;                    //出现次数为奇数的字母个数
        char odd_char;
        for (auto [c, freq]: char_freq)
        {
            if (freq % 2 == 1)
            {
                odd_cnt ++;
                odd_char = c;
                if (odd_cnt > 1)        //最多允许一个字母出现奇数次，到时候把它放中间
                    return {};
            }
        }
        string mid = "";
        if (odd_cnt == 1)               //如果有一个出现奇数次的，把它放中间
        {
            mid += odd_char;
            char_freq[odd_char] --;
        }
        dfs_backtrace(mid, n);
        return res;
    }
};
