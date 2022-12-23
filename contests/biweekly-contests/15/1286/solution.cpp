class CombinationIterator {
	void add(vector<int> &nums, int len)
	{
		int pos = nums.size() - 1;
		while(pos >= 0 && nums[pos] == len - (nums.size() - pos))
		{
			pos--;
		}
		if (pos < 0)
			return;

		nums[pos]++;
		for (int i = 1; pos + i < nums.size(); i++)
		{
			nums[pos + i] = nums[pos + i - 1] + 1;
		}
	}

	bool has(vector<int> nums, int len)
	{
		int pos = nums.size() - 1;
		while(pos >= 0 && nums[pos] == len - (nums.size() - pos))
		{
			pos--;
		}
		if (pos < 0)
			return false;
		return true;
	}

public:
	int len;
	string characters;
	vector<int> cur;
    CombinationIterator(string characters, int combinationLength) {
		this->characters = characters;
		len = combinationLength;
		for (int i = 0; i < len; ++i)
		{
			cur.push_back(i);
		}
		cur[len - 1]--;
    }
    
    string next() {
		string ans;
		add(cur, characters.size());
		for (auto i : cur)
		{
			ans.push_back(characters[i]);
		}
		return ans;
    }
    
    bool hasNext() {
		return has(cur, characters.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

