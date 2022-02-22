#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps = 1e-8;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int ans=0;
        for(auto point:points){
           int x=point[0]-location[0];
           int y=point[1]-location[1];
           if(x==0&&y==0)
                ans++;
            else{
                angles.emplace_back(atan2(x, y)*180/ M_PI);
            }
        }
        
        sort(angles.begin(), angles.end());
        int len = angles.size();
        for(int i=0;i<len;++i){
            angles.emplace_back(angles[i]+360);    
        }
        
        int num=0,begin=0,end=1;
        while(begin<len){
            while(end<angles.size()&&(angles[end]-angles[begin]<=double(angle)+eps)){
               end++;
            }
            num=max(num,end-begin);
            begin++;
        }
        return ans+num;
    }
};