class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		int num = 0, sum = 0, ans = 0;
		map<char, int> tables;
		vector<int> nums;

		for (char c: tasks)
		{
			tables[c]++;
		}

		for (auto it : tables)
		{
			nums.push_back(it.second);
			sum += it.second;
		}

		while(sum > 0)
		{
		    sort(nums.begin(), nums.end(), greater<>());
			for (int i = 0; i <= n; ++i)
			{
				ans++;
				if (i >= nums.size())
					continue;
				if (nums[i] > 0)
				{
					nums[i]--;
					sum--;
                    if (sum == 0){
                        break;
                    }
				}
			}
		}
		return ans;
    }
};
