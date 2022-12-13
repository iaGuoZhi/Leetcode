class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> begins, ends;
		int ans = 0, res = 0;;

		for (int i = 0; i < intervals.size(); ++i)
		{
			begins.push_back(intervals[i][0]);
			ends.push_back(intervals[i][1]);
		}
		sort(begins.begin(), begins.end());
		sort(ends.begin(), ends.end());

		int j = 0;
		for (int i = 0; i < begins.size(); ++i)
		{
			ans++;
			while(ends[j] <= begins[i])
			{
				ans--;
				j++;
			}
			res = max(ans, res);
		}
		return res;
	}
};
