class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
		map<int, int> mp;

		for (auto num : arr)
		{
            if (num % k > 0)
			    mp[num % k]++;
            if (num % k < 0)
                mp[abs(num % k)]--;
		}

		for (auto it: mp)
		{
			if ((k % 2 == 0 && it.first == k / 2) && it.second % 2 != 0)
				return false;
			if (it.second != mp[k - it.first])
				return false;
		}
		return true;
    }
};

