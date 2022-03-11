/**
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int size = parents.size();
        vector<int> level(size, 0);
        vector<bool> visited(size, false);
        vector<int> left_child_idx(size, -1);
        vector<int> right_child_idx(size, -1);
        vector<int> left_child_size(size, 0);
        vector<int> right_child_size(size, 0);
        map<int, vector<int>> level_map;
        queue<int> processing_nodes;
        int cur_node = 0, cur_level = 0;
        long long max_size = 0;
        int res = 0;

        // calculate child idx
        for(int i = 0; i < size; ++i){
            if(parents[i] != -1){
                if(left_child_idx[parents[i]] == -1){
                    left_child_idx[parents[i]] = i;
                }else{
                    right_child_idx[parents[i]] = i;
                }
            }else{
                // root node
                processing_nodes.push(i);
            }
        }

        // calculate level
        while(processing_nodes.size() > 0){
            int processing_size = processing_nodes.size();
            while(processing_size){
                cur_node = processing_nodes.front();
                processing_nodes.pop();
                level[cur_node] = cur_level;
                if(left_child_idx[cur_node] != -1)
                    processing_nodes.push(left_child_idx[cur_node]);
                if(right_child_idx[cur_node] != -1)
                    processing_nodes.push(right_child_idx[cur_node]);
                processing_size--;
            }
            cur_level++;
        }

        // current max level
        cur_level -= 1;

        for(; cur_level >= 0; --cur_level){
            for(int i = 0; i < size; ++i)
            {
                if(level[i] == cur_level){
                    cur_node = i;
                    int cur_size = left_child_size[cur_node] + right_child_size[cur_node] + 1;
                    if(parents[cur_node] != -1){
                        if(left_child_size[parents[cur_node]] == 0)
                        {
                            left_child_size[parents[cur_node]] = cur_size;
                        }else{
                            right_child_size[parents[cur_node]] = cur_size;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < size; ++i)
        {
            long long cur_score = 1;
            if(left_child_size[i] != 0)
                cur_score *= (long long)left_child_size[i];
            if(right_child_size[i] != 0)
                cur_score *= (long long)right_child_size[i];
            if(i != 0)
                cur_score *= (long long)(size - 1 - left_child_size[i] - right_child_size[i]);

            if(cur_score == max_size){
                res += 1;
            }
            if(cur_score > max_size){
                max_size = cur_score;
                res = 1;
            }
        }

        return res;
    }
};

int main(){
    vector<int> parents{-1, 2, 0, 2, 0};
    Solution sol;

    cout << sol.countHighestScoreNodes(parents) << endl;
    return 0;
}
*/

class Solution {
public:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    int dfs(int node) {
        long score = 1;
        int size = n - 1;
        for (int c : children[node]) {
            int t = dfs(c);
            score *= t;
            size -= t;
        }
        if (node != 0) {
            score *= size;
        }
        if (score == maxScore) {
            cnt++;
        } else if (score > maxScore) {
            maxScore = score;
            cnt = 1;
        }
        return n - size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            int p = parents[i];
            if (p != -1) {
                children[p].emplace_back(i);
            }
        }
        dfs(0);
        return cnt;
    }
};
