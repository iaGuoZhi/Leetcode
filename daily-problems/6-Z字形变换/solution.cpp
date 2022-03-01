#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int base = numRows * 2 - 2;
        int idx;
        vector<string> rows(numRows, "");

        if(base == 0)
            return s;

        for(int i = 0; i < s.size(); ++i)
        {
            idx = i % base;
            if(idx < numRows)
                rows[idx].push_back(s[i]);
            else
                rows[base - idx].push_back(s[i]);
        }

        for(int i = 0; i < numRows; ++i)
            res.append(rows[i]);

        return res;
    }
};

int main(){
    Solution sol;
    string s = "PAYPALISHIRING"; 
    cout<< sol.convert(s, 3) << endl;
    return 0;
}
