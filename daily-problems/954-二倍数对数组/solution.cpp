class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
      int size = arr.size();
      map<int,int> table;
      for(int i = 0; i < size; ++i)
        table[arr[i]] += 1;

      for (const auto& [key, value]: table) {
        if(key <= 0 && key % 2 != 0 && value != 0)
          return false;
        if(value == 0)
          continue;
        int target = (key <= 0) ? (key / 2) : (key * 2);
        if(table[target] < value)
          return false;
        table[target] -= value;
      }
      return true;
    }
};
