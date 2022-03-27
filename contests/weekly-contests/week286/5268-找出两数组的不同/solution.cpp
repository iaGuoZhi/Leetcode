class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      set<int> nums1_set, nums2_set;
      set<int> nums1_ans, nums2_ans;
      vector<vector<int>> ans(2, vector<int>());

      for(auto num : nums1)
        nums1_set.insert(num);
      for(auto num : nums2){
        nums2_set.insert(num);
        if(!nums1_set.count(num) && !nums2_ans.count(num))
          nums2_ans.insert(num);
      }
      for(auto num : nums1)
        if(!nums2_set.count(num) && !nums1_ans.count(num))
          nums1_ans.insert(num);

      for(auto num : nums1_ans)
        ans[0].push_back(num);
      for(auto num : nums2_ans)
        ans[1].push_back(num);
      return ans;
    }
};
