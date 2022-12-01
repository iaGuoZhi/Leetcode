class Solution {
	int innerTrap(vector<int>& height, int from, int to)
	{
		int maxHeight1 = 0, maxHeight2 = 0;
		int height1Idx = -1, height2Idx = -1;
		int ans = 0;

		if (from < 0 || to >= height.size() || to - from <= 1)
			return 0;
		for (int i = from; i <= to; ++i)
		{
			if (height[i] > maxHeight1)
			{
				maxHeight2 = maxHeight1;
				height2Idx = height1Idx;
				maxHeight1 = height[i];
				height1Idx = i;
			}
			else if (height[i] > maxHeight2)
			{
				maxHeight2 = height[i];
				height2Idx = i;
			}
		}

		if (maxHeight1 == 0 || maxHeight2 == 0)
			return 0;

		int begin = height1Idx < height2Idx ? height1Idx : height2Idx;
		int end = height1Idx < height2Idx ? height2Idx : height1Idx;

		for (int i = begin + 1; i < end; ++i)
		{
			ans += (maxHeight2 - height[i]);
		}

		return ans + innerTrap(height, from, begin) + innerTrap(height, end, to);
	}
public:
    int trap(vector<int>& height) {
		return innerTrap(height, 0, height.size() - 1);
    }
};
