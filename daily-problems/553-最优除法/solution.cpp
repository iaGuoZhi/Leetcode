#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    double maxDivision(vector<int> &nums, int begin_idx, string& format){
        double first_num, second_num;
        string bracket_second_format, no_bracket_second_format;
        double bracket_second_res, no_bracket_second_res;

        format = to_string(nums[begin_idx]);
    
        // should not exceed nums size
        if(begin_idx >= nums.size())
            return -1;
        if(begin_idx == nums.size() - 1){
            return nums[begin_idx];
        }

        first_num = (double)nums[begin_idx];
        second_num = (double)nums[begin_idx + 1];

        // to get max division results, dividend number should be smallest
        bracket_second_res = minDivision(nums, begin_idx + 1, bracket_second_format);
        // here second number just replace first number as divisor, so we should get max result
        no_bracket_second_res = maxDivision(nums, begin_idx + 1, no_bracket_second_format);

        bracket_second_res = first_num / bracket_second_res;
        no_bracket_second_res = first_num * no_bracket_second_res / second_num / second_num;

        // choose larger one
        if(bracket_second_res > no_bracket_second_res){
            format.push_back('/');
            format.push_back('(');
            format.append(bracket_second_format);
            format.push_back(')');
            return bracket_second_res;
        }else{
            format.push_back('/');
            format.append(no_bracket_second_format);
            return no_bracket_second_res;
        }

        // should not reach here
        return -1;
    }

    double minDivision(vector<int> &nums, int begin_idx, string& format){
        double first_num, second_num;
        string bracket_second_format, no_bracket_second_format;
        double bracket_second_res, no_bracket_second_res;

        format = to_string(nums[begin_idx]);

        // should not exceed nums size
        if(begin_idx >= nums.size())
            return -1;
        if(begin_idx == nums.size() - 1){
            return nums[begin_idx];
        }

        first_num = (double)nums[begin_idx];
        second_num = (double)nums[begin_idx + 1];

        // to get min division results, dividend number should be largest
        bracket_second_res = maxDivision(nums, begin_idx + 1, bracket_second_format);
        // here second number just replace first number as divisor, so we should get min result
        no_bracket_second_res = minDivision(nums, begin_idx + 1, no_bracket_second_format);

        bracket_second_res = first_num / bracket_second_res;
        no_bracket_second_res = first_num * no_bracket_second_res / second_num / second_num;

        // choose smaller one
        if(bracket_second_res < no_bracket_second_res){
            format.push_back('/');
            format.push_back('(');
            format.append(bracket_second_format);
            format.push_back(')');
            return bracket_second_res;
        }else{
            format.push_back('/');
            format.append(no_bracket_second_format);
            return no_bracket_second_res;
        }

        // should not reach here
        return -1;
    }
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        maxDivision(nums, 0, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    string ans;
    vector<int> nums;

    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);

    ans = sol.optimalDivision(nums);
    std::cout<< ans << endl;
    return 0;
}
