#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        return vector<vector<int>>{};
    }

    string readFile(string fileName){
        char *buffer;
        FILE *fh = fopen(fileName.c_str(), "rb");
        if(fh){
            fseek(fh, 0L, SEEK_END);
            long s= ftell(fh);
            rewind(fh);
            buffer=(char *) malloc(s);
            if(buffer!=NULL){
                fread(buffer, s, 1, fh);
                fclose(fh);
                fh=NULL;
                return buffer;
            }
        }
        return "";
    }

    void writeFile(string fileName, string content){
        FILE *fh=fopen(fileName.c_str(), "wb");
        if(fh){
            fwrite(content.c_str(), content.size(), 1, fh);
            fclose(fh);
        }
    }

    vector<string> splitTokens(string s){
        s=s.substr(1, s.size()-2);
        if(s.size()==0)
            return vector<string>{};
        
        s.push_back(',');
        string word="";
        vector<string> tokens;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==','){
                tokens.push_back(word.substr(1, word.size()-2));
                word="";
            }
            else{
                word.push_back(s[i]);
            }
        }
        return tokens;
    }

    void run(string fileName, string resultFile){
        string s= readFile(fileName);

        vector<string> tokens=splitTokens(s);
        cout<<tokens.size();
    }
};

int main(){
    Solution solu;
    solu.run("file.txt", "out.txt");
}