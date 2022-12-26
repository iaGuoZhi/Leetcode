class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
		int begin = 0, end = people.size() - 1;
		int ans = 0;
		sort(people.begin(), people.end());

		while (end >= begin)
		{
			if (people[begin] + people[end] <= limit)
				begin++;
			end--;
			ans++;
		}
		return ans;
    }
};
