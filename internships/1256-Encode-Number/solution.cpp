class Solution {
public:
    string encode(int num) {
		string ans;
		stack<char> st;
		do
		{
            num -= 1;
			switch ((num) % 2)
			{
				case 0: st.push('0'); break;
				case 1: st.push('1'); break;
			}
			num /= 2;
		} while(num);

		while(st.size())
		{
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
    }
};
