#include <bits/stdc++.h>
// int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(i == 0 && j == 0)
//         return grid[i][j];
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int up = INT_MAX, left = INT_MAX;
//     if(j > 0)
//       left = grid[i][j] + f(i, j - 1, grid, dp);
//     if(i > 0)
//         up = grid[i][j] + f(i - 1, j, grid, dp);
//     return dp[i][j] = min(left, up);
    
// }
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int N = grid.size();
    int M = grid[0].size();
//     vector<vector<int>> dp(N, vector<int>(M, -1));
    vector<int> prev(M, 0);
    for(int i = 0; i < N; i++){
        vector<int> curnt(M, 0);
        for(int j = 0; j < M; j++){
            if(i == 0 && j == 0)
                curnt[j] = grid[i][j];
            else{
                int up = INT_MAX, left = INT_MAX;
                if(i > 0)
                    up = grid[i][j] + prev[j];
                if(j > 0)
                    left = grid[i][j] + curnt[j - 1];
                curnt[j] = min(left, up);
            }
        }
        prev = curnt;
    }
//     return f(N - 1, M - 1, grid, dp);
    return prev[M - 1];
}