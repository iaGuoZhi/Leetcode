class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> ans;

		for (int i = 0; i < queries.size(); ++i)
		{
			int num = 0;
			for (int j = 0; j < points.size(); ++j)
			{
				if ((points[j][0] - queries[i][0]) * (points[j][0] - queries[i][0]) +
				     (points[j][1] - queries[i][1]) * (points[j][1] - queries[i][1]) <=
					queries[i][2] * queries[i][2])
					num++;
			}
			ans.push_back(num);
		}
		return ans;
    }
};
