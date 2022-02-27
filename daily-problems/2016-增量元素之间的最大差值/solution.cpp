class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int left_min_idx = -1;

        if(nums.size() <= 1)
            return res;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(left_min_idx < 0 || nums[i] < nums[left_min_idx]){
                for(int j = i + 1; j < nums.size(); ++j){
                    if(nums[j] - nums[i] > 0 && nums[j] - nums[i] > res){
                        res = nums[j] - nums[i];
                    }
                }
                left_min_idx = i;
            }
        }

        return res;
    }
};
