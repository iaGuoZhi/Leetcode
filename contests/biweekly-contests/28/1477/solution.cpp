class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
		vector<int> res;
		int end = 0, begin = 0, cur = 0;
		int ans = INT_MAX;
		while (end < arr.size())
		{
			cur += arr[end];
			if (cur == target)
			{
				res.push_back({begin, end});
			}
			if (cur >= target)
			{
				cur -= arr[begin];
				begin++;
			}
			if (cur < target)
				end++;
		}

    }
};
