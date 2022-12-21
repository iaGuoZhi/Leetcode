class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
		vector<int> ans;
		vector<int> odd, even;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
			{
				even.push_back(nums[i]);
			} else {
				odd.push_back(nums[i]);
			}
		}

		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());

		for (int i = 0; i < even.size(); ++i)
		{
			ans.push_back(even[i]);
			if (i < odd.size())
			    ans.push_back(odd[odd.size() - i - 1]);
		}

		return ans;
    }
};
