class Solution {
public:
    int pathSum(vector<int>& nums) {
		int table[5][10] = {-1};
		int ans = 0;

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 10; j++)
                table[i][j] = -1;

		for (int i = 0; i < nums.size(); ++i)
		{
			int first = nums[i] / 100, second = (nums[i] % 100) / 10, third = nums[i] % 10;
			table[first][second] = third;
		}

		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 1; j < 9; ++j)
			{
				if (table[i][j] == -1)
					continue;
                if (i == 4 || (table[i + 1][2 * j - 1] == -1 && table[i + 1][2 * j] == -1))
                    {
                        cout << table[i][j];
                        ans += table[i][j];
                        continue;
                    }
                if (table[i + 1][2 * j - 1] != -1)
			        table[i + 1][2 * j - 1] += table[i][j];
                if (table[i + 1][2 * j] != -1)
			        table[i + 1][2 * j] += table[i][j];
			}
		}
		return ans;
    }
};
