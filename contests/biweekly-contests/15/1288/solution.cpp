class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
				return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
				});

		int ans = intervals.size();
		int last = 0;

		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][1] <= intervals[last][1])
				ans--;
			else 
				last = i;
		}
			
		return ans;
    }
};
