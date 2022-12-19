class Solution {
public:
    int findDerangement(int n) {
		vector<long long> nums(n, 0);
        if (n == 1)
            return 0;
		nums[1] = 1;

		for (long long i = 2; i < n; ++i)
		{
			nums[i] = i * (nums[i - 1] + nums[i - 2]);
            nums[i] = nums[i] % (1000000007);
		}

		return nums[n - 1];
    }
};
