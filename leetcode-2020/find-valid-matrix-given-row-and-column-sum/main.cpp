#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(), n=colSum.size();

        vector<vector<int>> ans(m, vector<int> (n, 0));

        for(int i=0;i<m+n;++i){
            int minVal=INT_MAX,minCol=-1,minRow=-1;
            for(int j=0;j<n;++j){
                if(colSum[j]==0)
                    continue;
                if(colSum[j]<minVal){
                    minVal=colSum[j];
                    minCol=j;
                }
            }

            minVal=INT_MAX;
            for(int j=0;j<m;++j){
                if(rowSum[j]==0)
                    continue;
                if(rowSum[j]<minVal){
                    minVal=rowSum[j];
                    minRow=j;
                }
            }

            if(minCol==-1||minRow==-1)
                break;
            ans[minRow][minCol]=min(rowSum[minRow], colSum[minCol]);
            rowSum[minRow]-=ans[minRow][minCol];
            colSum[minCol]-=ans[minRow][minCol];
        }
        return ans;
    }
};