class NumMatrix {
    int m, n;
	unordered_map<int, int> mp;
	vector<vector<int>> sums;
	vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
		m = matrix.size(), n = matrix[0].size();
	    vector<vector<int>> sums(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i)
		{
			int left = 0;
			for (int j = 0; j < n; ++j)
			{
				left += matrix[i][j];
				sums[i][j] = left;
				if (i > 0)
					sums[i][j] += sums[i - 1][j];
			}
		}
		this->sums = sums;
		this->matrix = matrix;
    }
    
    void update(int row, int col, int val) {
		mp[row * n + col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		int ans = 0;
		ans = sums[row2][col2];
        if (row1 > 0)
            ans -= sums[row1 - 1][col2];
        if (col1 > 0)
            ans -= sums[row2][col1 - 1];
        if (row1 > 0 && col1 > 0)
            ans += sums[row1 - 1][col1 - 1];
		for (auto point: mp)
		{
            int cur_row = point.first / n, cur_col = point.first % n;
			if (cur_row >= row1 && cur_row <= row2 && cur_col >= col1 && cur_col <= col2)
			{
				ans += point.second - matrix[cur_row][cur_col];
			}
		}
		return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
