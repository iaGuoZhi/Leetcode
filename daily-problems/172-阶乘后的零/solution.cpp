class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, base = 5, cur_n = 5;
        while(cur_n <= n){
            int next_n = 5 * cur_n;

            ans += cur_n / 5;
            if(next_n > n){
                n = n - cur_n;
                cur_n = 5;
                continue;
            }
            cur_n = next_n;
        }

        return ans;
    }
};
