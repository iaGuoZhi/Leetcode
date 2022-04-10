#include "../../../../headers.h"

class Solution {
public:
    string minimizeResult(string expression) {
      int num1 = 0, num2 = 0;
      int size1 = 0, size2 = 0;
      bool is_num1 = true;
      string res;
      int min_multiply = 0, min_num1_idx = 0, min_num2_idx = 0;
      for(int i = 0; i < expression.size(); ++i)
      {
        if(expression[i] == '+')
        {
          is_num1 = false;
          continue;
        }
        if(is_num1)
        {
          num1 = num1 * 10 + (expression[i] - '0');
          size1++;
        } else{
          num2 = num2 * 10 + (expression[i] - '0');
          size2++;
        }
      }
      min_multiply = num1 + num2;

      for(int i = 1; i <= size1; ++i) {
        for(int j = 1; j <= size2; ++j) {
          int multiply = (num1 / (pow(10, size1 - i))) *
            (num1 % (int)(pow(10, size1 - i)) + num2 / (pow(10, size2 -j))) *
            (num2 % (int)pow(10, size2 - j));
          if(multiply < min_multiply)
          {
            min_multiply = multiply;
            min_num1_idx = i;
            min_num2_idx = j;
          }
        }
      }

      if(min_num1_idx == 0 || min_num2_idx == 0)
      {
        res.push_back('(');
        res.append(expression);
        res.push_back(')');
        return res;
      }
      for(int i = 0; i < min_num1_idx; i++)
      {
        res.push_back(expression[i]);
      }
      res.push_back('(');
      for(int i = min_num1_idx; i < size1; i++)
      {
        res.push_back(expression[i]);
      }
      res.push_back('+');
      for(int i = 0; i < min_num2_idx; i++)
      {
        res.push_back(expression[size1 + 1 + i]);
      }
      res.push_back(')');
      for(int i = min_num2_idx; i < size2; i++)
      {
        res.push_back(expression[size1 + 1 + i]);
      }

      return res;
    }
};
