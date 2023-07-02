class Solution {
private:
    bool f(int i, int j, string S1, string S2, vector<vector<int>> &dp){

        if(i == 0 && j == 0) return true;
        if(i == 0 && j >= 1) return false;
        if(j == 0 && i >= 1){
            for(int ind = 1; ind <= i; ind++){
                if(S1[ind - 1] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, S1, S2, dp);
        if(S1[i - 1] == '*') return dp[i][j] = f(i - 1, j, S1, S2, dp) || f(i, j - 1, S1, S2, dp);
        else
            return dp[i][j] = false;
    }
public:
    bool isMatch(string S2, string S1) {
        int N = S1.size();
        int M = S2.size();
        vector<vector<bool>> dp(N + 1, vector<bool> (M + 1, false));
        // return f(N, M, S1, S2, dp);
        dp[0][0] = true;
        for(int j = 1; j <= M; j++){
            dp[0][j] = false;
        }
        for(int i = 1; i <= N; i++){
            int flag = true;
            for(int ind = 1; ind <= i; ind++){
                if(S1[ind - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                   dp[i][j] = dp[i - 1][j - 1];
                else if(S1[i - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[N][M];
    }
};