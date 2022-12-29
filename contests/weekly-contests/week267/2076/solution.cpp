class UnionFind {
	int cnt = 0;
	vector<int> nums;
	vector<map<int, bool>> mps;

public:
	UnionFind(int n, vector<vector<int>> &restrictions)
	{
		nums.resize(n);
		for(int i = 0; i < n; ++i)
			nums[i] = i;
		mps.resize(n);
		for (auto restriction : restrictions)
		{
			mp[restriction[0]][restriction[1]] = true;
			mp[restriction[1]][restriction[0]] = true;
		}
	}

	int find(int x)
	{
		while (nums[x] != x)
		{
			x = nums[x];
		}
		return x;
	}

	bool Union(int x, int y)
	{
		int fx = find(x), fy = find(y);
		if (fx == fy)
			return true;
		if (mp[fx].find(fy) != mp[fx].end() || mp[fy].find(fx) != mp[fy].end())
			return false;
		nums[fx] = fy;
		for (auto it : mp[fx])
			mp[fy][find(it.first)] = true;
		cnt--;
	}
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
		UnionFind uf(n, restrictions);
		vector<bool> ans;
		for (auto request : requests)
			ans.push_back(uf.Union(request[0], request[1]));
		return ans;
    }
};


