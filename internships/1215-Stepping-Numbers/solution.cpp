class Solution {
	vector<int> ans;
	void bfs(int num, int low, int high)
	{
		if (low <= num && num <= high)
			ans.push_back(num);
		if (num <= 0 || num > high)
			return;
		
		int last = num % 10;
		double next_num = num;
		if (last > 0)
		{
			next_num = next_num * 10 + last - 1;
			if (next_num <= high)
				bfs((int)next_num, low, high);
		}
        next_num = num;
        if (last < 9) {
			next_num = next_num * 10 + last + 1;
			if (next_num <= high)
				bfs((int)next_num, low, high);
		}
	}

				
public:
    vector<int> countSteppingNumbers(int low, int high) {
		for (int i = 0; i < 10; ++i)
			bfs(i, low, high);
		
        sort(ans.begin(), ans.end());
		return ans;
    }
};
