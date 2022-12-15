class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
		int ans = 0;
		vector<int> equals;

		for (int i = 0; i < sideLength; ++i)
		{
			for (int j = 0; j < sideLength; ++j)
			{
				int cur = 1;
				cur *= (((width  - 1 - i)/ sideLength) + 1);
				cur *= (((height - 1 - j)/ sideLength) + 1);
				equals.push_back(cur);
			}
		}

		sort(equals.begin(), equals.end());

		for (int i = 0; i < maxOnes; ++i)
		{
			ans += equals[equals.size() - 1 - i];
		}
		return ans;
    }
};
