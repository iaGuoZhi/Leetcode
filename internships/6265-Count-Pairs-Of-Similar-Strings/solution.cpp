class Solution {
public:
    int similarPairs(vector<string>& words) {
		unordered_map<string, int> mp;
		int ans = 0;

		for (auto str: words)
        {
			std::set<char> chars;
			sort(str.begin(), str.end());
	        str.erase(
                remove_if(
                str.begin(),
                str.end(),
                [&chars] (char i) {
                    // If encountered character, remove this one.
                    if (chars.count(i)) { return true; }

                    // Otherwise, mark this character encountered and don't remove.
                    chars.insert(i);
                    return false;
                }
            ),
            str.end()
            );

			mp[str]++;
		}

		for (auto it: mp)
		{
			if (it.second > 1)
				ans += (it.second * (it.second - 1)) / 2;
		}

		return ans;
    }
};
