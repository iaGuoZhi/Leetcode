class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int i;
        map<int, int> tables;
        int target, target_freq = 0;

        for(i = 1; i < nums.size(); ++i){
            if(nums[i - 1] == key){
                tables[nums[i]] += 1;
            }
        }

        for(auto i : tables)
            if(i.second > target_freq){
                target_freq = i.second;
                target = i.first;
            }
    
        return target;
    }
};
