class Solution {
    private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis, int delrow[], int delcol[]){
        vis[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, grid, vis, delrow, delcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> vis(N, vector<int>(M, 0));
        int cnt = 0;
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i, j, grid, vis,delrow, delcol);
                }
            }
        }
        return cnt;
    }
};