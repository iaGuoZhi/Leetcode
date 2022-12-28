class Solution {
public:
    int minOperations(string s) {
		int ans = INT_MAX;
		int cur = 0;
		int begin = 0;

		for (auto c : s)
		{
			if (c != '0' + begin)
				cur++;
			begin = (begin + 1) % 2;
		}
		ans = min(ans, cur);
		begin = 1;
		cur = 0;
		for (auto c : s)
		{
			if (c != '0' + begin)
				cur++;
			begin = (begin + 1) % 2;
		}
		ans = min(ans, cur);
		return ans;
    }
};
