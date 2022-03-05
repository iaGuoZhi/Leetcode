class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() != b.size())
            return a.size() > b.size() ? a.size() : b.size();

        if(a.find(b) == string::npos)
            return a.size();

        return -1;
    }
};
