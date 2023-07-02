class Solution {
    // int f(int i, int j, int N, int M, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    //     if(j < 0 || j >= M)
    //         return 1e9;
    //     if(i == 0)
    //         return matrix[0][j];
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int up = matrix[i][j] + f(i - 1, j, N, M, matrix, dp);
    //     int ld = matrix[i][j] + f(i - 1, j - 1, N, M, matrix, dp);
    //     int rd = matrix[i][j] + f(i - 1, j + 1, N, M, matrix, dp);
    //     return dp[i][j] = min(up, min(ld, rd));
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        int ans = INT_MAX;
        vector<int> prev(M);
        for(int j = 0; j < M; j++){
            prev[j] = matrix[0][j];
        }
        for(int i = 1; i < N; i++){
            vector<int> curnt(M);
            for(int j = 0; j < M; j++){
                int up, ld = 1e9, ud = 1e9;
                up = matrix[i][j] + prev[j];
                if(j - 1 >= 0) ld = matrix[i][j] + prev[j - 1];
                if(j + 1 < M) ud = matrix[i][j] + prev[j + 1];
                curnt[j] = min({up, ld, ud});
            }
            prev = curnt;
        }
        for(int i = 0; i < M; i++){
        ans = min(ans, prev[i]);
    }
    return ans;
    }
    
};