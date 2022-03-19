class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0, pattern_a_num = 0, pattern_b_num = 0;
        for(int i = 0; i < text.size(); ++i)
        {
            if(text[i] == pattern[0]){
                pattern_a_num += 1;
            }
            if(text[i] == pattern[1]){
                res += pattern_a_num;
                pattern_b_num += 1;
            }
        }

        if(pattern[0] == pattern[1] && res > 0)
            res -= pattern_a_num;

        res += max(pattern_a_num, pattern_b_num);
        
        return res;
    }
};
