#include "../../headers.h"

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
      int size = arrival.size();
      long long busiest_times = 0;
      vector<long long> release_times(k, 0);
      vector<long long> busy_times(k, 0);
      vector<int> ans;

      for(int i = 0; i < size; ++i) {
        int t = i % k;
        do {
          if(release_times[t] <= (long long)arrival[i]){
            release_times[t] = (long long)load[i] + (long long)arrival[i];
            busy_times[t] += 1;
            break;
          }
          t = (t + 1) % k;
        }while(t != i % k);  // dropped
      }

      for(auto busy : busy_times){
        busiest_times = max(busy, busiest_times);
      }

      for(int i = 0; i < k; ++i){
        if(busy_times[i] == busiest_times)
          ans.push_back(i);
      }

      return ans;
    }
};
