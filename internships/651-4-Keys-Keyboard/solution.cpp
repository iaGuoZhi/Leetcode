class Solution {
public:
    int maxA(int N) {
        int dp[N+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= N; i++) {
            dp[i] = dp[i-1] + 1;
            for(int j = 2; j < i; j++) {
                dp[i] = max(dp[i], dp[j-2] * (i-j+1));
            }
        }
        return dp[N];
    }
};
