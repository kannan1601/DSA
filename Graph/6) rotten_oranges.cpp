class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> vis(N, vector<int>(M, 0));
        queue<pair<pair<int,int>, int>> q;
        
        int cntfresh = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1)
                    cntfresh++;
            }
        }
        int deltarow[] = {-1, 0, 1, 0};
        int deltacol[] = {0, 1, 0, - 1};
        int time = 0, cnt = 0;
        while(!q.empty()){
            int curntrow = q.front().first.first;
            int curntcol = q.front().first.second;
            time = max(time, q.front().second);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = curntrow + deltarow[i];
                int ncol = curntcol + deltacol[i];
                if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    cnt++;
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }
        if(cnt != cntfresh)
            return -1;
        return time;
    }
};