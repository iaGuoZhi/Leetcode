class Solution {
  static bool same_parity(int num1, int num2) {
    return (num1 % 2) == (num2 % 2);
  }

    static void my_sort(vector<int> &nums) {
      int size = nums.size();
      for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
          if(same_parity(nums[i], nums[j]) && nums[j] < nums[i]) {
              int tmp;
              tmp = nums[i];
              nums[i] = nums[j];
              nums[j] = tmp;
          }
        }
      }
    }

public:
    int largestInteger(int num) {
      vector<int> nums;
      int res = 0;
      int foo = 1;
      
      while(num){
        nums.push_back(num % 10);
        num /= 10;
      }
      my_sort(nums);

      for(int i = 0; i < nums.size(); ++i) {
        res = 10 * res + nums[nums.size() - i - 1];
      }
      return res;
    }
};
