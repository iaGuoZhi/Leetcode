class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
		int sum = 0, ski = 0;
		long long ans = 0;
		map<int, int> tables;
		int len = skill.size();
		for (int i = 0; i < len; i++)
		{
			sum += skill[i];
		    tables[skill[i]]++;
		}
		if (sum * 2 % len != 0)
			return -1;
		ski = sum * 2 / len;
        
		for (int i = 0; i < len; i++)
		{
			if (tables.find(ski - skill[i]) != tables.end() && tables[ski - skill[i]] > 0)
			{
		        tables[ski - skill[i]]--;
				ans += (long long)(skill[i] * (ski - skill[i]));
			}
			else
				return -1;
		}
		return ans / 2;
    }
};

