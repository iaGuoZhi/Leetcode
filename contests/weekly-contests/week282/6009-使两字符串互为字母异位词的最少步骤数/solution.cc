class Solution {
public:
    int minSteps(string s, string t) {
        int s_letter[26] = {0}, t_letter[26] = {0};
        int equal_num = 0;
        for(int i = 0; i < s.size(); ++i){
            s_letter[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < t.size(); ++i){
            t_letter[t[i] - 'a'] += 1;
        }

        for(int i = 0; i < 26; ++i)
        {
            equal_num += s_letter[i] < t_letter[i] ? s_letter[i] : t_letter[i];
        }

        return s.size() + t.size() - 2 * equal_num;
    }
};
