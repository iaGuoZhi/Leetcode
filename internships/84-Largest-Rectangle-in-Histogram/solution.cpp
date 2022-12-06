class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int len = heights.size();
		vector<int> left(len, 0), right(len, 0);
		stack<int> moon;
		int ans = 0;

		for (int i = 0; i < len; i++)
		{
			while(moon.size() && heights[moon.top()] >= heights[i])
			{
				moon.pop();
			}
			left[i] = moon.size() ? moon.top() : 0;
			moon.push(i);
		}

		moon = stack<int>();
		for (int i = len - 1; i >= 0; i--)
		{
			while(moon.size() && heights[moon.top()] > heights[i])
			{
				moon.pop();
			}
			right[i] = moon.size() ? moon.top() : len - 1;
			moon.push(i);
		}

		for (int i = 0; i < len; ++i)
		{
			ans = max(ans, heights[i] * (right[i] - left[i]));
		}

		return ans;
	}
};
