class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> window;
        int ans = 0;
        int l = 0, r = 0, valid = 0, n = s.length();
        while (r < n) {
            char c = s[r];
            if (window[c] == 0) {
                valid++;
            }
            window[c]++;
            while (valid > 2) {
                char d = s[l++];
                window[d]--;
                if (window[d] == 0) {
                    valid--;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
