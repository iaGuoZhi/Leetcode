class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int size = nums.size();
        vector<int> ans;
        int search_begin_idx = 0;

        for(int i = 0; i < size; ++i){
            if(nums[i] == key){
                for(int j = max(search_begin_idx, i - k); j < min(size, i + k + 1); ++j){
                    ans.push_back(j);
                }
                search_begin_idx = min(size, i + k + 1);
            }
        }

        return ans;
    }
};
