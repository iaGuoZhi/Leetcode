class Solution {
public:
    int trap(vector<int>& height) {
		int len = height.size();
		int leftMaxHeight = 0, rightMaxHeight = 0;
		int ans = 0;

		if (len == 0)
			return 0;

		vector<int> leftHeights(len, 0);
		vector<int> rightHeights(len, 0);

		for (int i = len - 1; i >= 0; i--)
		{
			rightHeights[i] = rightMaxHeight;
			if (height[i] > rightMaxHeight)
				rightMaxHeight = height[i];
		}
		for (int i = 0; i < len; i++)
		{
			leftHeights[i] = leftMaxHeight;
			if (height[i] > leftMaxHeight)
				leftMaxHeight = height[i];

			if (height[i] < leftHeights[i] && height[i] < rightHeights[i])
				ans += min(leftHeights[i], rightHeights[i]) - height[i];
		}
		return ans;
    }
};
