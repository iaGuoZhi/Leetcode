class Solution {
public:
    int validSubarrays(vector<int>& nums) {
		stack<int> st;
		int ans = 0;
		nums.push_back(-1);

		for (int i = 0; i < nums.size(); ++i)
		{
			while (!st.empty() && nums[i] < nums[st.top()])
			{
				ans += (i - st.top());
				st.pop();
			}
			st.push(i);
		}
		return ans;
    }
};
