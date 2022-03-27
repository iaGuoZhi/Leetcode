// bag problem
class Solution {
public:
    int minDeletion(vector<int>& nums) {
      int ans = 0;
      int size = nums.size();
      vector<vector<int>> table(2, vector<int>(size, 0));

      for(int i = 0; i < size - 1; ++i){
        if((i - ans)%2 == 0 && nums[i - ans] == nums[i + 1 - ans]){
          ans += 1;
          i += 1;
        }
      }
      if((size - ans) % 2 == 1)
        ans += 1;
      return ans;
    }
};
