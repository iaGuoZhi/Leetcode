class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i)
        {
            if (std::find(ans.begin(), ans.end(), words[i]) != ans.end())
                continue;
            for (int j = 0; j < words.size(); ++j)
            {
                if (j != i && words[j].find(words[i]) != std::string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
