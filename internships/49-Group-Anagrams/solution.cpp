class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		map<string, vector<int>> maps;

		for (int i = 0; i < strs.size(); ++i)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			maps[s].push_back(i);
		}

		for (auto arrs : maps)
		{
			vector<string> groups;
			for (auto i : arrs.second)
			{
				groups.push_back(strs[i]);
			}
			ans.push_back(groups);
		}
		return ans;
    }
};
