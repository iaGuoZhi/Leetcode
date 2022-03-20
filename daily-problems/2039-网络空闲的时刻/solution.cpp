#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int server_num = patience.size(), edge_size = edges.size();
        int layer = 0, server;
        int res = 0;
        vector<int> distance(server_num, 0);
        vector<vector<int>> linked_servers(server_num, vector<int>());
        queue<int> q;

        for(int i = 0; i < edge_size; ++i) {
            linked_servers[edges[i][0]].push_back(edges[i][1]);
            linked_servers[edges[i][1]].push_back(edges[i][0]);
        }
        
        q.push(0);
        while(q.size()){
            int q_size = q.size();
            layer += 1;
            for(int i = 0; i < q_size; ++i){
                server = q.front();
                q.pop();
                
                for(int j = 0; j < linked_servers[server].size(); ++j){
                    int next_server = linked_servers[server][j];
                    if(next_server != 0 && distance[next_server] == 0){
                        distance[next_server] = layer;
                        q.push(next_server);
                    }
                }
            }
        }

        for(int i = 1; i < server_num; ++i){
            int finish_time = 0;
            finish_time += 2 * distance[i];
            finish_time += ((2 * distance[i] - 1) / patience[i]) * patience[i];
            res = max(res, finish_time);
        }
            
        return res + 1;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 2},  {1, 2}};
    vector<int> patience = {0, 10, 10};
    Solution sol;

    cout << sol.networkBecomesIdle(edges, patience);
    return 0;
}
