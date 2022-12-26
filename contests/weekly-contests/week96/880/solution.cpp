class Solution {
public:
    string decodeAtIndex(string s, int k) {
		string cur;
		int begin = 0;
		long long cnt = 0;
		while (k >= cur.size())
		{
			if (s[begin] >= 'a' && s[begin] <= 'z')
			{
				cur.push_back(s[begin]);
				cnt++;
			}
			if (s[begin] >= '2' && s[begin] <= '9')
			{
				long long num = s[begin] - '0';
				cnt = cnt * num;
		}
		return cur.substr(k, 1);
    }
};
