class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
		vector<int> nums(6, 0);
		bool has = false;
		int top = 0, bottom = 0;
		int target = -1;
		for (int i = 0; i < tops.size(); ++i)
		{
			nums[tops[i] - 1]++;
            nums[bottoms[i] - 1]++;
		}

		for (int i = 0; i < 6; ++i)
		{
			if (nums[i] >= tops.size())
			{
				target = i + 1;
				has = true;
				break;
			}
		}

		if (!has)
			return -1;

		for (int i = 0; i < tops.size(); ++i)
		{
			if (tops[i] != target && bottoms[i] != target)
				return -1;
			if (tops[i] != target)
				top++;
		}

		for (int i = 0; i < tops.size(); ++i)
		{
			if (bottoms[i] != target)
				bottom++;
		}

		return min(top, bottom);
	}
};

