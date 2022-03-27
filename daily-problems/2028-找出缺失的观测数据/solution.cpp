class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int size = m + n;
        int total = size * mean;
        int m_total = 0, n_total = 0;
        vector<int> ans;
        vector<int> non_exist;

        for (auto i : rolls)
          m_total += i;

        n_total = total - m_total;
        while(n_total){
          if(n_total/n >6 || n_total/n < 1)
            return non_exist;
          ans.push_back(n_total / n);
          n_total -= n_total / n;
          n -= 1;
        }

        return ans;
    }
};
