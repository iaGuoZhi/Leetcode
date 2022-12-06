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
			left[i] = moon.size() ? moon.top() : -1;
			moon.push(i);
		}

		moon = stack<int>();
		for (int i = len - 1; i >= 0; i--)
		{
			while(moon.size() && heights[moon.top()] > heights[i])
			{
				moon.pop();
			}
			right[i] = moon.size() ? moon.top() : len;
			moon.push(i);
		}

		for (int i = 0; i < len; ++i)
		{
            cout << left[i] << right[i] << endl;
			ans = max(ans, heights[i] * (right[i] - left[i] - 1));
		}

		return ans;
	}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> table(m, vector<int>(n, 0));
		int ans = 0;

		for (int j = 0; j < n; j++)
		{
		    for (int i = 0; i < m; i++)
			{
				if (matrix[i][j] == '1')
				{
					table[i][j] = 1;
					if (i > 0)
				        table[i][j] += table[i - 1][j];
				}
				cout << table[i][j] << '\t';
			}
			cout << '\n';
		}

		for (int i = 0; i < m; i++)
		{
			ans = max(ans, largestRectangleArea(table[i]));
		}

		return ans;
    }
};
