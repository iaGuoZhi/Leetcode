class Solution {
public:
    int longestValidParentheses(string s) {
		int len = s.size();
		int left = 0, begin = -1;
		int ans = 0;
		stack<int> moon;
		moon.push(-1);

		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '(')
			{
				moon.push(i);
			}
			else
			{
				moon.pop();
				if (moon.empty())
					moon.push(i);
				else {
					ans = max(ans, i - moon.top());
				}
			}
		}
		return ans;
    }
};
