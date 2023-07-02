class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int ans = 0;
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        
        //first row and last row
        for(int j = 0; j < M; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[N - 1][j] == 1){
                q.push({N - 1, j});
                vis[N - 1][j] = 1;
            }
        }
        vector<vector<int>> duplicate = grid;
        //first and last column
        for(int i = 0; i < N; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][M - 1] == 1){
                q.push({i, M - 1});
                vis[i][M - 1] = 1;
            }
        }
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int curnt_row = q.front().first;
            int curnt_col = q.front().second;
            duplicate[curnt_row][curnt_col] = -1;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nxt_row = curnt_row + delta_row[i];
                int nxt_col = curnt_col + delta_col[i];
                if(nxt_row >= 0 && nxt_row < N && nxt_col >= 0 && nxt_col < M && grid[nxt_row][nxt_col] == 1
                && !vis[nxt_row][nxt_col]){
                    vis[nxt_row][nxt_col] = 1;
                    q.push({nxt_row, nxt_col});
                    duplicate[curnt_row][curnt_col] = -1;
                }
            }
            
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1 && duplicate[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};