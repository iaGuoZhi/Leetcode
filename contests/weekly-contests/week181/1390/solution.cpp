class Solution {
	vector<int> factors(int num)
	{
		vector<int> ans;
		for (int i = 2; i <= sqrt(num); ++i)
		{
			if (num % i == 0)
			{
				ans.push_back(i);
				if (num / i != i)
				{
					ans.push_back(num / i);
				}
			}
		}
		return ans;
	}
public:
    int sumFourDivisors(vector<int>& nums) {
		int ans = 0;
		for (auto num : nums)
		{
			vector<int> factor = factors(num);
			if (factor.size() == 2)
			{
				ans += 1;
				ans += num;
				ans += accumulate(factor.begin(), factor.end(), 0);
			}
		}
		return ans;
    }
};
