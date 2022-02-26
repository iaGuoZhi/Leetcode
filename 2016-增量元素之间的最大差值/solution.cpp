class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int i = 0, j = 1;
         //    int left_min = INT_MAX, right_max = INT_MIN;

        if(nums.size() <= 1)
            return res;
        for(i; i < nums.size(); ++i){
            for(j = i + 1; j < nums.size(); ++j){
                if(nums[j] - nums[i] > 0 && nums[j] - nums[i] > res){
                    res = nums[j] - nums[i];
                }
            }
        }

        return res;
    }
};
