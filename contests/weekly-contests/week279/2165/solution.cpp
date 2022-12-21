class Solution {
public:
    long long smallestNumber(long long num) {
		vector<long long> nums;
		long long my_num = abs(num);
		long long ans = 0;
		while (my_num)
		{
			nums.push_back(my_num % 10);
			my_num /= 10;
		}

		if (num > 0)
		{
			int i = 0;
		    sort(nums.begin(), nums.end());
			while (i < nums.size() && nums[i] == 0)
			{
				i++;
			}
			swap(nums[0], nums[i]);
		} else {
			sort(nums.begin(), nums.end(), greater());
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			ans = 10 * ans + nums[i];
		}

		return num >= 0 ? ans : -ans;
    }
};

