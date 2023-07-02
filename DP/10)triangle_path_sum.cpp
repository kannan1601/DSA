#include <bits/stdc++.h> 
// int f(int i, int j, vector<vector<int>> triangle, int n, vector<vector<int>> &dp){
//     if(i == n - 1)
//         return triangle[i][j];
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
//     int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);
//     return dp[i][j] = min(down, diagonal);
// }
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    // return f(0, 0, triangle, n, dp);
    vector<int> front_row(n);
    for(int j = 0; j < n; j++){
        front_row[j] = triangle[n - 1][j];
    }
    for(int i = n - 2; i >= 0; i--){
        vector<int> curnt(n);
        for(int j = 0; j <= i; j++){
            int down = triangle[i][j] + front_row[j];
            int diagonal = triangle[i][j] + front_row[j + 1];
            curnt[j] = min(down, diagonal);
        }
        front_row = curnt;
    }
    return front_row[0];
}