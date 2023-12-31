#include<bits/stdc++.h>
#define mod 1000000007
// int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
//     if(i == 0 && j == 0){
//         return 1;
//     }
//     if(i < 0 || j < 0){
//         return 0;
//     }  
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int up = 0, left = 0;
//     if(j > 0 && mat[i][j - 1] == 0)
//         left = f(i, j - 1, mat, dp);
//     if(i > 0 && mat[i - 1][j] == 0)
//         up = f(i - 1, j, mat, dp);
//     return dp[i][j] = ((left % mod + up % mod ) % mod);
// }
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(i == 0 && j == 0)dp[i][j] = 1;
            else if(mat[i][j] == -1)dp[i][j] = 0;
            else{
                int up = 0, left = 0;
                if(j > 0)
                    left = dp[i][j - 1];
                if(i > 0)
                    up = dp[i - 1][j];
                dp[i][j] = (left % mod + up % mod) % mod;
            }
                
        }
    }
    return dp[n - 1][m - 1];
}