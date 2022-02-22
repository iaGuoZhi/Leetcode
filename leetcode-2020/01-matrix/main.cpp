#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return matrix;
        int n=matrix[0].size();

        queue<vector<int>> arrays;


        for(int row=0;row<m;++row){
            for(int column = 0;column<n;++column){
                if(matrix[row][column]==0){
                    arrays.push(vector<int>{row, column});
                }
            }
        }

        while(arrays.size()>0){
            int size = arrays.size();
            for(int j=0;j<size;++j){
                vector<int> pos = arrays.front();
                arrays.pop();
                for(int k=-1;k<=1;++k){
                    for(int t =-1;t<=1;++t){
                        if(k!=t&&k+t!=0&&k+pos[0]>=0&&k+pos[0]<m&&t+pos[1]>=0&&t+pos[1]<n){
                            if(matrix[k+pos[0]][t+pos[1]]==1){
                                matrix[k+pos[0]][t+pos[1]]= matrix[pos[0]][pos[1]]-1;
                                arrays.push(vector<int> {k+pos[0], t+pos[1]});
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                matrix[i][j]=0-matrix[i][j];
            }
        }

        return matrix;
    }
};