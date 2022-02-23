class Solution {
public:
    bool isEnglishChar(char c)
    {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
    
    string reverseOnlyLetters(string s) {
        int begin_idx = 0, end_idx = s.size() -1;
        char tmp;

        while(begin_idx < end_idx)
        {
            while(begin_idx < end_idx && !isEnglishChar(s[begin_idx])){
                begin_idx++;
            }

            while(begin_idx < end_idx && !isEnglishChar(s[end_idx])){
                end_idx--;
            }

            if(begin_idx < end_idx){
                tmp = s[end_idx];
                s[end_idx] = s[begin_idx];
                s[begin_idx] = tmp;
                begin_idx++;
                end_idx--;
            }
        }
        return s;
    }
};
