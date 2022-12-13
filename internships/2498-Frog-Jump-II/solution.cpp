class Solution {
public:
    int maxJump(vector<int>& stones) {
		int ans = stones[1] - stones[0];
		for (int i = 0; i < stones.size() - 2; i++)
			ans = max(stones[i + 2] - stones[i], ans);
		return ans;
    }
};
