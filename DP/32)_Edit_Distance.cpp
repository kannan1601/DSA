class Solution {
private:
    int f(int i, int j, string S1, string S2, vector<vector<int>> &dp){
        
        if(j == 0){
            return i;
        }

        if(i == 0){
            return j;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(S1[i - 1] == S2[j - 1]){
            return dp[i][j] = 0 + f(i - 1, j - 1, S1, S2, dp);
        }

        int ins = 1 + f(i, j - 1, S1, S2, dp);
        int del = 1 + f(i - 1, j, S1, S2, dp);
        int replace = 1 + f(i - 1, j - 1, S1, S2, dp);

        return dp[i][j] = min({ins, del, replace});
    }
public:
    int minDistance(string S1, string S2) {
        int N = S1.size();
        int M = S2.size();
        vector<int> prev(M + 1, 0);
        // return f(N, M, S1, S2, dp);

        for(int j = 0; j <= M; j++)
            prev[j] = j;

        for(int i = 1; i <= N; i++){
            vector<int> cur(M + 1, 0);
            cur[0] = i;
            for(int j = 1; j <= M; j++){
                if(S1[i - 1] == S2[j - 1]){
                    cur[j] = 0 + prev[j - 1];
                    continue;
                }

                int ins = 1 + cur[j - 1];
                int del = 1 + prev[j];
                int replace = 1 + prev[j - 1];

               cur[j] = min({ins, del, replace});
            }

            prev = cur;
        }

        return prev[M];
    }
};