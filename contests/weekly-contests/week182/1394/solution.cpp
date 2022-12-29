class Solution {
public:
    int findLucky(vector<int>& arr) {
		map<int, int> mp;
		for (auto num : arr)
			mp[num]++;

		int ans = -1;
		for (auto it : mp)
		{
			if (it.first == it.second && it.first > ans)
				ans = it.first;
		}

		return ans;
    }
};
