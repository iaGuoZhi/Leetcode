class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
		map<int, int> mp;

		for (auto num : arr)
		{
			mp[num]++;
			if (mp[num] * 4 > arr.size())
				return num;
		}

		return -1;
    }
};
