class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = tickets[k] * tickets.size() - tickets.size() + k + 1;

		for (int i = 0; i < tickets.size(); ++i)
        {
            int num = tickets[i];
			if (num < tickets[k] && i < k)
				ans -= (tickets[k] - num);
            if (num < tickets[k] - 1 && i > k)
                ans -= (tickets[k] - 1 - num);
        }

		return ans;
    }
};

