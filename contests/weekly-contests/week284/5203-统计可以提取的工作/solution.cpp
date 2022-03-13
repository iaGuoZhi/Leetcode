class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        int d_size = dig.size();
        int a_size = artifacts.size();
        int ans = 0;

        for(int i = 0; i < d_size; i++){
            grid[dig[i][0]][dig[i][1]] = true;
        }
        
        for(int i = 0; i < a_size; i++){
            bool uncovered = true;
            for(int r = artifacts[i][0]; r <= artifacts[i][2]; ++r){
                for(int c = artifacts[i][1]; c <= artifacts[i][3]; ++c){
                    if(grid[r][c] == false){
                        uncovered = false;
                    }
                }
            }
            if(uncovered)
                ans++;
        }

        return ans;
    }
};
