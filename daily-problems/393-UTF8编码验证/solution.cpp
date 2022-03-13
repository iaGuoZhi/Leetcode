class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int size = data.size();
        int expected_n = 0, cur_n = 0;
        int i,j;

        for(i = 0; i < size; ++i){
            for(j = 7; j >= 0; --j)
            {
                if((data[i] & (1 << j)) == 0)
                    break;
            }
            cur_n = 7 - j;
                
            //up to 4 bytes
            if(cur_n > 4)
                return false;

            if(cur_n == 1)
            {
                if(expected_n == 0)
                    return false;
                expected_n -= 1;
                continue;
            }
            
            // new start of a utf-8 code
            if(expected_n > 0)
                return false;

            if(cur_n > 0)
                expected_n = cur_n - 1;
        }

        return expected_n == 0;
    }
};
