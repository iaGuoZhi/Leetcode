class Solution {
	int help(vector<int>& values)
	{
		if (values.size() == 3)
			return values[0] * values[1] * values[2];
		int p1, p2;
		vector<int> v1, v2;
		
		int min = INT_MAX;
		for (int i = 0; i < values.size(); ++i)
		{
			for (int j = i + 2; j < values.size() && (j + 1) % values.size() != i; ++j)
			{
				if (values[i] * values[j] < min)
				{
					min = values[i] * values[j];
					p1 = i;
					p2 = j;
				}
			}
		}

		for (int i = p1; i <= p2; ++i)
			v1.push_back(values[i]);
		for (int i = p2; i != p1; i = (i + 1) % values.size())
			v2.push_back(values[i]);
		v2.push_back(values[p1]);
		return help(v1) + help(v2);
	}
public:
    int minScoreTriangulation(vector<int>& values) {
		return help(values);
    }
};
