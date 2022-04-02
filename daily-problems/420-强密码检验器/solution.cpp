class Solution {
private:
  map<char, int> table;
  bool has_number = 0, has_lowercase = 0, has_uppercase = 0;

  void check_has(char c) {
    if(c >= '0' && c <= '9')
      has_number = true;
    if(c >= 'a' && c <= 'z')
      has_lowercase = true;
    if(c >= 'A' && c <= 'Z')
      has_uppercase = true;
  }

  int getSteps(char c) {
    int v = table[c];
    table[c] = 0;
    return (v + 1) / 3;
  }

public:
    int strongPasswordChecker(string password) {
      int size = password.size();
      int ans = 0;
      int miss_has = 0;

      if(size < 6) {
        return 6 - size;
      }

      if(size > 20) {
        return size - 20;
      }

      for(int i = 0; i <= size; ++i)
      {
        if(i < size)
          check_has(password[i]);
    
        if(i > 0 && i < size && password[i] == password[i - 1])
        {
          table[password[i]] += 1;
          continue;
        }

        if(i > 0) {
          ans += getSteps(password[i - 1]);
        }
      }

      if(!has_uppercase)
        miss_has += 1;
      if(!has_lowercase)
        miss_has += 1;
      if(!has_number)
        miss_has += 1;

      if(miss_has > ans)
        ans = miss_has;

      return ans;
    }
};
