class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m, n;
        int i, j;
        m = grid.size();
        if(m <= 0)
            return res;
        n = grid[0].size();
        if(n <= 0)
            return res;

        vector<vector<int>> path_grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j< n - 1; ++j){
                // right side
                if(grid[i][j] == grid[i][j + 1] && grid[i][j] == 1){
                    path_grid[i][j] = 1;
                // left side
                }else{
                    if(j > 0 && grid[i][j] == grid[i][j - 1] && grid[i][j] == -1){
                        path_grid[i][j] = -1;
                    }else{
                        path_grid[i][j] = 0;
                    }
                }
            }
        }

        for(int t = 0; t < n; ++t)
        {
            i = 0;
            j = t;
            while(i < m && && j >= 0 && j < n && grid[i][j] != 0){
                if(grid[i][j] == 1){
                    j += 1;
                }else{
                    j -= 1;
                }
                i++;
            }

            if(i == m){
                res.push_back(j);
            }else{
                res.push_back(-1);
            }
        }
        return ans;
    }
};
