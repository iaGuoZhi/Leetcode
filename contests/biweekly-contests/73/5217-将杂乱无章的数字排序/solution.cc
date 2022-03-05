class Solution {
    int convert(int num, vector<int> &mapping){
        int i;
        i = mapping[num % 10];
        if(num / 10 == 0)
            return i;
        return 10 * convert(num / 10, mapping) + i;
    }

    bool compare(int num1, int num2, vector<int> &mapping){
        int converted_num1,  converted_num2;

        converted_num1 = convert(num1, mapping);
        converted_num2 = convert(num2, mapping);
        if(converted_num1 < converted_num2)
            return true;

        return false;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int i, j;
        int tmp;
        vector<int> res;

        for(i = 0; i < nums.size(); ++i)
            res.push_back(nums[i]);

        sort(res.begin(), res.end(), [](const int &num1, const int &num2){
                return compare(num1, num2);
        });
        //for(i = 0; i < res.size(); ++i)
        //    for(j = i + 1; j < res.size(); ++j){
        //        if(compare(res[i], res[j], mapping) == true){
        //            tmp = res[j];
        //            res[j] = res[i];
        //            res[i] = tmp;
        //        }
        //    }
        return res;
    }
};
