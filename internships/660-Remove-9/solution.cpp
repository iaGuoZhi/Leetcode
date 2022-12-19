class Solution {
public:
    int newInteger(int n) {
		stack<int> st;
		long long pos = 1;
		long long ans = 0;
		while (n)
		{
			st.push(n % 9);
			n /= 9;
		}
		while(st.size() > 0)
		{
			ans *= 10;
			ans = ans + st.top();
			st.pop();
		}
		return ans;
    }
};
