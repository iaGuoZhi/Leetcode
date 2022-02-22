#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.size()-1,j=T.size()-1;

        while(i>=0||j>=0){
            int jump=0;
            while(i>=0&&(S[i]=='#'||jump>0)){
                if(S[i]=='#')
                    jump++;
                else
                    jump--;
                i=i-1;
            }

            jump=0;
            while(j>=0&&(T[j]=='#'||jump>0)){
                if(T[j]=='#')
                    jump++;
                else
                    jump--;
                j=j-1;
            }

            if(i>=0&&j<0||i<0&&j>=0)
                return false;

            if(i<0&&j<0)
                break;
                
            if(i>=0&&j>=0&&S[i]==T[j])
            {
                i--;
                j--;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};


int main(){
    string a="ab##";
    string b="c#d#";
    Solution solu;
    cout<<solu.backspaceCompare(a,b)<<endl;
    return 0;
}