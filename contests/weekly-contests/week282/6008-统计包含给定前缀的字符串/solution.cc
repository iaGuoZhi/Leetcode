class Solution {
    public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        int j;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i].size() >= pref.size()){
                for(j = 0; j < pref.size(); ++j){
                    if(words[i][j] != pref[j])
                        break;
                }
                if(j == pref.size())
                    res += 1;
            }
        }
        return res;
    }
};
