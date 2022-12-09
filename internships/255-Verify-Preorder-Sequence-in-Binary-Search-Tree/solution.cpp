class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<decltype(preorder.begin())> stk;
        auto pre_max = preorder.end();
        for(auto cur = preorder.begin(); cur!=preorder.end(); cur++){
            if(pre_max != preorder.end() && *cur < *pre_max) return false;
            while(!stk.empty() && *cur > *stk.top()){
                pre_max = stk.top(); stk.pop();
            }
            stk.emplace(cur);
        }
        return true;
    }
};
