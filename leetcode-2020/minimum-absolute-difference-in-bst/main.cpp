#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        stack<TreeNode *> q;
        vector<int> nums;
        TreeNode *p=root;

        while(q.size()||p!=NULL){
           while(p!=NULL){
               q.push(p);
               p=p->left;
           }

           p=q.top();
           q.pop();
           nums.push_back(p->val);
           p=p->right;
        }

        for(int i=0;i<nums.size()-1;++i){
            ans = min(ans, nums[i+1]-nums[i]);
        }
        return ans;
    }
};