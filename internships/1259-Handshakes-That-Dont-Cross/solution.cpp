class Solution {
public:
    int numberOfWays(int numPeople) {
		numPeople /= 2;
		vector<long long int> nums(numPeople + 1, 1);
		for (int i = 1; i <= numPeople; ++i)
		{
			nums[i] = nums[i - 1];
			for (int j = 0; j < i - 1; ++j)
			{
				nums[i] += (nums[j] * nums[i - j - 1]);
                nums[i] %= 1000000007;
			}
		}

		return nums[numPeople];
    }
};
