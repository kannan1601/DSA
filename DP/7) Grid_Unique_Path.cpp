//Recusrion
int f(int i, int j, int n, int m){
    if(i == n || j == m)
        return 0;
    if(i == n - 1 || j == m - 1)
        return 1;
    int right = f(i, j + 1, n, m);
    int down = f(i + 1, j, n , m);
    return right + down;
}
int uniquePaths(int n, int m) {
	return f(0, 0, n, m);
}

TC -> Every cell has 2 options down and right so O(2^N x M)
SC -> O(no of paths)




// Memoization
 
int f(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i == n || j == m)
        return 0;
    if(i == n - 1 || j == m - 1)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    int right = f(i, j + 1, n, m, dp);
    int down = f(i + 1, j, n , m, dp);
    return dp[i][j] = right + down;
}
int uniquePaths(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	return f(0, 0, n, m, dp);
}

TC -> O(N x M)
SC -> O(no of paths) + O(N x M)

//Tabulation
// Bottom up approach
int uniquePaths(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(i == 0 && j == 0)
          continue;
        int up, left;
        up = left = 0;
        if(i > 0){
          up = dp[i - 1][j];
        }
        if(j > 0){
          left = dp[i][j - 1];
        }
        dp[i][j] = up + left;
      }
    }
    cout << dp[n - 1][m - 1];
}

TC -> O(N x M)
SC -> O(N x M)