class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> q;
		int ans = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			q.push(nums[i]);
			ans += nums[i];
		}

		for (int i = 0; i < k; ++i)
		{
			int num = q.top();
			num = 0 - num;
			ans += 2 * num;
			q.pop();
			q.push(num);
		}

		return ans;
    }
};
