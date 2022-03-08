class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int left_candle_idx, right_candle_idx;
        int candle_num = 0;
        int s_size = s.size(), q_size = queries.size();
        vector<int> plates_left_candle(s_size, -1);
        vector<int> plates_right_candle(s_size, -1);
        vector<int> candles_serial(s_size, -1);
        vector<int> res;

        left_candle_idx = -1;
        right_candle_idx = -1;
        for(int i = 0; i < s_size; ++i){
            if(s[i] == '|'){
                left_candle_idx = i;
                candles_serial[i] = ++candle_num;
            }
            plates_left_candle[i] = left_candle_idx;

            if(s[s_size - i - 1] == '|'){
                right_candle_idx = s_size - i - 1;
            }
            plates_right_candle[s_size - i - 1] = right_candle_idx;
        }
        
        for(int i = 0; i < q_size; ++i){
            int begin_candle_idx = plates_right_candle[queries[i][0]];
            int end_candle_idx = plates_left_candle[queries[i][1]];
            if(begin_candle_idx == -1 || end_candle_idx == -1 || end_candle_idx <= begin_candle_idx)
            {
                res.push_back(0);
                continue;
            }
            res.push_back(end_candle_idx - begin_candle_idx - (candles_serial[end_candle_idx] - candles_serial[begin_candle_idx]));
        }

        return res;
    }
};
