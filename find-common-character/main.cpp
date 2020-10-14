#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        map<char, int> totaltable;
        
        for(int i=0;i<A.size();++i){
            map<char, int> table;
            for(int j=0;j<A[i].size();++j){
                table[A[i][j]]++;
            }
            for(auto t: table){
                if(totaltable.count(t.first)){
                    totaltable[t.first]=min(totaltable[t.first], t.second);
                }else{
                    if(i==0)
                        totaltable[t.first]=t.second;
                }
            }

            for(auto t: totaltable){
                if(!table.count(t.first)){
                    totaltable[t.first]=0;
                }
            }
        }

        for(auto t: totaltable){
            while(totaltable[t.first]>0){
                totaltable[t.first]--;
                ans.push_back(string(1,t.first));
            }
        }
        return ans;
    }