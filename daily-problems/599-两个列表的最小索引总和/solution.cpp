class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int l1_size = list1.size();
        int l2_size = list2.size();
        int i, idx_1, idx_2;

        for(i = 0; i < l1_size + l2_size - 1; ++i){
            for(idx_1 = 0; idx_1 <= i && idx_1 < l1_size; ++idx_1){
                idx_2 = i - idx_1;
                if(idx_2 >= l2_size)
                    continue;
                if(list1[idx_1].compare(list2[idx_2]) == 0){
                    ans.push_back(list1[idx_1]);
                }
            }
            if(ans.size())
                break;
        }
        return ans;
    }
};
