int ans = 0;
class Solution {
    int size = 0;
    void search(vector<int> &nums, int expected_res, int begin)
    {
        if(begin >= size)
        {
            ans += (expected_res == 0) ? 1 : 0;
            return;
        }
        if(expected_res == 0)
        {
            ans += (1 << (size - begin));
            return;
        }

        search(nums, expected_res - (expected_res & nums[begin]), begin + 1);
        search(nums, expected_res, begin + 1);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_res = 0;
        size = nums.size();

        for(int i = 0; i < size; ++i){
            max_res = max_res | nums[i];
        }
        
        search(nums, max_res, 0);
        return ans;
    }
};
