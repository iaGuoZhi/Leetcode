#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();++j){
                if(j-1!=i&&nums[j]==nums[j-1])
                    continue;
                int k=j+1,t=nums.size()-1;
                while(k<t){
                    int cur_sum=nums[i]+nums[j]+nums[k]+nums[t];
                    if(cur_sum==target){
                        vector<int> p{nums[i], nums[j], nums[k], nums[t]};
                        ans.push_back(p);
                    }
                    if(cur_sum<=target){
                        ++k;
                        while(k<t&&nums[k]==nums[k-1])
                            k++;
                    }
                    if(cur_sum>=target){
                        --t;
                        while(k<t&&nums[t]==nums[t+1])
                            t--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{4,0,2,1,0,9,6,5,3,-1};
    Solution solu;
    vector<vector<int>> ans =solu.fourSum(nums, 10);
    for(auto s: ans){
        for(auto n: s){
            printf("%d\t", n);
        }
        printf("\n");
    }
    return 0;
}