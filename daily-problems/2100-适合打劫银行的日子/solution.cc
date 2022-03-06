class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;
        vector<int> table(security.size());
        int successive_good_rob_day_cnt = 0;

        // from left to right
        for(int i = 0; i < security.size(); ++i){
            if(i > 0 && security[i - 1] >= security[i]){
               successive_good_rob_day_cnt += 1; 
            }else{
               successive_good_rob_day_cnt = 0; 
            }
            if(successive_good_rob_day_cnt >= time){
                table[i] += 1;
            }
        }

        successive_good_rob_day_cnt = 0; 
        // from right to left
        for(int i = security.size() - 1; i >= 0; --i){
            if(i < security.size() - 1 && security[i + 1] >= security[i]){
               successive_good_rob_day_cnt += 1; 
            }else{
               successive_good_rob_day_cnt = 0; 
            }
            if(successive_good_rob_day_cnt >= time){
                table[i] += 1;
            }
        }

        // only left and right both good day
        for(int i = 0; i < table.size(); ++i){
            if(table[i] == 2){
                res.push_back(i);
            }
        }
        return res;
    }
};
