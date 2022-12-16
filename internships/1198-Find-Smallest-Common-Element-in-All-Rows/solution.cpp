class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		vector<int> left(m , 0);

		for (int j = 0; j < n; ++j)
		{
			int val = mat[0][j];
			for (int i = 1; i < m; ++i)
			{
				while (begin[i] < n && mat[i][begin[i]] < val)
				{
					begin[i]++;
				}
				if (begin[i] >= n || mat[i][begin[i]] > val)
					break;
				if (mat[i][begin[i]] == val && i == m - 1)
					return val;
			}
		}
		return -;1
    }
};
