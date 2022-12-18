class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> degree(n + 1);

        for (vector<int>& edge : edges) {
            degree[edge[0]].insert(edge[1]);
            degree[edge[1]].insert(edge[0]);
        }
        vector<int> odd;
        for (int i = 1; i <= n; ++i) {
            if ((degree[i].size() & 1)) {
                if (!(degree[i].size() < n)) return false;
                odd.push_back(i);
            }
        }
        if (odd.size() == 0) return true;
        else if (odd.size() == 2) {
            if (!degree[odd[0]].count(odd[1])) return true;
            for (int i = 1; i <= n; i++) {
                if (i == odd[0] || i == odd[1]) continue;
                if(!(degree[i].count(odd[0]) || degree[i].count(odd[1]))) return true;
            }
            return false;
        }
        else if (odd.size() == 4) {
            if (!degree[odd[0]].count(odd[1])) {
                if (!degree[odd[2]].count(odd[3])) return true;
            }
            if (!degree[odd[0]].count(odd[2])) {
                if (!degree[odd[1]].count(odd[3])) return true;
            }
            if (!degree[odd[0]].count(odd[3])) {
                if (!degree[odd[1]].count(odd[2])) return true;
            }
            return false;
        }
        return false;

    }
};
