class Solution {
	unordered_map<int, int> mp;
public:
    int countMaxOrSubsets(vector<int>& nums) {
		int ans = 0;
		for (auto num : nums)
		{
			int pos = 0;
			while (num) {
				if (num % 2) {
					mp[pos]++;
				}
				num /= 2;
			}
		}



        
    }
};
