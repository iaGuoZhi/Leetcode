class Solution {
  int maxConsectutiveSymbol(string answerKey, int k, char target)
  {
    int begin = 0, end = 0, ans = 0;
    int changed = 0;
    int size = answerKey.size();
    while(end < size){
      if(answerKey[end] != target){
        if(changed < k){
          end++;
          changed+=1;
        }
        else{
          while(answerKey[begin] == target)
            begin++;
          begin+=1;
          end+=1;
        }
      }else{
        end++;
      }
      ans = max(ans, end - begin);
    }
    return ans;
  }

public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    return max(maxConsectutiveSymbol(answerKey, k, 'T'),
        maxConsectutiveSymbol(answerKey, k, 'F'));
  }
};
