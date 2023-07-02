class Solution {
public:
    string shortestCommonSupersequence(string S, string T) {
        string ans;
        int N = S.size();
        int M = T.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(S[i - 1] == T[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = N, j = M;
        while(i > 0 && j > 0){
            if(S[i - 1] == T[j - 1]){
                ans += S[i - 1];
                i--;
                j--;
            }
            else if(dp[i][j - 1] >= dp[i - 1][j]){
                ans += T[j - 1];
                j--;
            }
            else{
                ans += S[i - 1];
                i--;
            }
        }

        while(i > 0){
            ans += S[i - 1];
            i--;
        }
        while(j > 0){
            ans += T[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};