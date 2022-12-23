class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
		vector<int> ans;
		int n = prices.size();
		for (int i = 0; i < n; ++i)
		{
			ans.push_back(prices[i]);
			for (int j = i + 1; j < n; ++j)
			{
				if (prices[j] <= prices[i])
				{
					ans[i] -= prices[j];
					break;
				}
			}
		}
		return ans;
    }
};

